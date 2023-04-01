#ifndef _FUZZEXAMPLE_H_
#define _FUZZEXAMPLE_H_

#include "BBClientUtilities.h"
#include "../Example1_Driver_Lockbox/Example1_Driver_Lockbox.h"

EFI_STATUS
EFIAPI
FuzzExample1(
    IN INPUT_BUFFER *Input,
    IN EFI_HANDLE ParentImageHandle
);


EFI_STATUS
EFIAPI
Fuzz_Lockbox_SetLockPin(
    IN EFI_HANDLE  Controller,
    IN UINTN Value
);

EFI_STATUS
EFIAPI
Fuzz_Lockbox_WriteData_Wrapper(
    IN EFI_HANDLE  Controller,
    IN UINTN offset, 
    IN VOID *src, 
    IN UINTN length
);

EFI_STATUS
EFIAPI
Fuzz_Lockbox_ReadData(
    IN EFI_HANDLE Controller,
    IN OUT VOID **dest, 
    IN UINTN offset, 
    IN UINTN length
);

EFI_STATUS
EFIAPI
Fuzz_Lockbox_WriteData(
    IN EFI_HANDLE Controller,
    IN VOID *dest, 
    IN VOID *src, 
    IN UINTN length
);


#endif