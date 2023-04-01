#include "FuzzExample.h"

Example1_Driver_Lockbox_PROTOCOL *ProtocolInterface;
#define SETLOCKPIN 0
#define WRITEDATA_WRAPPER 1
#define WRITEDATA 2
#define READDATA 3
#define WRITE_LOCK 4
#define READ_LOCK 5

EFI_STATUS
EFIAPI
FuzzExample1(
    IN INPUT_BUFFER *Input,
    IN EFI_HANDLE ParentImageHandle
)
{
    gBS->LocateProtocol(&gExample1_Driver_LockboxProtocolGuid, NULL, (VOID *)&ProtocolInterface);
    EFI_STATUS Status;
    UINTN Function;
    ReadInput(Input, 1, &Function);
    Function %= 6;
    switch(Function)
    {
        case SETLOCKPIN:
            UINTN Value;
            ReadInput(Input, 8, &Value);
            Status = Fuzz_Lockbox_SetLockPin(NULL, Value);
            break;
        case WRITEDATA_WRAPPER:
            UINTN length;
            ReadInput(Input, 8, &length);
            UINTN src;
            ReadInput(Input, length, &src);
            UINTN offset;
            ReadInput(Input, 8, &offset);
            Status = Fuzz_Lockbox_WriteData_Wrapper(NULL, offset, (VOID *)&src, length);
            break;
        case WRITEDATA: 
            UINTN size;
            ReadInput(Input, 8, &size);
            UINTN src_write;
            ReadInput(Input, size, &src_write);
            UINTN dest_write;
            ReadInput(Input, 8, &dest_write);
            Status = Fuzz_Lockbox_WriteData(NULL, (VOID *)dest_write, &src_write, size);
            break;
        case READDATA:
            UINTN read_value;
            ReadInput(Input, 8, &read_value);
            UINTN Offset;
            ReadInput(Input, 8, &Offset);
            CHAR8 *storage=AllocatePool(read_value);
            VOID **buffer = (void**)&storage;
            SetMemN(storage, read_value-1, '\0');
            Status = Fuzz_Lockbox_ReadData(NULL, buffer, Offset, read_value);
            FreePool(storage);
            break;
        case WRITE_LOCK:
            UINTN write_value;
            ReadInput(Input, 8, &write_value);
            Fuzz_Lockbox_SetLockPin(NULL, write_value);
            UINTN size_r;
            ReadInput(Input, 8, &size_r);
            UINTN src_w;
            ReadInput(Input, size_r, &src_w);
            UINTN dest_w;
            ReadInput(Input, 8, &dest_w);
            Status = Fuzz_Lockbox_WriteData(NULL, (VOID *)dest_w, &src_w, size_r);
            break;
        case READ_LOCK:
            UINTN read_val;
            ReadInput(Input, 8, &read_val);
            Fuzz_Lockbox_SetLockPin(NULL, read_val);
            UINTN read;
            ReadInput(Input, 8, &read);
            UINTN off;
            ReadInput(Input, 8, &off);
            CHAR8 *stor=AllocatePool(read);
            VOID **buff = (void**)&stor;
            SetMemN(stor, read-1, '\0');
            Status = Fuzz_Lockbox_ReadData(NULL, buff, off, read);
            FreePool(stor);
            break;
    }
    return Status;
}

EFI_STATUS
EFIAPI
Fuzz_Lockbox_SetLockPin(
    IN EFI_HANDLE  Controller,
    IN UINTN Value
)
{
    EFI_STATUS retval = ProtocolInterface->Example1_Driver_Lockbox_SetLockPin(ProtocolInterface, Controller, Value);
    if (retval != EFI_SUCCESS)
    {
        //CpuDeadLoop();
        return EFI_ABORTED;
    }
    return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Fuzz_Lockbox_WriteData_Wrapper(
    IN EFI_HANDLE  Controller,
    IN UINTN offset, 
    IN VOID *src, 
    IN UINTN length
)
{
    EFI_STATUS retval = ProtocolInterface->Example1_Driver_Lockbox_WriteData_Wrapper(ProtocolInterface, Controller, offset, src, length);
    if (retval != EFI_SUCCESS)
    {
        //CpuDeadLoop();
        return EFI_ABORTED;
    }
    return EFI_SUCCESS;

}

EFI_STATUS
EFIAPI
Fuzz_Lockbox_ReadData(
    IN EFI_HANDLE Controller,
    IN OUT VOID **dest, 
    IN UINTN offset, 
    IN UINTN length
)
{
    EFI_STATUS retval = ProtocolInterface->Example1_Driver_Lockbox_ReadData(ProtocolInterface, Controller, dest, offset, length);
    if (retval != EFI_SUCCESS)
    {
        //CpuDeadLoop();
        return EFI_ABORTED;
    }
    return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Fuzz_Lockbox_WriteData(
    IN EFI_HANDLE Controller,
    IN VOID *dest, 
    IN VOID *src, 
    IN UINTN length
)
{
    EFI_STATUS retval = ProtocolInterface->Example1_Driver_Lockbox_WriteData(ProtocolInterface, Controller, dest, src, length);
    if (retval != EFI_SUCCESS)
    {
        //CpuDeadLoop();
        return EFI_ABORTED;
    }
    return EFI_SUCCESS;
}
