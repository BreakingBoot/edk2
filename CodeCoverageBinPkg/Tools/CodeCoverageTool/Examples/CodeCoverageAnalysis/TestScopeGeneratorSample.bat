@REM @file

@REM INTEL CONFIDENTIAL

@REM  Copyright (c) 2011-2013 Intel Corporation. All rights reserved.
@REM  The source code contained or described herein and all documents related 
@REM  to the source code ("Material") are owned by Intel Corporation or its 
@REM  suppliers or licensors. Title to the Material remains with Intel 
@REM  Corporation or its suppliers and licensors. 
@REM  The Material may contain trade secrets and proprietary and confidential 
@REM  information of Intel Corporation and its suppliers and licensors, and is 
@REM  protected by worldwide copyright and trade secret laws and treaty 
@REM  provisions. No part of the Material may be used, copied, reproduced, 
@REM  modified, published, uploaded, posted, transmitted, distributed, or 
@REM  disclosed in any way without Intel's prior express written permission. 
@REM  
@REM  No license under any patent, copyright, trade secret or other intellectual 
@REM  property right is granted to or conferred upon you by disclosure or 
@REM  delivery of the Materials, either expressly, by implication, inducement, 
@REM  estoppel or otherwise. Any license under such intellectual property rights 
@REM  must be express and approved by Intel in writing.
@REM  
@REM  Include any supplier copyright notices as supplier requires Intel to use.
@REM  
@REM  Include supplier trademarks or logos as supplier requires Intel to use, 
@REM  preceded by an asterisk. An asterisked footnote can be added as follows: 
@REM  *Third Party trademarks are the property of their respective owners.
@REM  
@REM  Unless otherwise agreed by Intel in writing, you may not remove or alter 
@REM  this notice or any other notice embedded in Materials by Intel or Intel's 
@REM  suppliers or licensors in any way.


@REM @file
@REM
@REM   An example of code coverage test scope generator 
@REM

@echo "Need to set EDK_TREE_PATH to the EDKII workspace by user manually"
@set EDK_TREE_PATH=c:\R9\EDK2

subst s: %EDK_TREE_PATH%
set PATH=%EDK_TREE_PATH%\CodeCoverageBinPkg\Tools\CodeCoverageTool\Bin\;%EDK_TREE_PATH%\CodeCoverageBinPkg\Tools\CodeCoverageTool\ItsCovAnalysisTool\;%PATH%

@REM ITS Native Code Coverage
ucovanalyse -p Patch\DxeMain.c.patch -w s:\ -i covdbconfig.ini -o ItsClientBat_DxeMain.bat
ucovanalyse -p Patch\MdeModulePkg.patch -w s:\ -i covdbconfig.ini -o ItsClientBat_MdeModulePkg.bat
