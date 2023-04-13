#include "FuzzSmmHarden.h"

#define SERVICE_GUID 0
#define VARIABLE_GUID 1
#define SYS 0
#define USR 1
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

    UINTN var_type;
    UINTN DataSize;
    UINTN NameSize;
    ReadInput(Input, 1, &var_type);
    var_type = StrDecimalToUintn((CHAR16 *)&var_type);
    ReadInput(Input, 2, &DataSize);
    DataSize = StrDecimalToUintn((CHAR16 *)&DataSize);
    ReadInput(Input, 1, &NameSize);
    NameSize = StrDecimalToUintn((CHAR16 *)&NameSize);
    CHAR16 *Data = AllocatePool(DataSize);
    CHAR16 *Name = AllocatePool(NameSize);
    ReadInput(Input, DataSize, Data);
    ReadInput(Input, NameSize, Name);
    DEBUG ((DEBUG_ERROR, "FUZZING: DataSize = %d\n", DataSize));
    DEBUG ((DEBUG_ERROR, "FUZZING: Data = %s\n", Data));
    DEBUG ((DEBUG_ERROR, "FUZZING: NameSize = %d\n", NameSize));
    DEBUG ((DEBUG_ERROR, "FUZZING: Name = %s\n", Name));
    var_type %= 3; 
    CHAR16 *VariableName;
    switch(var_type)
    {
        case SYS:
            DEBUG ((DEBUG_ERROR, "FUZZING: Variable Type = SYS\n"));
            VariableName = AllocatePool(NameSize + 4);
            VariableName = L"SYS-";
            CopyMem(VariableName + 4, 
                Name, 
                StrSize(Name) 
                ); 
            break;
        case USR:
            DEBUG ((DEBUG_ERROR, "FUZZING: Variable Type = USR\n"));
            VariableName = AllocatePool(NameSize + 4);
            VariableName = L"USR-";
            CopyMem(VariableName + 4, 
                Name, 
                StrSize(Name) 
                ); 
            break;
        default:
            DEBUG ((DEBUG_ERROR, "FUZZING: Variable Type = NONE\n"));
            VariableName = Name;
            break;
    }
    DEBUG ((DEBUG_ERROR, "FUZZING: VariableName = %s\n", VariableName));
    CHAR16 Buffer[StrSize(Data) + StrLen(VariableName)]; 

    gBS->CopyMem(Buffer, 
             VariableName, 
             StrSize(VariableName) 
             ); 
    gBS->CopyMem(Buffer + StrLen(VariableName) + 1, 
             Data, 
             StrSize(Data) 
             ); 
    DEBUG ((DEBUG_ERROR, "FUZZING: Buffer = %s\n", Buffer));
    CommunicateSMM(Guid, Buffer, DataSize);
    FreePool(Data);
    FreePool(Name);
    return Status;
}

VOID
CommunicateSMM(
  IN EFI_GUID  Guid,
  IN VOID     *Data,
  IN UINTN    DataSize
)
{
  EFI_STATUS Status;

  /* Locate the SmmCommunicationProtocol to interact with SMM */
  EFI_SMM_COMMUNICATION_PROTOCOL *SmmCommunication = NULL;
  Status = gBS->LocateProtocol(
    &gEfiSmmCommunicationProtocolGuid,
    NULL,
    (VOID **)&SmmCommunication
    );
  ASSERT_EFI_ERROR(Status);

  /* Interact with SMM */
  EFI_SMM_COMMUNICATE_HEADER *Buffer = AllocateRuntimeZeroPool(sizeof(*Buffer) + DataSize);
  Buffer->HeaderGuid = Guid;
  Buffer->MessageLength = DataSize;
  CopyMem(&Buffer->Data, Data, DataSize);

  SmmCommunication->Communicate(
    SmmCommunication,
    Buffer,
    NULL
  );

  FreePool(Buffer);
}