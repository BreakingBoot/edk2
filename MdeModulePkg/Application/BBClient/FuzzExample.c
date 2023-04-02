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
        UINTN tmp;
        case SETLOCKPIN:
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered SETLOCKPIN\n"));
            ReadInput(Input, 8, &tmp);
            UINTN out = StrDecimalToUintn((CHAR16 *)&tmp);
            Status = Fuzz_Lockbox_SetLockPin(NULL, out);
            break;
        case WRITEDATA_WRAPPER:
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered WRITEDATAWRAPPER\n"));
            UINTN length;
            UINTN offset;
            UINTN src;
            ReadInput(Input, 8, &tmp);
            length = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, length, &tmp);
            src = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, 8, &tmp);
            offset = StrDecimalToUintn((CHAR16 *)&tmp);
            Status = Fuzz_Lockbox_WriteData_Wrapper(NULL, offset, (VOID *)&src, length);
            break;
        case WRITEDATA: 
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered WRITEDATA\n"));
            UINTN size;
            UINTN src_write;
            UINTN dest_write;
            ReadInput(Input, 8, &tmp);
            size = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, size, &src_write);
            src_write = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, 8, &dest_write);
            dest_write = StrDecimalToUintn((CHAR16 *)&tmp);
            Status = Fuzz_Lockbox_WriteData(NULL, (VOID *)dest_write, &src_write, size);
            break;
        case READDATA:
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered READDATA\n"));
            UINTN read_value;
            UINTN Offset;
            ReadInput(Input, 8, &tmp);
            read_value = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, 8, &tmp);
            Offset = StrDecimalToUintn((CHAR16 *)&tmp);
            CHAR8 *storage=AllocatePool(read_value);
            VOID **buffer = (void**)&storage;
            SetMemN(storage, read_value, '\0');
            Status = Fuzz_Lockbox_ReadData(NULL, buffer, Offset, read_value);
            FreePool(storage);
            break;
        case WRITE_LOCK:
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered WRITELOCK\n"));
            UINTN write_value;
            UINTN size_r;
            UINTN src_w;
            UINTN dest_w;
            ReadInput(Input, 8, &tmp);
            write_value = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            Fuzz_Lockbox_SetLockPin(NULL, write_value);
            
            ReadInput(Input, 8, &tmp);
            size_r = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, size_r, &tmp);
            src_w = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp =0;
            ReadInput(Input, 8, &tmp);
            dest_w = StrDecimalToUintn((CHAR16 *)&tmp);
            Status = Fuzz_Lockbox_WriteData(NULL, (VOID *)dest_w, &src_w, size_r);
            break;
        case READ_LOCK:
            DEBUG ((DEBUG_ERROR, "EXAMPLE1: Entered READLOCK\n"));
            UINTN read_val;
            UINTN off;
            UINTN read;
            ReadInput(Input, 8, &tmp);
            read_val = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            Fuzz_Lockbox_SetLockPin(NULL, read_val);
            
            ReadInput(Input, 8, &tmp);
            read = StrDecimalToUintn((CHAR16 *)&tmp);
            tmp = 0;
            ReadInput(Input, 8, &tmp);
            off = StrDecimalToUintn((CHAR16 *)&tmp);
            CHAR8 *stor=AllocatePool(read);
            VOID **buff = (void**)&stor;
            SetMemN(stor, read, '\0');
            Status = Fuzz_Lockbox_ReadData(NULL, buff, off, read);
            FreePool(stor);
            Status = EFI_ABORTED;
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
