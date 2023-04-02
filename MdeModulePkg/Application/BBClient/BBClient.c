
/** @file
  This sample application bases on BreakingBoot PCD setting
  to run the Breaking Boot fuzzer to the UEFI Console.

  Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "BBClientFuzz.h"

INPUT_BUFFER  Input;

// Function that checks parameters and fuzzes the implemented services
EFI_STATUS
EFIAPI
VerifyParameters (
  IN UINTN Argc,
  IN CHAR16 **Argv,
  IN EFI_HANDLE ImageHandle
)
{
  EFI_STATUS Status;
  if(Argc > 1)
  {
    Input.Buffer = Argv[1];
    Input.Length = Strlen(Argv[1]);
    CHAR16 Driver_Choice = 0;
    ReadInput(&Input, 1, &Driver_Choice);
    UINTN option = StrDecimalToUintn((CHAR16 *)&Driver_Choice);
    switch(option)
    {
      case PROCESS_FIRMWARE_VOLUME:
        DEBUG ((DEBUG_ERROR, "FUZZING: ProcessFirmwareVolume\n"));
        Status = FuzzProcessFirmwareVolume(&Input);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
        }
        break;
      case CLOSE_EVENT:
        DEBUG ((DEBUG_ERROR, "FUZZING: CloseEvent\n"));
        Status = FuzzCloseEvent(&Input);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
        }
        break;
      case LOAD_IMAGE:
        DEBUG ((DEBUG_ERROR, "FUZZING: LoadImage\n"));
        Status = FuzzLoadImage(&Input, ImageHandle);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
        }
        break;
      case SMM_HARDEN:
        DEBUG ((DEBUG_ERROR, "FUZZING: SmmHarden\n"));
        Status = FuzzSmmHarden(&Input);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
        }
        break;
      case EXAMPLE:
        DEBUG ((DEBUG_ERROR, "FUZZING: Example1\n"));
        Status = FuzzExample1(&Input, ImageHandle);
        if(EFI_ERROR(Status))
        {
          DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
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

  if(Status == EFI_ABORTED)
  {
    //CpuDeadLoop();
    DEBUG ((DEBUG_ERROR, "FAILED: Status Error - %r\n", Status));
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
