#include "FuzzMemory.h"

EFI_STATUS
EFIAPI
FuzzMemory(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status = EFI_SUCCESS;
    UINTN MemoryService;
    ReadInput(Input, 2, &MemoryService);
    switch(MemoryService%15)
    {
        case ADD_MEMORY_SPACE:
            Status = FuzzAddMemorySpace(Input);
            break;
        case ALLOCATE_MEMORY_SPACE:
            Status = FuzzAllocateMemorySpace(Input);
            break;
        case FREE_MEMORY_SPACE:
            Status = FuzzFreeMemorySpace(Input);
            break;
        case REMOVE_MEMORY_SPACE:
            Status = FuzzRemoveMemorySpace(Input);
            break;
        case GET_MEMORY_SPACE_DESCRIPTOR:
            Status = FuzzGetMemorySpaceDescriptor(Input);
            break;
        case SET_MEMORY_SPACE_ATTRIBUTES:
            Status = FuzzSetMemorySpaceAttributes(Input);
            break;
        case GET_MEMORY_SPACE_MAP:
            Status = FuzzGetMemorySpaceMap(Input);
            break;
        case SET_MEMORY_SPACE_CAPABILITIES:
            Status = FuzzSetMemorySpaceCapabilities(Input);
            break;
        case ALLOCATE_PAGES:
            Status = FuzzAllocatePages(Input);
            break;
        case FREE_PAGES:
            Status = FuzzFreePages(Input);
            break;
        case GET_MEMORY_MAP:
            Status = FuzzGetMemoryMap(Input);
            break;
        case ALLOCATE_POOL:
            Status = FuzzAllocatePool(Input);
            break;
        case FREE_POOL:
            Status = FuzzFreePool(Input);
            break;
        case COPY_MEM:
            Status = FuzzCopyMem(Input);
            break;
        case SET_MEM:
            Status = FuzzSetMem(Input);
            break;
    }
    return Status;
}

EFI_STATUS
EFIAPI
FuzzAddMemorySpace(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status = EFI_SUCCESS;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzAllocateMemorySpace(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzFreeMemorySpace(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzRemoveMemorySpace(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzGetMemorySpaceDescriptor(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzSetMemorySpaceAttributes(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzGetMemorySpaceMap(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzSetMemorySpaceCapabilities(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzAllocatePages(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzFreePages(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzGetMemoryMap(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzAllocatePool(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzFreePool(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzCopyMem(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}

EFI_STATUS
EFIAPI
FuzzSetMem(
    IN INPUT_BUFFER *Input
)
{
    EFI_STATUS Status;
    return Status;
}