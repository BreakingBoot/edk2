#ifndef _FUZZSMMHARDEN_H_
#define _FUZZSMMHARDEN_H_

#include "BBClientUtilities.h"
#include <Protocol/SmmCommunication.h>

EFI_STATUS
EFIAPI
FuzzSmmHarden(
    IN INPUT_BUFFER *Input
);

VOID
CommunicateSMM(
  IN EFI_GUID  Guid,
  IN VOID     *Data,
  IN UINTN    DataSize
);

#endif