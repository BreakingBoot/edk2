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

  TianoLib.h

Abstract:

  Defines some EDK2 specific APIs which will used by bullseye coverage lib.

**/
#if _MSC_EXTENSIONS
  //
  // Microsoft* compiler requires _EFIAPI useage, __cdecl is Microsoft* specific C.
  // 
  #define EFIAPI __cdecl  
#endif
#if !defined(__GNUC__) && (__STDC_VERSION__ < 199901L)
  //
  // No ANSI C 2000 stdint.h integer width declarations, so define equivalents
  //
  #if _MSC_EXTENSIONS 
    
    //
    // use Microsoft* C complier dependent interger width types 
    //
    typedef unsigned __int64    UINT64;
    typedef __int64             INT64;
    typedef unsigned __int32    UINT32;
    typedef __int32             INT32;
    typedef unsigned short      UINT16;
    typedef unsigned short      CHAR16;
    typedef short               INT16;
    typedef unsigned char       BOOLEAN;
    typedef unsigned char       UINT8;
    typedef char                CHAR8;
    typedef char                INT8;
  #else

    //
    // Assume standard IA-32 alignment. 
    // BugBug: Need to check portability of long long
    //
    typedef unsigned long long  UINT64;
    typedef long long           INT64;
    typedef unsigned int        UINT32;
    typedef int                 INT32;
    typedef unsigned short      UINT16;
    typedef unsigned short      CHAR16;
    typedef short               INT16;
    typedef unsigned char       BOOLEAN;
    typedef unsigned char       UINT8;
    typedef char                CHAR8;
    typedef char                INT8;
  #endif

  #define UINT8_MAX 0xff

#else
  //
  // Use ANSI C 2000 stdint.h integer width declarations
  //
  #include "stdint.h"
  typedef uint8_t   BOOLEAN;
  typedef int8_t    INT8;
  typedef uint8_t   UINT8;
  typedef int16_t   INT16;
  typedef uint16_t  UINT16;
  typedef int32_t   INT32;
  typedef uint32_t  UINT32;
  typedef int64_t   INT64;
  typedef uint64_t  UINT64;
  typedef char      CHAR8;
  typedef uint16_t  CHAR16;

#endif

typedef UINT32  UINTN;
typedef INT32   INTN;


typedef INTN EFI_STATUS;

#define EFI_PHYSICAL_ADDRESS  UINT64

#define VOID      void

#define IN
#define OUT
///
/// Datum is read-only
///
#define CONST     const

#define DEBUG_ERROR     0x80000000
#define EFI_D_ERROR     DEBUG_ERROR

#define EFI_SUCCESS     0

//#define _DEBUG_BUILD_           0

//
// Declare bits for PcdDebugPrintErrorLevel and the ErrorLevel parameter of DebugPrint()
//
#define DEBUG_INIT      0x00000001  // Initialization
#define DEBUG_WARN      0x00000002  // Warnings
#define DEBUG_LOAD      0x00000004  // Load events
#define DEBUG_FS        0x00000008  // EFI File system
#define DEBUG_POOL      0x00000010  // Alloc & Free's
#define DEBUG_PAGE      0x00000020  // Alloc & Free's
#define DEBUG_INFO      0x00000040  // Verbose
#define DEBUG_DISPATCH  0x00000080  // PEI/DXE/SMM Dispatchers
#define DEBUG_VARIABLE  0x00000100  // Variable
#define DEBUG_BM        0x00000400  // Boot Manager
#define DEBUG_BLKIO     0x00001000  // BlkIo Driver
#define DEBUG_NET       0x00004000  // SNI Driver
#define DEBUG_UNDI      0x00010000  // UNDI Driver
#define DEBUG_LOADFILE  0x00020000  // UNDI Driver
#define DEBUG_EVENT     0x00080000  // Event messages
#define DEBUG_GCD       0x00100000  // Global Coherency Database changes
#define DEBUG_CACHE     0x00200000  // Memory range cachability changes
#define DEBUG_ERROR     0x80000000  // Error

#define EINTR (-1)
#define ENOSYS (-2)

#define O_CREAT 0x0100
#define O_RDONLY 0
#define O_RDWR 2
#define O_WRONLY 1
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0
//
//Maximum number of bytes in a pathname, including the terminating null character.
//
#define PATH_MAX 128
#define NULL 0
#define cov_atomic_initializer 1
typedef volatile UINT32 cov_atomic_t;
typedef UINT32 off_t;

extern int    CovError;
extern UINT32 cov_file_open_lock;
extern UINT32 cov_file_write_lock;

extern 
VOID
EFIAPI
DebugPrint (
  IN  UINTN        ErrorLevel,
  IN  CONST CHAR8  *Format,
  ...
  );

extern
__inline UINT32 cov_atomic_tryLock (
  IN   volatile UINT32*    p
  );
  
extern
__inline VOID cov_atomic_unlock (
  IN   volatile UINT32* p
  );
  
extern
INT32
CovFileOpen (
  IN     CONST CHAR8* path, 
  IN     INT32        oflag, 
  IN     INT32        mode
  );

extern
INT32 
CovFileClose (
  IN      INT32  fildes
  );

extern
INT32
CovFileRead (
  IN     INT32       fildes, 
  IN     VOID*       buf, 
  IN     INT32       nbyte
  );

extern
INT32
CovFileWrite (
  IN     INT32       fildes, 
  IN     CONST VOID* buf, 
  IN     INT32       nbyte
  );


extern
INT32
CovFileLseek (
  IN      INT32   fildes, 
  IN      INT32   offset, 
  IN      INT32   whence
  );


extern
INT32
CovFileExit (
  IN      VOID (*function)(VOID)
  );
 
extern 
CHAR8* 
CovFileGetEnv (
  IN    CONST   CHAR8* name
  );

extern
CHAR8* 
CovFileGetCwd (
  IN      CHAR8*   buf, 
  IN      UINT32   size
  );
