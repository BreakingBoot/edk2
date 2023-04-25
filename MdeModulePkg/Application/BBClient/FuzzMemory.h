#ifndef _FUZZMEMORY_H_
#define _FUZZMEMORY_H_

#define ADD_MEMORY_SPACE 0
#define ALLOCATE_MEMORY_SPACE 1
#define FREE_MEMORY_SPACE 2
#define REMOVE_MEMORY_SPACE 3
#define GET_MEMORY_SPACE_DESCRIPTOR 4
#define SET_MEMORY_SPACE_ATTRIBUTES 5
#define GET_MEMORY_SPACE_MAP 6
#define SET_MEMORY_SPACE_CAPABILITIES 7
#define ALLOCATE_PAGES 8
#define FREE_PAGES 9
#define GET_MEMORY_MAP 10
#define ALLOCATE_POOL 11
#define FREE_POOL 12
#define COPY_MEM 13
#define SET_MEM 14

EFI_ALLOCATE_TYPE AllocationTypes[]  = {///
                                        /// Allocate any available range of pages that satisfies the request.
                                        ///
                                        AllocateAnyPages,
                                        ///
                                        /// Allocate any available range of pages whose uppermost address is less than
                                        /// or equal to a specified maximum address.
                                        ///
                                        AllocateMaxAddress,
                                        ///
                                        /// Allocate pages at a specified address.
                                        ///
                                        AllocateAddress,
                                        ///
                                        /// Maximum enumeration value that may be used for bounds checking.
                                        ///
                                        MaxAllocateType};

EFI_MEMORY_TYPE MemoryTypes[] = {EfiReservedMemoryType,
                                ///
                                /// The code portions of a loaded application.
                                /// (Note that UEFI OS loaders are UEFI applications.)
                                ///
                                EfiLoaderCode,
                                ///
                                /// The data portions of a loaded application and the default data allocation
                                /// type used by an application to allocate pool memory.
                                ///
                                EfiLoaderData,
                                ///
                                /// The code portions of a loaded Boot Services Driver.
                                ///
                                EfiBootServicesCode,
                                ///
                                /// The data portions of a loaded Boot Serves Driver, and the default data
                                /// allocation type used by a Boot Services Driver to allocate pool memory.
                                ///
                                EfiBootServicesData,
                                ///
                                /// The code portions of a loaded Runtime Services Driver.
                                ///
                                EfiRuntimeServicesCode,
                                ///
                                /// The data portions of a loaded Runtime Services Driver and the default
                                /// data allocation type used by a Runtime Services Driver to allocate pool memory.
                                ///
                                EfiRuntimeServicesData,
                                ///
                                /// Free (unallocated) memory.
                                ///
                                EfiConventionalMemory,
                                ///
                                /// Memory in which errors have been detected.
                                ///
                                EfiUnusableMemory,
                                ///
                                /// Memory that holds the ACPI tables.
                                ///
                                EfiACPIReclaimMemory,
                                ///
                                /// Address space reserved for use by the firmware.
                                ///
                                EfiACPIMemoryNVS,
                                ///
                                /// Used by system firmware to request that a memory-mapped IO region
                                /// be mapped by the OS to a virtual address so it can be accessed by EFI runtime services.
                                ///
                                EfiMemoryMappedIO,
                                ///
                                /// System memory-mapped IO region that is used to translate memory
                                /// cycles to IO cycles by the processor.
                                ///
                                EfiMemoryMappedIOPortSpace,
                                ///
                                /// Address space reserved by the firmware for code that is part of the processor.
                                ///
                                EfiPalCode,
                                ///
                                /// A memory region that operates as EfiConventionalMemory,
                                /// however it happens to also support byte-addressable non-volatility.
                                ///
                                EfiPersistentMemory,
                                ///
                                /// A memory region that describes system memory that has not been accepted
                                /// by a corresponding call to the underlying isolation architecture.
                                ///
                                EfiUnacceptedMemoryType,
                                EfiMaxMemoryType
                                };

EFI_GCD_MEMORY_TYPE GcdMemoryTypes[] = {///
                                        /// A memory region that is visible to the boot processor. However, there are no system
                                        /// components that are currently decoding this memory region.
                                        ///
                                        EfiGcdMemoryTypeNonExistent,
                                        ///
                                        /// A memory region that is visible to the boot processor. This memory region is being
                                        /// decoded by a system component, but the memory region is not considered to be either
                                        /// system memory or memory-mapped I/O.
                                        ///
                                        EfiGcdMemoryTypeReserved,
                                        ///
                                        /// A memory region that is visible to the boot processor. A memory controller is
                                        /// currently decoding this memory region and the memory controller is producing a
                                        /// tested system memory region that is available to the memory services.
                                        ///
                                        EfiGcdMemoryTypeSystemMemory,
                                        ///
                                        /// A memory region that is visible to the boot processor. This memory region is
                                        /// currently being decoded by a component as memory-mapped I/O that can be used to
                                        /// access I/O devices in the platform.
                                        ///
                                        EfiGcdMemoryTypeMemoryMappedIo,
                                        ///
                                        /// A memory region that is visible to the boot processor.
                                        /// This memory supports byte-addressable non-volatility.
                                        ///
                                        EfiGcdMemoryTypePersistent,
                                        //
                                        // Keep original one for the compatibility.
                                        //
                                        EfiGcdMemoryTypePersistentMemory = EfiGcdMemoryTypePersistent,
                                        ///
                                        /// A memory region that provides higher reliability relative to other memory in the
                                        /// system. If all memory has the same reliability, then this bit is not used.
                                        ///
                                        EfiGcdMemoryTypeMoreReliable,
                                        // ///
                                        // /// A memory region that describes system memory that has not been accepted
                                        // /// by a corresponding call to the underlying isolation architecture.
                                        // ///
                                        // /// Please be noted:
                                        // /// EfiGcdMemoryTypeUnaccepted is defined in PrePiDxeCis.h because it has not been
                                        // /// defined in PI spec.
                                        // EfiGcdMemoryTypeUnaccepted,
                                        EfiGcdMemoryTypeMaximum = 7
                                        };

EFI_STATUS
EFIAPI
FuzzMemory(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzAddMemorySpace(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzAllocateMemorySpace(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzFreeMemorySpace(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzRemoveMemorySpace(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzGetMemorySpaceDescriptor(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzSetMemorySpaceAttributes(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzGetMemorySpaceMap(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzSetMemorySpaceCapabilities(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzAllocatePages(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzFreePages(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzGetMemoryMap(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzAllocatePool(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzFreePool(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzCopyMem(
    IN INPUT_BUFFER *Input
);

EFI_STATUS
EFIAPI
FuzzSetMem(
    IN INPUT_BUFFER *Input
);

#endif