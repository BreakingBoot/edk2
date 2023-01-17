
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
/*
EFI_DEVICE_PATH_PROTOCOL *
DevicePathFromHandle (
   EFI_HANDLE                      Handle
  )
{
  EFI_DEVICE_PATH_PROTOCOL  *DevicePath;
  EFI_STATUS                Status;

  Status = gBS->HandleProtocol (
                  Handle,
                  &gEfiDevicePathProtocolGuid,
                  (VOID *) &DevicePath
                  );
  if (EFI_ERROR (Status)) {
    DevicePath = NULL;
  }
  return DevicePath;
}
*/

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

EFI_STATUS
EFIAPI
FuzzCloseEvent(
  IN UINTN UserType,
  IN UINTN UserTpl
)
{
  EFI_STATUS Status;
  EFI_EVENT DummyEvent;
  UINT32 Type;
  EFI_TPL NotifyTpl; 
  EFI_EVENT_NOTIFY NotifyFunction; // Optional
  VOID *NotifyContext; // Optional

  //
  // Set the values for the DummyEvent to create
  //
  // Random Notify Type
  switch(UserType%8)
  {
    case 0:
      Type = EVT_TIMER | EVT_NOTIFY_SIGNAL;
      break;
    case 1:
      Type = EVT_TIMER;
      break;
    case 2:
      Type = EVT_NOTIFY_WAIT;
      break;
    case 3:
      Type = EVT_NOTIFY_SIGNAL;
      break;
    case 4:
      Type = EVT_SIGNAL_EXIT_BOOT_SERVICES;
      break;
    case 5:
      Type = EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE;
      break;
    case 6:
      Type = 0x00000000;
      break;
    case 7:
      Type = EVT_TIMER | EVT_NOTIFY_WAIT;
      break;
  }
  // Needs to be of type TPL_APPLICATION, TPL_CALLBACK, and TPL_NOTIFY
  NotifyTpl = (EFI_TPL) UserTpl;
  // Set as NULL but can be set to a custom value
  NotifyFunction = EfiEventEmptyFunction; 
  NotifyContext = NULL;


  Status = gBS->CreateEvent(Type, NotifyTpl, NotifyFunction, NotifyContext, &DummyEvent);
  if(EFI_ERROR(Status))
  {
    DEBUG ((DEBUG_ERROR, "FAILED Creating DummyEvent of Type: %x with a Status: %r\n", Type, Status));
  }
  Status = gBS->CloseEvent(DummyEvent);

  return Status;
}


STATIC
UINT16
FvBufCalculateSum16 (
  IN UINT16       *Buffer,
  IN UINTN        Size
  )
{
  UINTN   Index;
  UINT16  Sum;

  Sum = 0;

  //
  // Perform the word sum for buffer
  //
  for (Index = 0; Index < Size; Index++) {
    Sum = (UINT16) (Sum + Buffer[Index]);
  }

  return (UINT16) Sum;
}


STATIC
UINT16
FvBufCalculateChecksum16 (
  IN UINT16       *Buffer,
  IN UINTN        Size
  )
{
  return (UINT16)(0x10000 - FvBufCalculateSum16 (Buffer, Size));
}


EFI_STATUS
EFIAPI
FuzzProcessFirmwareVolume(
  IN UINT64 InputLength,
  IN EFI_FVB_ATTRIBUTES_2 InputAttributes,
  IN UINT32 NumBlocks,
  IN UINT32 BlockLength,
  IN EFI_GUID Guid
)
{
  EFI_STATUS Status;
  EFI_HANDLE FvProtocolHandle;
  EFI_FIRMWARE_VOLUME_HEADER FwHeader;

  // FW Header Info
  // COMPLETED
  EFI_FV_BLOCK_MAP_ENTRY BlockMap;
  BlockMap.Length = BlockLength;
  BlockMap.NumBlocks = NumBlocks;
  EFI_FV_BLOCK_MAP_ENTRY EmptyBlock;
  EmptyBlock.Length = 0;
  EmptyBlock.NumBlocks = 0;
  UINT64 FvLength = InputLength;
  UINT32 Signature = EFI_FVH_SIGNATURE;
  EFI_FVB_ATTRIBUTES_2 Attributes = InputAttributes;
  UINT8 Reserved = 0;
  UINT8 Revision = EFI_FVH_REVISION;
  UINT16 HeaderLength = (UINT16) (((UINTN) &(BlockMap)) - (UINTN) InputLength);
  UINT16 Checksum = FvBufCalculateChecksum16((UINT16*) &FwHeader, HeaderLength / sizeof (UINT16));
  EFI_GUID FileSystemGuid = Guid;

  // INCOMPLETED
  UINT16 ExtHeaderOffset = 0; // May need to change
  

  gBS->SetMem(&(FwHeader.ZeroVector), 16, 0);
  FwHeader.FileSystemGuid = FileSystemGuid;
  FwHeader.FvLength = FvLength;
  FwHeader.Signature = Signature;
  FwHeader.Attributes = Attributes;
  FwHeader.HeaderLength = HeaderLength;
  FwHeader.Checksum = Checksum;
  FwHeader.ExtHeaderOffset = ExtHeaderOffset;
  FwHeader.Reserved[0] = Reserved;
  FwHeader.Revision = Revision;
  FwHeader.BlockMap[0] = BlockMap;
  FwHeader.BlockMap[1] = BlockMap;
  FwHeader.BlockMap[2] = EmptyBlock;

  DEBUG ((DEBUG_ERROR, "FUZZING: ZeroVector - %d\n", FwHeader.ZeroVector[0]));
  DEBUG ((DEBUG_ERROR, "FUZZING: FileSystemGuid - %x\n", FwHeader.FileSystemGuid));
  DEBUG ((DEBUG_ERROR, "FUZZING: FvLength - %d\n", FwHeader.FvLength));
  DEBUG ((DEBUG_ERROR, "FUZZING: Signature - %d\n", FwHeader.Signature));
  DEBUG ((DEBUG_ERROR, "FUZZING: Attributes - %d\n", FwHeader.Attributes));
  DEBUG ((DEBUG_ERROR, "FUZZING: HeaderLength - %d\n", FwHeader.HeaderLength));
  DEBUG ((DEBUG_ERROR, "FUZZING: Checksum - %d\n", FwHeader.Checksum));
  DEBUG ((DEBUG_ERROR, "FUZZING: ExtHeaderOffset - %d\n", FwHeader.ExtHeaderOffset));
  DEBUG ((DEBUG_ERROR, "FUZZING: Reserved - %d\n", FwHeader.Reserved[0]));
  DEBUG ((DEBUG_ERROR, "FUZZING: Revision - %d\n", FwHeader.Revision));
  DEBUG ((DEBUG_ERROR, "FUZZING: BlockMap(NumBlocks) - %d\n", FwHeader.BlockMap[1].NumBlocks));
  DEBUG ((DEBUG_ERROR, "FUZZING: BlockMap(Length) - %d\n", FwHeader.BlockMap[1].Length));
  DEBUG((DEBUG_INFO, "Size - %d\n", sizeof(FwHeader.BlockMap)));

  Status = gDS->ProcessFirmwareVolume((VOID *) &FwHeader, FwHeader.FvLength, &FvProtocolHandle);

  return Status;
}


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
  EFI_STATUS Status;
  EFI_PEI_HOB_POINTERS FvHob;
  EFI_FIRMWARE_VOLUME_HEADER *FwHeader;
  EFI_HANDLE FvProtocolHandle;
  if(Argc > 1)
  {
    switch(StrDecimalToUintn(Argv[1]))
    {
      case PROCESS_FIRMWARE_VOLUME: // INCOMPLETE
        if(Argc != 6)
        {
          Print(L"Need 5 Arguments for ProcessFirmwareImage\n");
          Print(L"BBClient.efi 0 <InputLength> <InputAttributes> <NumBlocks> <BlockLength>\n");
          Print(L"    <InputLength>     : Firmware Volume Image Length\n");
          Print(L"    <InputAttributes> : Specific FV attributes\n");
          Print(L"    <NumBlocks>       : Number of Blocks for FV BlockMap\n");
          Print(L"    <BlockLength>     : Length of each Block in the BlockMap\n");
          break;
        }
        UINT64 InputLength = StrDecimalToUint64(Argv[2]);
        EFI_FVB_ATTRIBUTES_2 InputAttributes = (EFI_FVB_ATTRIBUTES_2) StrDecimalToUint64(Argv[3]);
        UINT32 NumBlocks = (UINT32) StrDecimalToUint64(Argv[4]);
        UINT32 BlockLength = (UINT32) StrDecimalToUint64(Argv[5]);

        FvHob.Raw = GetHobList();
        FvHob.Raw = GetNextHob(EFI_HOB_TYPE_FV, FvHob.Raw);
        FwHeader = (EFI_FIRMWARE_VOLUME_HEADER *) (UINTN) ((EFI_PHYSICAL_ADDRESS)(UINTN)FvHob.FirmwareVolume->BaseAddress);    
        DEBUG ((DEBUG_ERROR, "NORMAL: ZeroVector - %d\n", FwHeader->ZeroVector[0]));
        DEBUG ((DEBUG_ERROR, "NORMAL: FileSystemGuid - %x\n", FwHeader->FileSystemGuid));
        DEBUG ((DEBUG_ERROR, "NORMAL: FvLength - %d\n", FwHeader->FvLength));
        DEBUG ((DEBUG_ERROR, "NORMAL: Signature - %d\n", FwHeader->Signature));
        DEBUG ((DEBUG_ERROR, "NORMAL: Attributes - %d\n", FwHeader->Attributes));
        DEBUG ((DEBUG_ERROR, "NORMAL: HeaderLength - %d\n", FwHeader->HeaderLength));
        DEBUG ((DEBUG_ERROR, "NORMAL: Checksum - %d\n", FwHeader->Checksum));
        DEBUG ((DEBUG_ERROR, "NORMAL: ExtHeaderOffset - %d\n", FwHeader->ExtHeaderOffset));
        DEBUG ((DEBUG_ERROR, "NORMAL: Reserved - %d\n", FwHeader->Reserved[0]));
        DEBUG ((DEBUG_ERROR, "NORMAL: Revision - %d\n", FwHeader->Revision));
        DEBUG ((DEBUG_ERROR, "NORMAL: BlockMap(NumBlocks) - %d\n", FwHeader->BlockMap[1].NumBlocks));
        DEBUG ((DEBUG_ERROR, "NORMAL: BlockMap(Length) - %d\n", FwHeader->BlockMap[1].Length));
        DEBUG((DEBUG_INFO, "Size - %d\n", sizeof(FwHeader->BlockMap)));
        gDS->ProcessFirmwareVolume((VOID *) FwHeader, FwHeader->FvLength, &FvProtocolHandle);
        Status = FuzzProcessFirmwareVolume(InputLength, InputAttributes, NumBlocks, BlockLength, FwHeader->FileSystemGuid);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FUZZING: Status Error - %r\n", Status));
        }
        break;
      case CLOSE_EVENT: // COMPLETED
        if(Argc != 4)
        {
          Print(L"Need 2 Arguments for CloseEvent\n");
          Print(L"BBClient.efi 1 <EventType> <NotifyTPL>\n");
          Print(L"    <EventType> : The type of event to be created\n");
          Print(L"    <NotifyTPL> : The task priority level of the event\n");
          break;
        }
        UINTN Type = StrDecimalToUintn(Argv[2]);
        UINTN NotifyTpl = StrDecimalToUintn(Argv[3]);
        DEBUG ((DEBUG_ERROR, "FUZZING: CoreCloseEvent(%d, %d)\n", Type, NotifyTpl));
        Status = FuzzCloseEvent(Type, NotifyTpl);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FUZZING: Status Error - %r\n", Status));
        }
        break;
      case LOAD_IMAGE: // INCOMPLETE
        // Check that the correct input parameters were entered
        //   Argv[2] - BootPolicy (TRUE/FALSE)
        //   Argv[3] - Load from memory (TRUE/FALSE)
        //   Argv[4] - SourceSize (UINTN)
        //   Argv[5] - Driver Size (UINTN)
        if(Argc < 6)
        {
          Print(L"Need 5 Arguments for LoadImage\n");
          break;
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
        Status = FuzzLoadImage(BootPolicy, ImageHandle, SourceBuffer, SourceSize, DriverSize, ReturnImageHandle);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FUZZING: Status Error - %r\n", Status));
        }
        break;
      default:
        HelpMenu();
        break;
    }
  }
  else
  {
    HelpMenu();
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
