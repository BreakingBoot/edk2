#include "FuzzTrust.h"

EFI_STATUS
EFIAPI
FuzzTrust(
    IN INPUT_BUFFER *Input
)
{
    LIST_ENTRY             *Link;
    EFI_CORE_DRIVER_ENTRY  *DriverEntry;
    EFI_STATUS Status = EFI_SUCCESS;
    UINTN count = 0;
    for (Link = mDiscoveredList.ForwardLink; Link != &mDiscoveredList; Link = Link->ForwardLink) {
        DriverEntry = CR (Link, EFI_CORE_DRIVER_ENTRY, Link, EFI_CORE_DRIVER_ENTRY_SIGNATURE);
        if(count == 7)
        {
            Status = gDS->Trust(DriverEntry->FvHandle, &DriverEntry->FileName);
            break;
        }
        count++;
    }

    return Status;
}