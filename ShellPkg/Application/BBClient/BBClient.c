
/** @file
  This sample application bases on BreakingBoot PCD setting
  to run the Breaking Boot fuzzer to the UEFI Console.

  Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include "../../MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.h"
//#include <Library/HobLib.h>
#include <Library/BaseLib.h>
#include <PiDxe.h>
#include <Protocol/LoadedImage.h>
#include "../../ShellPkg/Include/Protocol/EfiShellInterface.h"
#include <Protocol/FirmwareVolume2.h>
#include <Protocol/ShellParameters.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <PiDxe.h>
#include <Guid/DxeServices.h>
#include <Protocol/VariableWrite.h>
#include <Protocol/FaultTolerantWrite.h>
#include <Protocol/FirmwareVolumeBlock.h>
#include <Protocol/Variable.h>
#include <Protocol/VariableLock.h>
#include <Protocol/VarCheck.h>
#include <Library/HobLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiRuntimeLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/SynchronizationLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/AuthVariableLib.h>
#include <Library/VarCheckLib.h>
#include <Library/VariableFlashInfoLib.h>
#include <Library/SafeIntLib.h>
#include <Guid/GlobalVariable.h>
#include <Guid/EventGroup.h>
#include <Guid/VariableFormat.h>
#include <Guid/SystemNvDataGuid.h>
#include <Guid/FaultTolerantWrite.h>
#include <Guid/VarErrorFlag.h>

#define PROCESS_FIRMWARE_VOLUME 0
#define CLOSE_EVENT 1
#define LOAD_IMAGE 2

typedef struct {
  MEDIA_FW_VOL_FILEPATH_DEVICE_PATH    File;
  EFI_DEVICE_PATH_PROTOCOL             End;
} FV_FILEPATH_DEVICE_PATH;

FV_FILEPATH_DEVICE_PATH  mFvDevicePath;

// Help Menu to display correct format and available services to fuzz
EFI_STATUS
EFIAPI
HelpMenu ()
{
  Print(L"Usage: BBClient.efi <Function to Fuzz> [Parameters for function] \n \
          <Functions to Fuzz>: 0 - ProcessFirmwareVolume\n \
                               1 - CloseEvent\n \
                               2 - LoadImage\n \
                               ");
  return EFI_SUCCESS;
}

EFI_DEVICE_PATH_PROTOCOL *
CoreFvToDevicePath (
  IN  EFI_FIRMWARE_VOLUME2_PROTOCOL  *Fv,
  IN  EFI_HANDLE                     FvHandle,
  IN  EFI_GUID                       *DriverName
  )
{
  EFI_STATUS                Status;
  EFI_DEVICE_PATH_PROTOCOL  *FvDevicePath;
  EFI_DEVICE_PATH_PROTOCOL  *FileNameDevicePath;

  //
  // Remember the device path of the FV
  //
  Status = gBS->HandleProtocol (FvHandle, &gEfiDevicePathProtocolGuid, (VOID **)&FvDevicePath);
  if (EFI_ERROR (Status)) {
    FileNameDevicePath = NULL;
  } else {
    //
    // Build a device path to the file in the FV to pass into gBS->LoadImage
    //
    EfiInitializeFwVolDevicepathNode (&mFvDevicePath.File, DriverName);
    SetDevicePathEndNode (&mFvDevicePath.End);

    FileNameDevicePath = AppendDevicePath (
                           FvDevicePath,
                           (EFI_DEVICE_PATH_PROTOCOL *)&mFvDevicePath
                           );
  }

  return FileNameDevicePath;
}

EFI_STATUS
EFIAPI
FuzzLoadImage(
  IN BOOLEAN                   BootPolicy,
  IN EFI_HANDLE                ParentImageHandle,
  // IN EFI_DEVICE_PATH_PROTOCOL  *FilePath,
  IN VOID                      *SourceBuffer   OPTIONAL,
  IN UINTN                     SourceSize,
  IN UINTN                     DriverSize,
  OUT EFI_HANDLE               *ImageHandle
)
{
  // Create an empty DriverEntry
  //EFI_CORE_DRIVER_ENTRY *DriverEntry;
  // File GUID for SampleDriver
  EFI_GUID DriverName = {0xFE3542FE, 0xC1D3, 0x4EF8, {0x65, 0x7C, 0x80, 0x48, 0x60, 0x6F, 0xF6, 0x71}};
  EFI_STATUS Status;
  EFI_PEI_HOB_POINTERS HobFv;
  EFI_PEI_HOB_POINTERS DriverEntry;
  EFI_FIRMWARE_VOLUME2_PROTOCOL  *Fv;
  EFI_HANDLE                     FvHandle;
  UINTN                          BufferSize;

  // Link the empty DriverEntry to a Driver on in the HOB list
  // The drivers parameters will be modified to meet those
  // of the user input parameters
  /*
  DriverEntry = AllocateZeroPool (sizeof (EFI_CORE_DRIVER_ENTRY));
  ASSERT (DriverEntry != NULL);
  if (Type == EFI_FV_FILETYPE_FIRMWARE_VOLUME_IMAGE) {
    DriverEntry->IsFvImage = TRUE;
  }

  DriverEntry->Signature = EFI_CORE_DRIVER_ENTRY_SIGNATURE;
  CopyGuid (&DriverEntry->FileName, DriverName);
  DriverEntry->FvHandle         = FvHandle;
  DriverEntry->Fv               = Fv;
  DriverEntry->FvFileDevicePath = CoreFvToDevicePath (Fv, FvHandle, DriverName);
  */
  BufferSize = sizeof (EFI_FIRMWARE_VOLUME2_PROTOCOL);
  Print(L"Current BufferSize = %d\n", BufferSize);
  Status     = gBS->LocateHandle (
                  ByProtocol,
                  &gEfiFirmwareVolume2ProtocolGuid,
                  NULL,
                  &BufferSize,
                  &FvHandle
                  );
  if (EFI_ERROR (Status)) {
    //
    // If no more notification events exit
    //
    Print(L"Required BufferSize = %d\n", BufferSize);
    Print(L"Couldn't Locate Handle: %r\n", Status);
    return Status;
  }
  Status = gBS->HandleProtocol (FvHandle, &gEfiFirmwareVolume2ProtocolGuid, (VOID **)&Fv);
  
  HobFv.Raw = GetHobList();

  
  // Loop through all of the HOBs until the Sample Driver is found
  while((HobFv.Raw = GetNextHob(EFI_HOB_TYPE_FV, HobFv.Raw)) != NULL)
  {
    // Check if the Driver name and the FV name match
    if(CompareGuid(&DriverName, &HobFv.FirmwareVolume2->FileName)/* &&
        CompareGuid(FvNameGuid, &HobFv.FirmwareVolume2->FvName)*/)
    {
      // if you found the Driver you were looking for
      // save it to the DriverEntry and break the loop
      DriverEntry = HobFv;
      break;
    }
    HobFv.Raw = GET_NEXT_HOB(HobFv);
  } 
  
  // Modify the Sample Driver to match the user input parameters
  // Like Driver size
  DriverEntry.FirmwareVolume->Length = DriverSize;

  // Run the CoreLoadImage to load the modified Driver to fuzz
  // the service
  Status = gBS->LoadImage(BootPolicy,
                          ParentImageHandle,
                          CoreFvToDevicePath (Fv, FvHandle, &DriverName),
                          SourceBuffer,
                          SourceSize,
                          ImageHandle);


  Print(L"%r\n", Status);
  return Status;
}


/*
EFI_STATUS
EFIAPI
CreateDummyFv(

)
{
  EFI_STATUS Status;
  return Status;
}
*/

// Function that checks parameters and fuzzes the implemented services
EFI_STATUS
EFIAPI
VerifyParameters (
  IN UINTN Argc,
  IN CHAR16 **Argv,
  IN EFI_HANDLE ImageHandle
)
{
  //EFI_CORE_DRIVER_ENTRY *DriverEntry;
  EFI_HANDLE ReturnImageHandle;
  //EFI_STATUS Status;
  if(Argc > 2)
  {
    switch(StrDecimalToUintn(Argv[1]))
    {
      case PROCESS_FIRMWARE_VOLUME: //
        //Status = gDS->ProcessFirmwareVolume((VOID *) FwHeader, (MAX_UINT32), &FvProtocolHandle);
        break;
      case CLOSE_EVENT:
        //Status = gBS->CloseEvent();
        break;
      case LOAD_IMAGE:
        // Check that the correct input parameters were entered
        //   Argv[2] - BootPolicy (TRUE/FALSE)
        //   Argv[3] - Load from memory (TRUE/FALSE)
        //   Argv[4] - SourceSize (UINTN)
        //   Argv[5] - Driver Size (UINTN)
        if(Argc < 6)
        {
          Print(L"Need 5 Arguments for LoadImage\n");
          HelpMenu();
          return EFI_ABORTED;
        }
        BOOLEAN BootPolicy = (BOOLEAN) StrDecimalToUintn(Argv[2]);
        if(StrDecimalToUintn(Argv[3]))
        {
          Print(L"Entered IF\n");
          //VOID *SourceBuffer = ;
        }
        VOID *SourceBuffer = NULL;
        UINTN SourceSize = StrDecimalToUintn(Argv[4]);
        UINTN DriverSize = StrDecimalToUintn(Argv[5]);
        FuzzLoadImage(BootPolicy, ImageHandle, SourceBuffer, SourceSize, DriverSize, ReturnImageHandle);
        break;
      default:
        HelpMenu();
        break;
    }
  }
  return EFI_SUCCESS;
}

/**
  The user Entry Point for Application. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
BBClientMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
  EFI_SHELL_PARAMETERS_PROTOCOL *EfiShellParametersProtocol;
  EFI_SHELL_INTERFACE *EfiShellInterface;
  UINTN Argc;
  CHAR16 **Argv;

  EfiShellParametersProtocol = NULL;
  EfiShellInterface = NULL;

  Status = gBS->OpenProtocol(ImageHandle,
                            &gEfiShellParametersProtocolGuid,
                            (VOID **)&EfiShellParametersProtocol,
                            ImageHandle,
                            NULL,
                            EFI_OPEN_PROTOCOL_GET_PROTOCOL);
  
  if(!EFI_ERROR(Status))
  {
    Argc = EfiShellParametersProtocol->Argc;
    Argv = EfiShellParametersProtocol->Argv;

    VerifyParameters(Argc, Argv, ImageHandle);
  } 
  else 
  {
    Status = gBS->OpenProtocol(ImageHandle,
                               &gEfiShellInterfaceGuid,
                               (VOID **)&EfiShellInterface,
                               ImageHandle,
                               NULL,
                               EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    
    if(!EFI_ERROR(Status))
    {
      Argc = EfiShellInterface->Argc;
      Argv = EfiShellInterface->Argv;
      VerifyParameters(Argc, Argv, ImageHandle);
    }
    else
    {
      Print(L"\nGetting Shell parameters did not work\n");
    }
  }


  return EFI_SUCCESS;
}
