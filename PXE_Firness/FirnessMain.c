#include "FirnessHarnesses.h"
#include "tsffs-gcc-x86_64.h"

INPUT_BUFFER Input;

__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FirnessMain (
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
) {
    EFI_STATUS Status = EFI_SUCCESS;

    UINTN MaxInputSize = 0x1000;
    UINT8 *buffer = (UINT8 *)AllocatePages(EFI_SIZE_TO_PAGES(MaxInputSize));
    UINTN InputSize = MaxInputSize;

    HARNESS_START(buffer, &InputSize);

    Input.Buffer = buffer;
    Input.Length = InputSize;

    UINT8 DriverChoice = 0;
    ReadBytes(&Input, sizeof(DriverChoice), (VOID *)&DriverChoice);
    switch(DriverChoice%11)
    {
        case 0:
            Status = FuzzStop(&Input, SystemTable, ImageHandle);
            break;
        case 1:
            Status = FuzzMtftp(&Input, SystemTable, ImageHandle);
            break;
        case 2:
            Status = FuzzDhcp(&Input, SystemTable, ImageHandle);
            break;
        case 3:
            Status = FuzzDiscover(&Input, SystemTable, ImageHandle);
            break;
        case 4:
            Status = FuzzSetParameters(&Input, SystemTable, ImageHandle);
            break;
        case 5:
            Status = FuzzUdpWrite(&Input, SystemTable, ImageHandle);
            break;
        case 6:
            Status = FuzzUdpRead(&Input, SystemTable, ImageHandle);
            break;
        case 7:
            Status = FuzzSetIpFilter(&Input, SystemTable, ImageHandle);
            break;
        case 8:
            Status = FuzzStart(&Input, SystemTable, ImageHandle);
            break;
        case 9:
            Status = FuzzSetStationIp(&Input, SystemTable, ImageHandle);
            break;
        case 10:
            Status = FuzzSetPackets(&Input, SystemTable, ImageHandle);
            break;
    }

    HARNESS_STOP();

    return Status;
}
