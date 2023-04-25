#ifndef _FUZZPROTOCOL_H_
#define _FUZZPROTOCOL_H_

#include "BBClientUtilities.h"
#include "Protocol/AtaAtapiPolicy.h"
#include "Protocol/BootLogo.h"
#include "Protocol/BootLogo2.h"
#include "Protocol/DebuggerConfiguration.h"
#include "Protocol/DeviceSecurity.h"
#include "Protocol/DisplayProtocol.h"
#include "Protocol/EbcSimpleDebugger.h"
#include "Protocol/EbcVmTest.h"
#include "Protocol/EsrtManagement.h"
#include "Protocol/FaultTolerantWrite.h"
#include "Protocol/FileExplorer.h"
#include "Protocol/FirmwareManagementProgress.h"
#include "Protocol/FormBrowserEx.h"
#include "Protocol/FormBrowserEx2.h"
#include "Protocol/GenericMemoryTest.h"
#include "Protocol/IoMmu.h"
#include "Protocol/IpmiProtocol.h"
#include "Protocol/LoadPe32Image.h"
#include "Protocol/LockBox.h"
#include "Protocol/NonDiscoverableDevice.h"
#include "Protocol/PeCoffImageEmulator.h"
#include "Protocol/PlatformBootManager.h"
#include "Protocol/PlatformLogo.h"
#include "Protocol/PlatformSpecificResetFilter.h"
#include "Protocol/PlatformSpecificResetHandler.h"
#include "Protocol/Print2.h"
#include "Protocol/Ps2Policy.h"
#include "Protocol/SdMmcOverride.h"
#include "Protocol/SmmExitBootServices.h"
#include "Protocol/SmmFirmwareVolumeBlock.h"
#include "Protocol/SmmLegacyBoot.h"
#include "Protocol/SmmMemoryAttribute.h"
#include "Protocol/SmmReadyToBoot.h"
#include "Protocol/SmmSwapAddressRange.h"
#include "Protocol/SmmVarCheck.h"
#include "Protocol/SmmVariable.h"
#include "Protocol/SwapAddressRange.h"
#include "Protocol/UfsHostController.h"
#include "Protocol/UfsHostControllerPlatform.h"
#include "Protocol/VarCheck.h"
#include "Protocol/VariableLock.h"
#include "Protocol/VariablePolicy.h"


#define LOCATE_PROTOCOL 0
#define OPEN_PROTOCOL 1
#define CLOSE_PROTOCOL 2
#define HANDLE_PROTOCOL 3
#define OPEN_PROTOCOL_INFORMATION 4
#define PROTOCOLS_PER_HANDLE 5
#define LOCATE_HANDLE_BUFFER 6
#define INSTALL_PROTOCOL_INTERFACE 7
#define REINSTALL_PROTOCOL_INTERFACE 8
#define UNINSTALL_PROTOCOL_INTERFACE 9
#define INSTALL_MULTIPLE_PROTOCOL_INTERFACES 10
#define UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES 11

//#define Dummy_PROTOCOL_GUID {0xc45d71be, 0x84f9, 0x446a, {0xae, 0xe8, 0x50, 0x49, 0xf5, 0xb4, 0xbf, 0x96}}

//typedef struct _Dummy_PROTOCOL Dummy_PROTOCOL;

static EFI_GUID* ProtocolGuidList[] = {&gEdkiiAtaAtapiPolicyProtocolGuid, &gEfiBootLogoProtocolGuid, &gEdkiiBootLogo2ProtocolGuid, 
                            &gEfiDebuggerConfigurationProtocolGuid, &gEdkiiDeviceSecurityProtocolGuid, 
                            &gEdkiiFormDisplayEngineProtocolGuid, &gEfiEbcSimpleDebuggerProtocolGuid, 
                            &gEfiEbcVmTestProtocolGuid, &gEsrtManagementProtocolGuid, &gEfiFaultTolerantWriteProtocolGuid, 
                            &gEfiFileExplorerProtocolGuid, &gEdkiiFirmwareManagementProgressProtocolGuid, &gEdkiiFormBrowserExProtocolGuid, 
                            &gEdkiiFormBrowserEx2ProtocolGuid, &gEfiGenericMemTestProtocolGuid, &gEdkiiIoMmuProtocolGuid, 
                            &gIpmiProtocolGuid, &gSmmIpmiProtocolGuid, &gEfiLoadPeImageProtocolGuid, 
                            &gEfiLockBoxProtocolGuid, &gEdkiiNonDiscoverableDeviceProtocolGuid, &gEdkiiPeCoffImageEmulatorProtocolGuid, 
                            &gEdkiiPlatformBootManagerProtocolGuid, &gEdkiiPlatformLogoProtocolGuid, &gEdkiiPlatformSpecificResetFilterProtocolGuid, 
                            &gEdkiiPlatformSpecificResetHandlerProtocolGuid, &gEfiPrint2SProtocolGuid, &gEfiPs2PolicyProtocolGuid, 
                            &gEdkiiSdMmcOverrideProtocolGuid, &gEdkiiSmmExitBootServicesProtocolGuid, &gEfiSmmFaultTolerantWriteProtocolGuid, 
                            &gEfiSmmFirmwareVolumeBlockProtocolGuid, &gEdkiiSmmLegacyBootProtocolGuid, &gEdkiiSmmMemoryAttributeProtocolGuid, 
                            &gEdkiiSmmReadyToBootProtocolGuid, &gEfiSmmSwapAddressRangeProtocolGuid, &gEdkiiSmmVarCheckProtocolGuid, 
                            &gEfiSmmVariableProtocolGuid, &gEfiSwapAddressRangeProtocolGuid, &gEdkiiUfsHostControllerProtocolGuid, 
                            &gEdkiiUfsHcPlatformProtocolGuid, &gEdkiiVarCheckProtocolGuid, &gEdkiiVariableLockProtocolGuid, 
                            &gEdkiiVariablePolicyProtocolGuid};


VOID *ProtocolList[] = {&EDKII_ATA_ATAPI_POLICY_PROTOCOL, &EFI_BOOT_LOGO_PROTOCOL, &EDKII_BOOT_LOGO2_PROTOCOL, 
                            &EFI_DEBUGGER_CONFIGURATION_PROTOCOL, &EDKII_DEVICE_SECURITY_PROTOCOL, 
                            &EDKII_FORM_DISPLAY_ENGINE_PROTOCOL, &EFI_EBC_SIMPLE_DEBUGGER_PROTOCOL,
                            &EFI_EBC_VM_TEST_PROTOCOL, &ESRT_MANAGEMENT_PROTOCOL, &EFI_FAULT_TOLERANT_WRITE_PROTOCOL, 
                            &EFI_FILE_EXPLORER_PROTOCOL, &EDKII_FIRMWARE_MANAGEMENT_PROGRESS_PROTOCOL, &EDKII_FORM_BROWSER_EXTENSION_PROTOCOL,  
                            &EDKII_FORM_BROWSER_EXTENSION2_PROTOCOL, &EFI_GENERIC_MEMORY_TEST_PROTOCOL, &EDKII_IOMMU_PROTOCOL, 
                            &IPMI_PROTOCOL, &IPMI_PROTOCOL, &EFI_PE32_IMAGE_PROTOCOL, 
                            NULL, &NON_DISCOVERABLE_DEVICE, &EDKII_PECOFF_IMAGE_EMULATOR_PROTOCOL, 
                            &EDKII_PLATFORM_BOOT_MANAGER_PROTOCOL, &EDKII_PLATFORM_LOGO_PROTOCOL, &EDKII_PLATFORM_SPECIFIC_RESET_FILTER_PROTOCOL, 
                            &EDKII_PLATFORM_SPECIFIC_RESET_HANDLER_PROTOCOL, &EFI_PRINT2S_PROTOCOL, &EFI_PS2_POLICY_PROTOCOL, 
                            &EDKII_SD_MMC_OVERRIDE, NULL, &EFI_SMM_FAULT_TOLERANT_WRITE_PROTOCOL, 
                            &EFI_SMM_FIRMWARE_VOLUME_BLOCK_PROTOCOL, NULL, &EDKII_SMM_MEMORY_ATTRIBUTE_PROTOCOL, 
                            NULL, &EFI_SMM_SWAP_ADDRESS_RANGE_PROTOCOL, &EDKII_SMM_VAR_CHECK_PROTOCOL, 
                            &EFI_SMM_VARIABLE_PROTOCOL, &EFI_SWAP_ADDRESS_RANGE_PROTOCOL, &EDKII_UFS_HOST_CONTROLLER_PROTOCOL, 
                            &EDKII_UFS_HC_PLATFORM_PROTOCOL, &EDKII_VAR_CHECK_PROTOCOL, &EDKII_VARIABLE_LOCK_PROTOCOL, 
                            &EDKII_VARIABLE_POLICY_PROTOCOL};


UINT32 ProtocolAttributes[] = {EFI_OPEN_PROTOCOL_GET_PROTOCOL, EFI_OPEN_PROTOCOL_BY_DRIVER, EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER, 
                            EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL, EFI_OPEN_PROTOCOL_TEST_PROTOCOL, EFI_OPEN_PROTOCOL_EXCLUSIVE};

EFI_STATUS
EFIAPI
FuzzProtocol(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzLocateProtocol(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzOpenProtocol(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzCloseProtocol(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzHandleProtocol(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzOpenProtocolInformation(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzProtocolsPerHandle(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzLocateHandleBuffer(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzInstallProtocolInterface(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzReinstallProtocolInterface(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzUninstallProtocolInterface(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzInstallMultipleProtocolInterfaces(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzUninstallMultipleProtocolInterfaces(
    IN INPUT_BUFFER *Input
);

#endif