/** @file
  This is a Dummy Driver for creating an Image and a FV

**/
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiDriverEntryPoint.h>



/**
  The user Entry Point for DXE Driver. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
// This is a simple driver that is used to create a DXE Image and FW Image
EFI_STATUS
EFIAPI
DummyDriverEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  Print(L"Dummy Driver Entry Function");
  return EFI_SUCCESS;
}
