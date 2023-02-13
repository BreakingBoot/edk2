/** @file

INTEL CONFIDENTIAL

Copyright (c) 2011-2013 Intel Corporation. All rights reserved.
The source code contained or described herein and all documents related 
to the source code ("Material") are owned by Intel Corporation or its 
suppliers or licensors. Title to the Material remains with Intel 
Corporation or its suppliers and licensors. 
The Material may contain trade secrets and proprietary and confidential 
information of Intel Corporation and its suppliers and licensors, and is 
protected by worldwide copyright and trade secret laws and treaty 
provisions. No part of the Material may be used, copied, reproduced, 
modified, published, uploaded, posted, transmitted, distributed, or 
disclosed in any way without Intel's prior express written permission. 

No license under any patent, copyright, trade secret or other intellectual 
property right is granted to or conferred upon you by disclosure or 
delivery of the Materials, either expressly, by implication, inducement, 
estoppel or otherwise. Any license under such intellectual property rights 
must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, 
preceded by an asterisk. An asterisked footnote can be added as follows: 
*Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter 
this notice or any other notice embedded in Materials by Intel or Intel's 
suppliers or licensors in any way.

Module Name:

  CodeCoveragePei.c

Abstract:

  This PEI module enables a code coverage on PEI phase for EDK modules. 

**/
#include <Library/CodeCoveragePeimLib.h>
#include <Library/DebugLib.h>
#include <Library/PeiServicesLib.h>

/**
  Main entry for PEIM.

  @param  FileHandle  Handle of the file being invoked.
  @param  PeiServices Describes the list of possible PEI Services.

  @return Status of install PCD_PPI

**/
EFI_STATUS
EFIAPI
PeimInit (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )
{ 
  EFI_STATUS     Status;

  Status            = EFI_SUCCESS;
  
  DEBUG ((EFI_D_INFO, "\n!!!!!Initialize the PEI code coverage test environment!!!!!\n"));
  
  //
  // Build the code coverage services for PEI phase.
  //
  //
  // 0x21 - 0xf..f are reserved.
  // 
  // #define BOOT_WITH_FULL_CONFIGURATION                  0x00
  // #define BOOT_WITH_MINIMAL_CONFIGURATION               0x01
  // #define BOOT_ASSUMING_NO_CONFIGURATION_CHANGES        0x02
  // #define BOOT_WITH_FULL_CONFIGURATION_PLUS_DIAGNOSTICS 0x03
  // #define BOOT_WITH_DEFAULT_SETTINGS                    0x04
  // #define BOOT_ON_S4_RESUME                             0x05
  // #define BOOT_ON_S5_RESUME                             0x06
  // #define BOOT_WITH_MFG_MODE_SETTINGS                   0x07
  // #define BOOT_ON_S2_RESUME                             0x10
  // #define BOOT_ON_S3_RESUME                             0x11
  // #define BOOT_ON_FLASH_UPDATE                          0x12
  // #define BOOT_IN_RECOVERY_MODE                         0x20
  //
  // If TRUE, it will load the FVMAIN.Fv from USB disk and use 
  // the second parameter as its BootMode
  // Or else, load the FVMAIN.Fv from NorFlash and ingore the second parameter.
  //
  Status = PeiCovServices(FALSE, BOOT_WITH_FULL_CONFIGURATION);

  return Status;
}

