#include "FuzzSmmHarden.h"

#define SERVICE_GUID 0
#define VARIABLE_GUID 1
EFI_SMM_COMMUNICATION_PROTOCOL *SmmCommunication;

EFI_STATUS
EFIAPI
FuzzSmmHarden(
    IN INPUT_BUFFER *Input)
{
    UINTN guid;
    ReadInput(Input, 1, &guid);
    guid %= 2;
    EFI_STATUS Status = gBS->LocateProtocol(
            &gEfiSmmCommunicationProtocolGuid,
            NULL,
            (VOID **)&SmmCommunication
            );
    EFI_GUID Guid;
    switch(guid)
    {
        case SERVICE_GUID:
            Guid = gEfiSmmHardenVariableManagerGuid;
            DEBUG ((DEBUG_ERROR, "FUZZING: SmmHardenVariableManagerGuid\n"));
            break;
        case VARIABLE_GUID:
            Guid = gEfiSmmHardenBootServiceGuid;
            DEBUG ((DEBUG_ERROR, "FUZZING: SmmHardenBootServiceGuid\n"));
            break;
    }
    CHAR16 Data;
    UINTN DataSize;
    ReadInput(Input, 1, &Data);
    ReadInput(Input, 1, &DataSize);
    DataSize = StrDecimalToUintn((CHAR16 *)&DataSize);
    EFI_SMM_COMMUNICATE_HEADER *Buffer = AllocateRuntimeZeroPool(sizeof(*Buffer) + DataSize);
    Buffer->HeaderGuid = Guid;
    Buffer->MessageLength = DataSize;
    CopyMem(&Buffer->Data, (VOID*)&Data, DataSize);

    SmmCommunication->Communicate(
        SmmCommunication,
        Buffer,
        NULL
    );

    FreePool(Buffer);
    return Status;
}
