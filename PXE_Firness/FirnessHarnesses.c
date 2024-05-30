#include "FirnessHarnesses.h"

/*
    This is a harness for fuzzing the protocol service
    called Stop.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzStop(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    
    Status = ProtocolVariable->Stop(
        ProtocolVariable
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called Mtftp.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzMtftp(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    EFI_PXE_BASE_CODE_TFTP_OPCODE Mtftp_Arg_1 = 0;
    UINTN*  Mtftp_Arg_2 = AllocateZeroPool(sizeof(UINTN ));
    BOOLEAN Mtftp_Arg_3 = FALSE;
    UINT64 * Mtftp_Arg_4 = AllocateZeroPool(sizeof(UINT64));
    UINTN * Mtftp_Arg_5 = AllocateZeroPool(sizeof(UINTN));
    EFI_IP_ADDRESS * Mtftp_Arg_6 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    UINT8 * Mtftp_Arg_7 = AllocateZeroPool(sizeof(UINT8));
    EFI_PXE_BASE_CODE_MTFTP_INFO * Mtftp_Arg_8 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_MTFTP_INFO));
    BOOLEAN Mtftp_Arg_9 = FALSE;
    
    
    // Constant Variable Initialization
    UINT8* Mtftp_Arg_1_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(Mtftp_Arg_1_choice), (VOID *)Mtftp_Arg_1_choice);
    switch(*Mtftp_Arg_1_choice % 10) {
        case 0:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_MTFTP_GET_FILE_SIZE;
            break;
        case 1:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_MTFTP_LAST;
            break;
        case 2:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_MTFTP_READ_DIRECTORY;
            break;
        case 3:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_MTFTP_READ_FILE;
            break;
        case 4:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_TFTP_FIRST;
            break;
        case 5:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_TFTP_GET_FILE_SIZE;
            break;
        case 6:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_TFTP_READ_DIRECTORY;
            break;
        case 7:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_TFTP_READ_FILE;
            break;
        case 8:
            Mtftp_Arg_1 = EFI_PXE_BASE_CODE_TFTP_WRITE_FILE;
            break;
        case 9:
            ReadBytes(Input, sizeof(Mtftp_Arg_1), (VOID *)&Mtftp_Arg_1);
            break;
    }
    
    // Fuzzable Variable Initialization
    UINT8 Mtftp_Arg_2_choice = 0;
    ReadBytes(Input, sizeof(Mtftp_Arg_2_choice), (VOID *)&Mtftp_Arg_2_choice);
    switch(Mtftp_Arg_2_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(Mtftp_Arg_2), (VOID *)Mtftp_Arg_2);
            break;
        case 1:
        {
            gBS->FreePool(Mtftp_Arg_2);
            Mtftp_Arg_2 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Mtftp_Arg_3), (VOID *)&Mtftp_Arg_3);
    
    // Fuzzable Variable Initialization
    UINT8 Mtftp_Arg_4_choice = 0;
    ReadBytes(Input, sizeof(Mtftp_Arg_4_choice), (VOID *)&Mtftp_Arg_4_choice);
    switch(Mtftp_Arg_4_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(Mtftp_Arg_4), (VOID *)Mtftp_Arg_4);
            break;
        case 1:
        {
            gBS->FreePool(Mtftp_Arg_4);
            Mtftp_Arg_4 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 Mtftp_Arg_5_choice = 0;
    ReadBytes(Input, sizeof(Mtftp_Arg_5_choice), (VOID *)&Mtftp_Arg_5_choice);
    switch(Mtftp_Arg_5_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(Mtftp_Arg_5), (VOID *)Mtftp_Arg_5);
            break;
        case 1:
        {
            gBS->FreePool(Mtftp_Arg_5);
            Mtftp_Arg_5 = NULL;
            break;
        }
    }
    
    UINT8* Mtftp_Arg_6_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(Mtftp_Arg_6_choice), (VOID *)Mtftp_Arg_6_choice);
    switch(*Mtftp_Arg_6_choice % 8) {
        case 0:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * NetLibStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0_choice), (VOID *)&NetLibStrToIp4_Arg_0_choice);
            switch(NetLibStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0), (VOID *)NetLibStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibStrToIp4_Arg_0);
                    NetLibStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibStrToIp4_Arg_1_OutputChoice);
            if(*NetLibStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibStrToIp4_Arg_1), (VOID *)NetLibStrToIp4_Arg_1);
            }
            Status = NetLibStrToIp4(
                NetLibStrToIp4_Arg_0,
                NetLibStrToIp4_Arg_1
            );
    
            break;
        }
        case 1:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR8 * NetLibAsciiStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR8));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibAsciiStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0_choice), (VOID *)&NetLibAsciiStrToIp4_Arg_0_choice);
            switch(NetLibAsciiStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0), (VOID *)NetLibAsciiStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibAsciiStrToIp4_Arg_0);
                    NetLibAsciiStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibAsciiStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibAsciiStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibAsciiStrToIp4_Arg_1_OutputChoice);
            if(*NetLibAsciiStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibAsciiStrToIp4_Arg_1), (VOID *)NetLibAsciiStrToIp4_Arg_1);
            }
            Status = NetLibAsciiStrToIp4(
                NetLibAsciiStrToIp4_Arg_0,
                NetLibAsciiStrToIp4_Arg_1
            );
    
            break;
        }
        case 2:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * HttpDns4_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 HttpDns4_Arg_1_choice = 0;
            ReadBytes(Input, sizeof(HttpDns4_Arg_1_choice), (VOID *)&HttpDns4_Arg_1_choice);
            switch(HttpDns4_Arg_1_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(HttpDns4_Arg_1), (VOID *)HttpDns4_Arg_1);
                    break;
                case 1:
                {
                    gBS->FreePool(HttpDns4_Arg_1);
                    HttpDns4_Arg_1 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * HttpDns4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* HttpDns4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(HttpDns4_Arg_2_OutputChoice), (VOID *)HttpDns4_Arg_2_OutputChoice);
            if(*HttpDns4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*HttpDns4_Arg_2), (VOID *)HttpDns4_Arg_2);
            }
            Status = HttpDns4(
                NULL,
                HttpDns4_Arg_1,
                HttpDns4_Arg_2
            );
    
            break;
        }
        case 3:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 StrToIpv4Address_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0_choice), (VOID *)&StrToIpv4Address_Arg_0_choice);
            switch(StrToIpv4Address_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0), (VOID *)StrToIpv4Address_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(StrToIpv4Address_Arg_0);
                    StrToIpv4Address_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            UINT8* StrToIpv4Address_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_1_OutputChoice), (VOID *)StrToIpv4Address_Arg_1_OutputChoice);
            if(*StrToIpv4Address_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_1), (VOID *)StrToIpv4Address_Arg_1);
            }
            EFI_IPv4_ADDRESS * StrToIpv4Address_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* StrToIpv4Address_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_2_OutputChoice), (VOID *)StrToIpv4Address_Arg_2_OutputChoice);
            if(*StrToIpv4Address_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_2), (VOID *)StrToIpv4Address_Arg_2);
            }
            UINT8 * StrToIpv4Address_Arg_3 = AllocateZeroPool(sizeof(UINT8));
            UINT8* StrToIpv4Address_Arg_3_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_3_OutputChoice), (VOID *)StrToIpv4Address_Arg_3_OutputChoice);
            if(*StrToIpv4Address_Arg_3_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_3), (VOID *)StrToIpv4Address_Arg_3);
            }
            StrToIpv4Address(
                StrToIpv4Address_Arg_0,
                (CHAR16 **)&StrToIpv4Address_Arg_1,
                StrToIpv4Address_Arg_2,
                StrToIpv4Address_Arg_3
            );
    
            break;
        }
        case 4:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIp_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIp_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0_choice), (VOID *)&Ip4Config2StrToIp_Arg_0_choice);
            switch(Ip4Config2StrToIp_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0), (VOID *)Ip4Config2StrToIp_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIp_Arg_0);
                    Ip4Config2StrToIp_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIp_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIp_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIp_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIp_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIp_Arg_1), (VOID *)Ip4Config2StrToIp_Arg_1);
            }
            Status = Ip4Config2StrToIp(
                Ip4Config2StrToIp_Arg_0,
                Ip4Config2StrToIp_Arg_1
            );
    
            break;
        }
        case 5:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIpList_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIpList_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0_choice), (VOID *)&Ip4Config2StrToIpList_Arg_0_choice);
            switch(Ip4Config2StrToIpList_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0), (VOID *)Ip4Config2StrToIpList_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIpList_Arg_0);
                    Ip4Config2StrToIpList_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIpList_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIpList_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_1), (VOID *)Ip4Config2StrToIpList_Arg_1);
            }
            UINTN * Ip4Config2StrToIpList_Arg_2 = AllocateZeroPool(sizeof(UINTN));
            UINT8* Ip4Config2StrToIpList_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_2_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_2_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_2), (VOID *)Ip4Config2StrToIpList_Arg_2);
            }
            Status = Ip4Config2StrToIpList(
                Ip4Config2StrToIpList_Arg_0,
                (EFI_IPv4_ADDRESS **)&Ip4Config2StrToIpList_Arg_1,
                Ip4Config2StrToIpList_Arg_2
            );
    
            break;
        }
        case 6:
        {
        // Generator Struct Variable Initialization
            /*
                Output Variable(s)
            */
            UINT32 * GetDns4ServerFromDhcp4_Arg_1 = AllocateZeroPool(sizeof(UINT32));
            UINT8* GetDns4ServerFromDhcp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_1_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_1_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_1), (VOID *)GetDns4ServerFromDhcp4_Arg_1);
            }
            EFI_IPv4_ADDRESS * GetDns4ServerFromDhcp4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* GetDns4ServerFromDhcp4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_2_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_2_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_2), (VOID *)GetDns4ServerFromDhcp4_Arg_2);
            }
            Status = GetDns4ServerFromDhcp4(
                NULL,
                GetDns4ServerFromDhcp4_Arg_1,
                (EFI_IPv4_ADDRESS **)&GetDns4ServerFromDhcp4_Arg_2
            );
    
            break;
        }
        case 7:
        {
        // Generator Struct Variable Initialization
        ReadBytes(Input, sizeof(Mtftp_Arg_6->Addr), (VOID *)&(Mtftp_Arg_6->Addr));
        ReadBytes(Input, sizeof(Mtftp_Arg_6->v4), (VOID *)&(Mtftp_Arg_6->v4));
        ReadBytes(Input, sizeof(Mtftp_Arg_6->v6), (VOID *)&(Mtftp_Arg_6->v6));
    
            break;
        }
    }
    // Fuzzable Variable Initialization
    UINT8 Mtftp_Arg_7_choice = 0;
    ReadBytes(Input, sizeof(Mtftp_Arg_7_choice), (VOID *)&Mtftp_Arg_7_choice);
    switch(Mtftp_Arg_7_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(Mtftp_Arg_7), (VOID *)Mtftp_Arg_7);
            break;
        case 1:
        {
            gBS->FreePool(Mtftp_Arg_7);
            Mtftp_Arg_7 = NULL;
            break;
        }
    }
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(Mtftp_Arg_8->MCastIp), (VOID *)&(Mtftp_Arg_8->MCastIp));
    ReadBytes(Input, sizeof(Mtftp_Arg_8->CPort), (VOID *)&(Mtftp_Arg_8->CPort));
    ReadBytes(Input, sizeof(Mtftp_Arg_8->SPort), (VOID *)&(Mtftp_Arg_8->SPort));
    ReadBytes(Input, sizeof(Mtftp_Arg_8->ListenTimeout), (VOID *)&(Mtftp_Arg_8->ListenTimeout));
    ReadBytes(Input, sizeof(Mtftp_Arg_8->TransmitTimeout), (VOID *)&(Mtftp_Arg_8->TransmitTimeout));
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Mtftp_Arg_9), (VOID *)&Mtftp_Arg_9);
    
    Status = ProtocolVariable->Mtftp(
        ProtocolVariable,
        Mtftp_Arg_1,
        (void *)Mtftp_Arg_2,
        Mtftp_Arg_3,
        Mtftp_Arg_4,
        Mtftp_Arg_5,
        Mtftp_Arg_6,
        Mtftp_Arg_7,
        Mtftp_Arg_8,
        Mtftp_Arg_9
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called Dhcp.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzDhcp(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    BOOLEAN Dhcp_Arg_1 = FALSE;
    
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Dhcp_Arg_1), (VOID *)&Dhcp_Arg_1);
    
    Status = ProtocolVariable->Dhcp(
        ProtocolVariable,
        Dhcp_Arg_1
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called Discover.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzDiscover(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    UINT16 Discover_Arg_1 = 0;
    UINT16 * Discover_Arg_2 = AllocateZeroPool(sizeof(UINT16));
    BOOLEAN Discover_Arg_3 = FALSE;
    EFI_PXE_BASE_CODE_DISCOVER_INFO * Discover_Arg_4 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_DISCOVER_INFO));
    
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Discover_Arg_1), (VOID *)&Discover_Arg_1);
    
    // Fuzzable Variable Initialization
    UINT8 Discover_Arg_2_choice = 0;
    ReadBytes(Input, sizeof(Discover_Arg_2_choice), (VOID *)&Discover_Arg_2_choice);
    switch(Discover_Arg_2_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(Discover_Arg_2), (VOID *)Discover_Arg_2);
            break;
        case 1:
        {
            gBS->FreePool(Discover_Arg_2);
            Discover_Arg_2 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Discover_Arg_3), (VOID *)&Discover_Arg_3);
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(Discover_Arg_4->UseMCast), (VOID *)&(Discover_Arg_4->UseMCast));
    ReadBytes(Input, sizeof(Discover_Arg_4->UseBCast), (VOID *)&(Discover_Arg_4->UseBCast));
    ReadBytes(Input, sizeof(Discover_Arg_4->UseUCast), (VOID *)&(Discover_Arg_4->UseUCast));
    ReadBytes(Input, sizeof(Discover_Arg_4->MustUseList), (VOID *)&(Discover_Arg_4->MustUseList));
    ReadBytes(Input, sizeof(Discover_Arg_4->ServerMCastIp), (VOID *)&(Discover_Arg_4->ServerMCastIp));
    ReadBytes(Input, sizeof(Discover_Arg_4->IpCnt), (VOID *)&(Discover_Arg_4->IpCnt));
    ReadBytes(Input, sizeof(Discover_Arg_4->SrvList), (VOID *)&(Discover_Arg_4->SrvList));
    
    Status = ProtocolVariable->Discover(
        ProtocolVariable,
        Discover_Arg_1,
        Discover_Arg_2,
        Discover_Arg_3,
        Discover_Arg_4
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called SetParameters.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzSetParameters(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    BOOLEAN * SetParameters_Arg_1 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetParameters_Arg_2 = AllocateZeroPool(sizeof(BOOLEAN));
    UINT8 * SetParameters_Arg_3 = AllocateZeroPool(sizeof(UINT8));
    UINT8 * SetParameters_Arg_4 = AllocateZeroPool(sizeof(UINT8));
    BOOLEAN * SetParameters_Arg_5 = AllocateZeroPool(sizeof(BOOLEAN));
    
    
    // Fuzzable Variable Initialization
    UINT8 SetParameters_Arg_1_choice = 0;
    ReadBytes(Input, sizeof(SetParameters_Arg_1_choice), (VOID *)&SetParameters_Arg_1_choice);
    switch(SetParameters_Arg_1_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetParameters_Arg_1), (VOID *)SetParameters_Arg_1);
            break;
        case 1:
        {
            gBS->FreePool(SetParameters_Arg_1);
            SetParameters_Arg_1 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetParameters_Arg_2_choice = 0;
    ReadBytes(Input, sizeof(SetParameters_Arg_2_choice), (VOID *)&SetParameters_Arg_2_choice);
    switch(SetParameters_Arg_2_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetParameters_Arg_2), (VOID *)SetParameters_Arg_2);
            break;
        case 1:
        {
            gBS->FreePool(SetParameters_Arg_2);
            SetParameters_Arg_2 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetParameters_Arg_3_choice = 0;
    ReadBytes(Input, sizeof(SetParameters_Arg_3_choice), (VOID *)&SetParameters_Arg_3_choice);
    switch(SetParameters_Arg_3_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetParameters_Arg_3), (VOID *)SetParameters_Arg_3);
            break;
        case 1:
        {
            gBS->FreePool(SetParameters_Arg_3);
            SetParameters_Arg_3 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetParameters_Arg_4_choice = 0;
    ReadBytes(Input, sizeof(SetParameters_Arg_4_choice), (VOID *)&SetParameters_Arg_4_choice);
    switch(SetParameters_Arg_4_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetParameters_Arg_4), (VOID *)SetParameters_Arg_4);
            break;
        case 1:
        {
            gBS->FreePool(SetParameters_Arg_4);
            SetParameters_Arg_4 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetParameters_Arg_5_choice = 0;
    ReadBytes(Input, sizeof(SetParameters_Arg_5_choice), (VOID *)&SetParameters_Arg_5_choice);
    switch(SetParameters_Arg_5_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetParameters_Arg_5), (VOID *)SetParameters_Arg_5);
            break;
        case 1:
        {
            gBS->FreePool(SetParameters_Arg_5);
            SetParameters_Arg_5 = NULL;
            break;
        }
    }
    
    Status = ProtocolVariable->SetParameters(
        ProtocolVariable,
        SetParameters_Arg_1,
        SetParameters_Arg_2,
        SetParameters_Arg_3,
        SetParameters_Arg_4,
        SetParameters_Arg_5
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called UdpWrite.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzUdpWrite(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    UINT16 UdpWrite_Arg_1 = 0;
    EFI_IP_ADDRESS * UdpWrite_Arg_2 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_PXE_BASE_CODE_UDP_PORT * UdpWrite_Arg_3 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_UDP_PORT));
    EFI_IP_ADDRESS * UdpWrite_Arg_4 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_IP_ADDRESS * UdpWrite_Arg_5 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_PXE_BASE_CODE_UDP_PORT * UdpWrite_Arg_6 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_UDP_PORT));
    UINTN * UdpWrite_Arg_7 = AllocateZeroPool(sizeof(UINTN));
    UINTN*  UdpWrite_Arg_8 = AllocateZeroPool(sizeof(UINTN ));
    UINTN * UdpWrite_Arg_9 = AllocateZeroPool(sizeof(UINTN));
    UINTN*  UdpWrite_Arg_10 = AllocateZeroPool(sizeof(UINTN ));
    
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(UdpWrite_Arg_1), (VOID *)&UdpWrite_Arg_1);
    
    UINT8* UdpWrite_Arg_2_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(UdpWrite_Arg_2_choice), (VOID *)UdpWrite_Arg_2_choice);
    switch(*UdpWrite_Arg_2_choice % 9) {
        case 0:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * NetLibStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0_choice), (VOID *)&NetLibStrToIp4_Arg_0_choice);
            switch(NetLibStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0), (VOID *)NetLibStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibStrToIp4_Arg_0);
                    NetLibStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibStrToIp4_Arg_1_OutputChoice);
            if(*NetLibStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibStrToIp4_Arg_1), (VOID *)NetLibStrToIp4_Arg_1);
            }
            Status = NetLibStrToIp4(
                NetLibStrToIp4_Arg_0,
                NetLibStrToIp4_Arg_1
            );
    
            break;
        }
        case 1:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR8 * NetLibAsciiStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR8));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibAsciiStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0_choice), (VOID *)&NetLibAsciiStrToIp4_Arg_0_choice);
            switch(NetLibAsciiStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0), (VOID *)NetLibAsciiStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibAsciiStrToIp4_Arg_0);
                    NetLibAsciiStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibAsciiStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibAsciiStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibAsciiStrToIp4_Arg_1_OutputChoice);
            if(*NetLibAsciiStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibAsciiStrToIp4_Arg_1), (VOID *)NetLibAsciiStrToIp4_Arg_1);
            }
            Status = NetLibAsciiStrToIp4(
                NetLibAsciiStrToIp4_Arg_0,
                NetLibAsciiStrToIp4_Arg_1
            );
    
            break;
        }
        case 2:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * HttpDns4_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 HttpDns4_Arg_1_choice = 0;
            ReadBytes(Input, sizeof(HttpDns4_Arg_1_choice), (VOID *)&HttpDns4_Arg_1_choice);
            switch(HttpDns4_Arg_1_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(HttpDns4_Arg_1), (VOID *)HttpDns4_Arg_1);
                    break;
                case 1:
                {
                    gBS->FreePool(HttpDns4_Arg_1);
                    HttpDns4_Arg_1 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * HttpDns4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* HttpDns4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(HttpDns4_Arg_2_OutputChoice), (VOID *)HttpDns4_Arg_2_OutputChoice);
            if(*HttpDns4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*HttpDns4_Arg_2), (VOID *)HttpDns4_Arg_2);
            }
            Status = HttpDns4(
                NULL,
                HttpDns4_Arg_1,
                HttpDns4_Arg_2
            );
    
            break;
        }
        case 3:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 StrToIpv4Address_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0_choice), (VOID *)&StrToIpv4Address_Arg_0_choice);
            switch(StrToIpv4Address_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0), (VOID *)StrToIpv4Address_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(StrToIpv4Address_Arg_0);
                    StrToIpv4Address_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            UINT8* StrToIpv4Address_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_1_OutputChoice), (VOID *)StrToIpv4Address_Arg_1_OutputChoice);
            if(*StrToIpv4Address_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_1), (VOID *)StrToIpv4Address_Arg_1);
            }
            EFI_IPv4_ADDRESS * StrToIpv4Address_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* StrToIpv4Address_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_2_OutputChoice), (VOID *)StrToIpv4Address_Arg_2_OutputChoice);
            if(*StrToIpv4Address_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_2), (VOID *)StrToIpv4Address_Arg_2);
            }
            UINT8 * StrToIpv4Address_Arg_3 = AllocateZeroPool(sizeof(UINT8));
            UINT8* StrToIpv4Address_Arg_3_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_3_OutputChoice), (VOID *)StrToIpv4Address_Arg_3_OutputChoice);
            if(*StrToIpv4Address_Arg_3_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_3), (VOID *)StrToIpv4Address_Arg_3);
            }
            StrToIpv4Address(
                StrToIpv4Address_Arg_0,
                (CHAR16 **)&StrToIpv4Address_Arg_1,
                StrToIpv4Address_Arg_2,
                StrToIpv4Address_Arg_3
            );
    
            break;
        }
        case 4:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIp_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIp_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0_choice), (VOID *)&Ip4Config2StrToIp_Arg_0_choice);
            switch(Ip4Config2StrToIp_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0), (VOID *)Ip4Config2StrToIp_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIp_Arg_0);
                    Ip4Config2StrToIp_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIp_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIp_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIp_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIp_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIp_Arg_1), (VOID *)Ip4Config2StrToIp_Arg_1);
            }
            Status = Ip4Config2StrToIp(
                Ip4Config2StrToIp_Arg_0,
                Ip4Config2StrToIp_Arg_1
            );
    
            break;
        }
        case 5:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIpList_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIpList_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0_choice), (VOID *)&Ip4Config2StrToIpList_Arg_0_choice);
            switch(Ip4Config2StrToIpList_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0), (VOID *)Ip4Config2StrToIpList_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIpList_Arg_0);
                    Ip4Config2StrToIpList_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIpList_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIpList_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_1), (VOID *)Ip4Config2StrToIpList_Arg_1);
            }
            UINTN * Ip4Config2StrToIpList_Arg_2 = AllocateZeroPool(sizeof(UINTN));
            UINT8* Ip4Config2StrToIpList_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_2_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_2_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_2), (VOID *)Ip4Config2StrToIpList_Arg_2);
            }
            Status = Ip4Config2StrToIpList(
                Ip4Config2StrToIpList_Arg_0,
                (EFI_IPv4_ADDRESS **)&Ip4Config2StrToIpList_Arg_1,
                Ip4Config2StrToIpList_Arg_2
            );
    
            break;
        }
        case 6:
        {
        // Generator Struct Variable Initialization
            /*
                Output Variable(s)
            */
            UINT32 * GetDns4ServerFromDhcp4_Arg_1 = AllocateZeroPool(sizeof(UINT32));
            UINT8* GetDns4ServerFromDhcp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_1_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_1_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_1), (VOID *)GetDns4ServerFromDhcp4_Arg_1);
            }
            EFI_IPv4_ADDRESS * GetDns4ServerFromDhcp4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* GetDns4ServerFromDhcp4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_2_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_2_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_2), (VOID *)GetDns4ServerFromDhcp4_Arg_2);
            }
            Status = GetDns4ServerFromDhcp4(
                NULL,
                GetDns4ServerFromDhcp4_Arg_1,
                (EFI_IPv4_ADDRESS **)&GetDns4ServerFromDhcp4_Arg_2
            );
    
            break;
        }
        case 7:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR8 * HttpUrlGetIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR8));
            UINTN*  HttpUrlGetIp4_Arg_1 = AllocateZeroPool(sizeof(UINTN ));
            
            // Fuzzable Variable Initialization
            UINT8 HttpUrlGetIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(HttpUrlGetIp4_Arg_0_choice), (VOID *)&HttpUrlGetIp4_Arg_0_choice);
            switch(HttpUrlGetIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(HttpUrlGetIp4_Arg_0), (VOID *)HttpUrlGetIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(HttpUrlGetIp4_Arg_0);
                    HttpUrlGetIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            // Fuzzable Variable Initialization
            UINT8 HttpUrlGetIp4_Arg_1_choice = 0;
            ReadBytes(Input, sizeof(HttpUrlGetIp4_Arg_1_choice), (VOID *)&HttpUrlGetIp4_Arg_1_choice);
            switch(HttpUrlGetIp4_Arg_1_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(HttpUrlGetIp4_Arg_1), (VOID *)HttpUrlGetIp4_Arg_1);
                    break;
                case 1:
                {
                    gBS->FreePool(HttpUrlGetIp4_Arg_1);
                    HttpUrlGetIp4_Arg_1 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * HttpUrlGetIp4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* HttpUrlGetIp4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(HttpUrlGetIp4_Arg_2_OutputChoice), (VOID *)HttpUrlGetIp4_Arg_2_OutputChoice);
            if(*HttpUrlGetIp4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*HttpUrlGetIp4_Arg_2), (VOID *)HttpUrlGetIp4_Arg_2);
            }
            Status = HttpUrlGetIp4(
                HttpUrlGetIp4_Arg_0,
                (void *)HttpUrlGetIp4_Arg_1,
                HttpUrlGetIp4_Arg_2
            );
    
            break;
        }
        case 8:
        {
        // Generator Struct Variable Initialization
        ReadBytes(Input, sizeof(UdpWrite_Arg_2->Addr), (VOID *)&(UdpWrite_Arg_2->Addr));
        ReadBytes(Input, sizeof(UdpWrite_Arg_2->v4), (VOID *)&(UdpWrite_Arg_2->v4));
        ReadBytes(Input, sizeof(UdpWrite_Arg_2->v6), (VOID *)&(UdpWrite_Arg_2->v6));
    
            break;
        }
    }
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_3_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_3_choice), (VOID *)&UdpWrite_Arg_3_choice);
    switch(UdpWrite_Arg_3_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_3), (VOID *)UdpWrite_Arg_3);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_3);
            UdpWrite_Arg_3 = NULL;
            break;
        }
    }
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(UdpWrite_Arg_4->Addr), (VOID *)&(UdpWrite_Arg_4->Addr));
    ReadBytes(Input, sizeof(UdpWrite_Arg_4->v4), (VOID *)&(UdpWrite_Arg_4->v4));
    ReadBytes(Input, sizeof(UdpWrite_Arg_4->v6), (VOID *)&(UdpWrite_Arg_4->v6));
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(UdpWrite_Arg_5->Addr), (VOID *)&(UdpWrite_Arg_5->Addr));
    ReadBytes(Input, sizeof(UdpWrite_Arg_5->v4), (VOID *)&(UdpWrite_Arg_5->v4));
    ReadBytes(Input, sizeof(UdpWrite_Arg_5->v6), (VOID *)&(UdpWrite_Arg_5->v6));
    
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_6_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_6_choice), (VOID *)&UdpWrite_Arg_6_choice);
    switch(UdpWrite_Arg_6_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_6), (VOID *)UdpWrite_Arg_6);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_6);
            UdpWrite_Arg_6 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_7_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_7_choice), (VOID *)&UdpWrite_Arg_7_choice);
    switch(UdpWrite_Arg_7_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_7), (VOID *)UdpWrite_Arg_7);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_7);
            UdpWrite_Arg_7 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_8_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_8_choice), (VOID *)&UdpWrite_Arg_8_choice);
    switch(UdpWrite_Arg_8_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_8), (VOID *)UdpWrite_Arg_8);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_8);
            UdpWrite_Arg_8 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_9_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_9_choice), (VOID *)&UdpWrite_Arg_9_choice);
    switch(UdpWrite_Arg_9_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_9), (VOID *)UdpWrite_Arg_9);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_9);
            UdpWrite_Arg_9 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpWrite_Arg_10_choice = 0;
    ReadBytes(Input, sizeof(UdpWrite_Arg_10_choice), (VOID *)&UdpWrite_Arg_10_choice);
    switch(UdpWrite_Arg_10_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpWrite_Arg_10), (VOID *)UdpWrite_Arg_10);
            break;
        case 1:
        {
            gBS->FreePool(UdpWrite_Arg_10);
            UdpWrite_Arg_10 = NULL;
            break;
        }
    }
    
    Status = ProtocolVariable->UdpWrite(
        ProtocolVariable,
        UdpWrite_Arg_1,
        UdpWrite_Arg_2,
        UdpWrite_Arg_3,
        UdpWrite_Arg_4,
        UdpWrite_Arg_5,
        UdpWrite_Arg_6,
        UdpWrite_Arg_7,
        (void *)UdpWrite_Arg_8,
        UdpWrite_Arg_9,
        (void *)UdpWrite_Arg_10
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called UdpRead.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzUdpRead(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    UINT16 UdpRead_Arg_1 = 0;
    EFI_IP_ADDRESS * UdpRead_Arg_2 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_PXE_BASE_CODE_UDP_PORT * UdpRead_Arg_3 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_UDP_PORT));
    EFI_IP_ADDRESS * UdpRead_Arg_4 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_PXE_BASE_CODE_UDP_PORT * UdpRead_Arg_5 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_UDP_PORT));
    UINTN * UdpRead_Arg_6 = AllocateZeroPool(sizeof(UINTN));
    UINTN*  UdpRead_Arg_7 = AllocateZeroPool(sizeof(UINTN ));
    UINTN * UdpRead_Arg_8 = AllocateZeroPool(sizeof(UINTN));
    UINTN*  UdpRead_Arg_9 = AllocateZeroPool(sizeof(UINTN ));
    
    
    UINT8* UdpRead_Arg_1_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(UdpRead_Arg_1_choice), (VOID *)UdpRead_Arg_1_choice);
    switch(*UdpRead_Arg_1_choice % 2) {
        case 0:
        {
        // Constant Variable Initialization
        UdpRead_Arg_1 = EFI_PXE_BASE_CODE_UDP_OPFLAGS_ANY_DEST_IP;
    
            break;
        }
        case 1:
        {
        // Fuzzable Variable Initialization
        ReadBytes(Input, sizeof(UdpRead_Arg_1), (VOID *)&UdpRead_Arg_1);
    
            break;
        }
    }
    // Constant Variable Initialization
    UdpRead_Arg_2 = NULL;
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_3_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_3_choice), (VOID *)&UdpRead_Arg_3_choice);
    switch(UdpRead_Arg_3_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_3), (VOID *)UdpRead_Arg_3);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_3);
            UdpRead_Arg_3 = NULL;
            break;
        }
    }
    
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_5_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_5_choice), (VOID *)&UdpRead_Arg_5_choice);
    switch(UdpRead_Arg_5_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_5), (VOID *)UdpRead_Arg_5);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_5);
            UdpRead_Arg_5 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_6_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_6_choice), (VOID *)&UdpRead_Arg_6_choice);
    switch(UdpRead_Arg_6_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_6), (VOID *)UdpRead_Arg_6);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_6);
            UdpRead_Arg_6 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_7_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_7_choice), (VOID *)&UdpRead_Arg_7_choice);
    switch(UdpRead_Arg_7_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_7), (VOID *)UdpRead_Arg_7);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_7);
            UdpRead_Arg_7 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_8_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_8_choice), (VOID *)&UdpRead_Arg_8_choice);
    switch(UdpRead_Arg_8_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_8), (VOID *)UdpRead_Arg_8);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_8);
            UdpRead_Arg_8 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 UdpRead_Arg_9_choice = 0;
    ReadBytes(Input, sizeof(UdpRead_Arg_9_choice), (VOID *)&UdpRead_Arg_9_choice);
    switch(UdpRead_Arg_9_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(UdpRead_Arg_9), (VOID *)UdpRead_Arg_9);
            break;
        case 1:
        {
            gBS->FreePool(UdpRead_Arg_9);
            UdpRead_Arg_9 = NULL;
            break;
        }
    }
    
    Status = ProtocolVariable->UdpRead(
        ProtocolVariable,
        UdpRead_Arg_1,
        UdpRead_Arg_2,
        UdpRead_Arg_3,
        UdpRead_Arg_4,
        UdpRead_Arg_5,
        UdpRead_Arg_6,
        (void *)UdpRead_Arg_7,
        UdpRead_Arg_8,
        (void *)UdpRead_Arg_9
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called SetIpFilter.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzSetIpFilter(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    
    Status = ProtocolVariable->SetIpFilter(
        ProtocolVariable,
        NULL
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called Start.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzStart(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    BOOLEAN Start_Arg_1 = FALSE;
    
    
    // Fuzzable Variable Initialization
    ReadBytes(Input, sizeof(Start_Arg_1), (VOID *)&Start_Arg_1);
    
    Status = ProtocolVariable->Start(
        ProtocolVariable,
        Start_Arg_1
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called SetStationIp.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzSetStationIp(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    EFI_IP_ADDRESS * SetStationIp_Arg_1 = AllocateZeroPool(sizeof(EFI_IP_ADDRESS));
    EFI_MAC_ADDRESS * SetStationIp_Arg_2 = AllocateZeroPool(sizeof(EFI_MAC_ADDRESS));
    
    
    UINT8* SetStationIp_Arg_1_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(SetStationIp_Arg_1_choice), (VOID *)SetStationIp_Arg_1_choice);
    switch(*SetStationIp_Arg_1_choice % 8) {
        case 0:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * NetLibStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0_choice), (VOID *)&NetLibStrToIp4_Arg_0_choice);
            switch(NetLibStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_0), (VOID *)NetLibStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibStrToIp4_Arg_0);
                    NetLibStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibStrToIp4_Arg_1_OutputChoice);
            if(*NetLibStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibStrToIp4_Arg_1), (VOID *)NetLibStrToIp4_Arg_1);
            }
            Status = NetLibStrToIp4(
                NetLibStrToIp4_Arg_0,
                NetLibStrToIp4_Arg_1
            );
    
            break;
        }
        case 1:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR8 * NetLibAsciiStrToIp4_Arg_0 = AllocateZeroPool(sizeof(CHAR8));
            
            // Fuzzable Variable Initialization
            UINT8 NetLibAsciiStrToIp4_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0_choice), (VOID *)&NetLibAsciiStrToIp4_Arg_0_choice);
            switch(NetLibAsciiStrToIp4_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_0), (VOID *)NetLibAsciiStrToIp4_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(NetLibAsciiStrToIp4_Arg_0);
                    NetLibAsciiStrToIp4_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * NetLibAsciiStrToIp4_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* NetLibAsciiStrToIp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(NetLibAsciiStrToIp4_Arg_1_OutputChoice), (VOID *)NetLibAsciiStrToIp4_Arg_1_OutputChoice);
            if(*NetLibAsciiStrToIp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*NetLibAsciiStrToIp4_Arg_1), (VOID *)NetLibAsciiStrToIp4_Arg_1);
            }
            Status = NetLibAsciiStrToIp4(
                NetLibAsciiStrToIp4_Arg_0,
                NetLibAsciiStrToIp4_Arg_1
            );
    
            break;
        }
        case 2:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * HttpDns4_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 HttpDns4_Arg_1_choice = 0;
            ReadBytes(Input, sizeof(HttpDns4_Arg_1_choice), (VOID *)&HttpDns4_Arg_1_choice);
            switch(HttpDns4_Arg_1_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(HttpDns4_Arg_1), (VOID *)HttpDns4_Arg_1);
                    break;
                case 1:
                {
                    gBS->FreePool(HttpDns4_Arg_1);
                    HttpDns4_Arg_1 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * HttpDns4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* HttpDns4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(HttpDns4_Arg_2_OutputChoice), (VOID *)HttpDns4_Arg_2_OutputChoice);
            if(*HttpDns4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*HttpDns4_Arg_2), (VOID *)HttpDns4_Arg_2);
            }
            Status = HttpDns4(
                NULL,
                HttpDns4_Arg_1,
                HttpDns4_Arg_2
            );
    
            break;
        }
        case 3:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 StrToIpv4Address_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0_choice), (VOID *)&StrToIpv4Address_Arg_0_choice);
            switch(StrToIpv4Address_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(StrToIpv4Address_Arg_0), (VOID *)StrToIpv4Address_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(StrToIpv4Address_Arg_0);
                    StrToIpv4Address_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            CHAR16 * StrToIpv4Address_Arg_1 = AllocateZeroPool(sizeof(CHAR16));
            UINT8* StrToIpv4Address_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_1_OutputChoice), (VOID *)StrToIpv4Address_Arg_1_OutputChoice);
            if(*StrToIpv4Address_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_1), (VOID *)StrToIpv4Address_Arg_1);
            }
            EFI_IPv4_ADDRESS * StrToIpv4Address_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* StrToIpv4Address_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_2_OutputChoice), (VOID *)StrToIpv4Address_Arg_2_OutputChoice);
            if(*StrToIpv4Address_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_2), (VOID *)StrToIpv4Address_Arg_2);
            }
            UINT8 * StrToIpv4Address_Arg_3 = AllocateZeroPool(sizeof(UINT8));
            UINT8* StrToIpv4Address_Arg_3_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(StrToIpv4Address_Arg_3_OutputChoice), (VOID *)StrToIpv4Address_Arg_3_OutputChoice);
            if(*StrToIpv4Address_Arg_3_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*StrToIpv4Address_Arg_3), (VOID *)StrToIpv4Address_Arg_3);
            }
            StrToIpv4Address(
                StrToIpv4Address_Arg_0,
                (CHAR16 **)&StrToIpv4Address_Arg_1,
                StrToIpv4Address_Arg_2,
                StrToIpv4Address_Arg_3
            );
    
            break;
        }
        case 4:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIp_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIp_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0_choice), (VOID *)&Ip4Config2StrToIp_Arg_0_choice);
            switch(Ip4Config2StrToIp_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_0), (VOID *)Ip4Config2StrToIp_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIp_Arg_0);
                    Ip4Config2StrToIp_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIp_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIp_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIp_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIp_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIp_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIp_Arg_1), (VOID *)Ip4Config2StrToIp_Arg_1);
            }
            Status = Ip4Config2StrToIp(
                Ip4Config2StrToIp_Arg_0,
                Ip4Config2StrToIp_Arg_1
            );
    
            break;
        }
        case 5:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            CHAR16 * Ip4Config2StrToIpList_Arg_0 = AllocateZeroPool(sizeof(CHAR16));
            
            // Fuzzable Variable Initialization
            UINT8 Ip4Config2StrToIpList_Arg_0_choice = 0;
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0_choice), (VOID *)&Ip4Config2StrToIpList_Arg_0_choice);
            switch(Ip4Config2StrToIpList_Arg_0_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_0), (VOID *)Ip4Config2StrToIpList_Arg_0);
                    break;
                case 1:
                {
                    gBS->FreePool(Ip4Config2StrToIpList_Arg_0);
                    Ip4Config2StrToIpList_Arg_0 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            EFI_IPv4_ADDRESS * Ip4Config2StrToIpList_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* Ip4Config2StrToIpList_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_1_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_1_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_1), (VOID *)Ip4Config2StrToIpList_Arg_1);
            }
            UINTN * Ip4Config2StrToIpList_Arg_2 = AllocateZeroPool(sizeof(UINTN));
            UINT8* Ip4Config2StrToIpList_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(Ip4Config2StrToIpList_Arg_2_OutputChoice), (VOID *)Ip4Config2StrToIpList_Arg_2_OutputChoice);
            if(*Ip4Config2StrToIpList_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*Ip4Config2StrToIpList_Arg_2), (VOID *)Ip4Config2StrToIpList_Arg_2);
            }
            Status = Ip4Config2StrToIpList(
                Ip4Config2StrToIpList_Arg_0,
                (EFI_IPv4_ADDRESS **)&Ip4Config2StrToIpList_Arg_1,
                Ip4Config2StrToIpList_Arg_2
            );
    
            break;
        }
        case 6:
        {
        // Generator Struct Variable Initialization
            /*
                Output Variable(s)
            */
            UINT32 * GetDns4ServerFromDhcp4_Arg_1 = AllocateZeroPool(sizeof(UINT32));
            UINT8* GetDns4ServerFromDhcp4_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_1_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_1_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_1), (VOID *)GetDns4ServerFromDhcp4_Arg_1);
            }
            EFI_IPv4_ADDRESS * GetDns4ServerFromDhcp4_Arg_2 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            UINT8* GetDns4ServerFromDhcp4_Arg_2_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(GetDns4ServerFromDhcp4_Arg_2_OutputChoice), (VOID *)GetDns4ServerFromDhcp4_Arg_2_OutputChoice);
            if(*GetDns4ServerFromDhcp4_Arg_2_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*GetDns4ServerFromDhcp4_Arg_2), (VOID *)GetDns4ServerFromDhcp4_Arg_2);
            }
            Status = GetDns4ServerFromDhcp4(
                NULL,
                GetDns4ServerFromDhcp4_Arg_1,
                (EFI_IPv4_ADDRESS **)&GetDns4ServerFromDhcp4_Arg_2
            );
    
            break;
        }
        case 7:
        {
        // Generator Struct Variable Initialization
        ReadBytes(Input, sizeof(SetStationIp_Arg_1->Addr), (VOID *)&(SetStationIp_Arg_1->Addr));
        ReadBytes(Input, sizeof(SetStationIp_Arg_1->v4), (VOID *)&(SetStationIp_Arg_1->v4));
        ReadBytes(Input, sizeof(SetStationIp_Arg_1->v6), (VOID *)&(SetStationIp_Arg_1->v6));
    
            break;
        }
    }
    UINT8* SetStationIp_Arg_2_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(SetStationIp_Arg_2_choice), (VOID *)SetStationIp_Arg_2_choice);
    switch(*SetStationIp_Arg_2_choice % 5) {
        case 0:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            unsigned int Ip4GetMulticastMac_Arg_1 = 0;
            
            // Fuzzable Variable Initialization
            ReadBytes(Input, sizeof(Ip4GetMulticastMac_Arg_1), (VOID *)&Ip4GetMulticastMac_Arg_1);
            
            Status = Ip4GetMulticastMac(
                NULL,
                Ip4GetMulticastMac_Arg_1,
                SetStationIp_Arg_2
            );
    
            break;
        }
        case 1:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            EFI_IPv6_ADDRESS * Ip6GetMulticastMac_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv6_ADDRESS));
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(Ip6GetMulticastMac_Arg_1->Addr), (VOID *)&(Ip6GetMulticastMac_Arg_1->Addr));
            
            Status = Ip6GetMulticastMac(
                NULL,
                Ip6GetMulticastMac_Arg_1,
                SetStationIp_Arg_2
            );
    
            break;
        }
        case 2:
        {
        // Generator Struct Variable Initialization
            /*
                Input Variable(s)
            */
            EFI_IPv4_ADDRESS * PxeBcCheckArpCache_Arg_1 = AllocateZeroPool(sizeof(EFI_IPv4_ADDRESS));
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(PxeBcCheckArpCache_Arg_1->Addr), (VOID *)&(PxeBcCheckArpCache_Arg_1->Addr));
            
            PxeBcCheckArpCache(
                NULL,
                PxeBcCheckArpCache_Arg_1,
                SetStationIp_Arg_2
            );
    
            break;
        }
        case 3:
        {
        // Generator Struct Variable Initialization
            EFI_SIMPLE_NETWORK_PROTOCOL * ProtocolVariable1 = NULL;
            Status = SystemTable->BootServices->LocateProtocol(&gEfiSimpleNetworkProtocolGuid, NULL, (VOID *)&ProtocolVariable1);
            if (EFI_ERROR(Status)) {
                return Status;
            }
            /*
                Input Variable(s)
            */
            UINTN * EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2 = AllocateZeroPool(sizeof(UINTN));
            
            
            // Fuzzable Variable Initialization
            UINT8 EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2_choice = 0;
            ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2_choice), (VOID *)&EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2_choice);
            switch(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2);
                    break;
                case 1:
                {
                    gBS->FreePool(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2);
                    EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2 = NULL;
                    break;
                }
            }
            
            /*
                Output Variable(s)
            */
            UINTN * EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1 = AllocateZeroPool(sizeof(UINTN));
            UINT8* EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1_OutputChoice), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1_OutputChoice);
            if(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1);
            }
            UINTN*  EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3 = AllocateZeroPool(sizeof(UINTN ));
            UINT8* EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3_OutputChoice), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3_OutputChoice);
            if(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3);
            }
            EFI_MAC_ADDRESS * EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5 = AllocateZeroPool(sizeof(EFI_MAC_ADDRESS));
            UINT8* EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5_OutputChoice), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5_OutputChoice);
            if(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5);
            }
            UINT16 * EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6 = AllocateZeroPool(sizeof(UINT16));
            UINT8* EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6_OutputChoice), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6_OutputChoice);
            if(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6), (VOID *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6);
            }
            Status = ProtocolVariable1->Receive(
                ProtocolVariable1,
                EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_1,
                EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_2,
                (void *)EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_3,
                SetStationIp_Arg_2,
                EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_5,
                EFI_SIMPLE_NETWORK_PROTOCOL_Receive_Arg_6
            );
    
            break;
        }
        case 4:
        {
        // Generator Struct Variable Initialization
        ReadBytes(Input, sizeof(SetStationIp_Arg_2->Addr), (VOID *)&(SetStationIp_Arg_2->Addr));
    
            break;
        }
    }
    Status = ProtocolVariable->SetStationIp(
        ProtocolVariable,
        SetStationIp_Arg_1,
        SetStationIp_Arg_2
    );
    return Status;
}

/*
    This is a harness for fuzzing the protocol service
    called SetPackets.
*/
__attribute__((no_sanitize("address")))
EFI_STATUS
EFIAPI
FuzzSetPackets(
    IN INPUT_BUFFER *Input,
    IN EFI_SYSTEM_TABLE *SystemTable,
    IN EFI_HANDLE *ImageHandle
) {
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_PXE_BASE_CODE_PROTOCOL * ProtocolVariable = NULL;
    Status = SystemTable->BootServices->LocateProtocol(&gEfiPxeBaseCodeProtocolGuid, NULL, (VOID *)&ProtocolVariable);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    /*
        Input Variable(s)
    */
    BOOLEAN * SetPackets_Arg_1 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetPackets_Arg_2 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetPackets_Arg_3 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetPackets_Arg_4 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetPackets_Arg_5 = AllocateZeroPool(sizeof(BOOLEAN));
    BOOLEAN * SetPackets_Arg_6 = AllocateZeroPool(sizeof(BOOLEAN));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_7 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_8 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_9 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_10 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_11 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    EFI_PXE_BASE_CODE_PACKET * SetPackets_Arg_12 = AllocateZeroPool(sizeof(EFI_PXE_BASE_CODE_PACKET));
    
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_1_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_1_choice), (VOID *)&SetPackets_Arg_1_choice);
    switch(SetPackets_Arg_1_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_1), (VOID *)SetPackets_Arg_1);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_1);
            SetPackets_Arg_1 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_2_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_2_choice), (VOID *)&SetPackets_Arg_2_choice);
    switch(SetPackets_Arg_2_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_2), (VOID *)SetPackets_Arg_2);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_2);
            SetPackets_Arg_2 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_3_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_3_choice), (VOID *)&SetPackets_Arg_3_choice);
    switch(SetPackets_Arg_3_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_3), (VOID *)SetPackets_Arg_3);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_3);
            SetPackets_Arg_3 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_4_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_4_choice), (VOID *)&SetPackets_Arg_4_choice);
    switch(SetPackets_Arg_4_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_4), (VOID *)SetPackets_Arg_4);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_4);
            SetPackets_Arg_4 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_5_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_5_choice), (VOID *)&SetPackets_Arg_5_choice);
    switch(SetPackets_Arg_5_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_5), (VOID *)SetPackets_Arg_5);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_5);
            SetPackets_Arg_5 = NULL;
            break;
        }
    }
    
    // Fuzzable Variable Initialization
    UINT8 SetPackets_Arg_6_choice = 0;
    ReadBytes(Input, sizeof(SetPackets_Arg_6_choice), (VOID *)&SetPackets_Arg_6_choice);
    switch(SetPackets_Arg_6_choice % 2) {
        case 0:
            ReadBytes(Input, sizeof(SetPackets_Arg_6), (VOID *)SetPackets_Arg_6);
            break;
        case 1:
        {
            gBS->FreePool(SetPackets_Arg_6);
            SetPackets_Arg_6 = NULL;
            break;
        }
    }
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(SetPackets_Arg_7->Raw), (VOID *)&(SetPackets_Arg_7->Raw));
    ReadBytes(Input, sizeof(SetPackets_Arg_7->Dhcpv4), (VOID *)&(SetPackets_Arg_7->Dhcpv4));
    ReadBytes(Input, sizeof(SetPackets_Arg_7->Dhcpv6), (VOID *)&(SetPackets_Arg_7->Dhcpv6));
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(SetPackets_Arg_8->Raw), (VOID *)&(SetPackets_Arg_8->Raw));
    ReadBytes(Input, sizeof(SetPackets_Arg_8->Dhcpv4), (VOID *)&(SetPackets_Arg_8->Dhcpv4));
    ReadBytes(Input, sizeof(SetPackets_Arg_8->Dhcpv6), (VOID *)&(SetPackets_Arg_8->Dhcpv6));
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(SetPackets_Arg_9->Raw), (VOID *)&(SetPackets_Arg_9->Raw));
    ReadBytes(Input, sizeof(SetPackets_Arg_9->Dhcpv4), (VOID *)&(SetPackets_Arg_9->Dhcpv4));
    ReadBytes(Input, sizeof(SetPackets_Arg_9->Dhcpv6), (VOID *)&(SetPackets_Arg_9->Dhcpv6));
    
    UINT8* SetPackets_Arg_10_choice = AllocateZeroPool(sizeof(UINT8));
    ReadBytes(Input, sizeof(SetPackets_Arg_10_choice), (VOID *)SetPackets_Arg_10_choice);
    switch(*SetPackets_Arg_10_choice % 3) {
        case 0:
        {
        // Generator Struct Variable Initialization
            EFI_MTFTP6_PROTOCOL * ProtocolVariable2 = NULL;
            Status = SystemTable->BootServices->LocateProtocol(&gEfiMtftp6ProtocolGuid, NULL, (VOID *)&ProtocolVariable2);
            if (EFI_ERROR(Status)) {
                return Status;
            }
            /*
                Input Variable(s)
            */
            EFI_MTFTP6_OVERRIDE_DATA * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1 = AllocateZeroPool(sizeof(EFI_MTFTP6_OVERRIDE_DATA));
            UINT8 * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2 = AllocateZeroPool(sizeof(UINT8));
            UINT8 * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3 = AllocateZeroPool(sizeof(UINT8));
            UINT8 EFI_MTFTP6_PROTOCOL_GetInfo_Arg_4 = 0;
            EFI_MTFTP6_OPTION * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5 = AllocateZeroPool(sizeof(EFI_MTFTP6_OPTION));
            
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->ServerIp), (VOID *)&(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->ServerIp));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->ServerPort), (VOID *)&(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->ServerPort));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->TryCount), (VOID *)&(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->TryCount));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->TimeoutValue), (VOID *)&(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1->TimeoutValue));
            
            // Fuzzable Variable Initialization
            UINT8 EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2_choice = 0;
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2_choice), (VOID *)&EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2_choice);
            switch(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2);
                    break;
                case 1:
                {
                    gBS->FreePool(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2);
                    EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2 = NULL;
                    break;
                }
            }
            
            // Fuzzable Variable Initialization
            UINT8 EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3_choice = 0;
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3_choice), (VOID *)&EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3_choice);
            switch(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3);
                    break;
                case 1:
                {
                    gBS->FreePool(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3);
                    EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3 = NULL;
                    break;
                }
            }
            
            // Fuzzable Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_4), (VOID *)&EFI_MTFTP6_PROTOCOL_GetInfo_Arg_4);
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5->OptionStr), (VOID *)(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5->OptionStr));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5->ValueStr), (VOID *)(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5->ValueStr));
            
            /*
                Output Variable(s)
            */
            UINT32 * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6 = AllocateZeroPool(sizeof(UINT32));
            UINT8* EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6_OutputChoice), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6_OutputChoice);
            if(*EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6);
            }
            EFI_MTFTP6_PACKET * EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7 = AllocateZeroPool(sizeof(EFI_MTFTP6_PACKET));
            UINT8* EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7_OutputChoice), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7_OutputChoice);
            if(*EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7), (VOID *)EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7);
            }
            Status = ProtocolVariable2->GetInfo(
                ProtocolVariable2,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_1,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_2,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_3,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_4,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_5,
                EFI_MTFTP6_PROTOCOL_GetInfo_Arg_6,
                (EFI_MTFTP6_PACKET **)&EFI_MTFTP6_PROTOCOL_GetInfo_Arg_7
            );
    
            break;
        }
        case 1:
        {
        // Generator Struct Variable Initialization
            EFI_MTFTP4_PROTOCOL * ProtocolVariable3 = NULL;
            Status = SystemTable->BootServices->LocateProtocol(&gEfiMtftp4ProtocolGuid, NULL, (VOID *)&ProtocolVariable3);
            if (EFI_ERROR(Status)) {
                return Status;
            }
            /*
                Input Variable(s)
            */
            EFI_MTFTP4_OVERRIDE_DATA * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1 = AllocateZeroPool(sizeof(EFI_MTFTP4_OVERRIDE_DATA));
            UINT8 * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2 = AllocateZeroPool(sizeof(UINT8));
            UINT8 * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3 = AllocateZeroPool(sizeof(UINT8));
            UINT8 EFI_MTFTP4_PROTOCOL_GetInfo_Arg_4 = 0;
            EFI_MTFTP4_OPTION * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5 = AllocateZeroPool(sizeof(EFI_MTFTP4_OPTION));
            
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->GatewayIp), (VOID *)&(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->GatewayIp));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->ServerIp), (VOID *)&(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->ServerIp));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->ServerPort), (VOID *)&(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->ServerPort));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->TryCount), (VOID *)&(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->TryCount));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->TimeoutValue), (VOID *)&(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1->TimeoutValue));
            
            // Fuzzable Variable Initialization
            UINT8 EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2_choice = 0;
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2_choice), (VOID *)&EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2_choice);
            switch(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2);
                    break;
                case 1:
                {
                    gBS->FreePool(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2);
                    EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2 = NULL;
                    break;
                }
            }
            
            // Fuzzable Variable Initialization
            UINT8 EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3_choice = 0;
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3_choice), (VOID *)&EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3_choice);
            switch(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3_choice % 2) {
                case 0:
                    ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3);
                    break;
                case 1:
                {
                    gBS->FreePool(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3);
                    EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3 = NULL;
                    break;
                }
            }
            
            // Fuzzable Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_4), (VOID *)&EFI_MTFTP4_PROTOCOL_GetInfo_Arg_4);
            
            // Generator Struct Variable Initialization
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5->OptionStr), (VOID *)(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5->OptionStr));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5->ValueStr), (VOID *)(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5->ValueStr));
            
            /*
                Output Variable(s)
            */
            UINT32 * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6 = AllocateZeroPool(sizeof(UINT32));
            UINT8* EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6_OutputChoice), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6_OutputChoice);
            if(*EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6);
            }
            EFI_MTFTP4_PACKET * EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7 = AllocateZeroPool(sizeof(EFI_MTFTP4_PACKET));
            UINT8* EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7_OutputChoice = AllocateZeroPool(sizeof(UINT8));
            ReadBytes(Input, sizeof(EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7_OutputChoice), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7_OutputChoice);
            if(*EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7_OutputChoice % 2)
            {
                ReadBytes(Input, sizeof(*EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7), (VOID *)EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7);
            }
            Status = ProtocolVariable3->GetInfo(
                ProtocolVariable3,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_1,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_2,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_3,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_4,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_5,
                EFI_MTFTP4_PROTOCOL_GetInfo_Arg_6,
                (EFI_MTFTP4_PACKET **)&EFI_MTFTP4_PROTOCOL_GetInfo_Arg_7
            );
    
            break;
        }
        case 2:
        {
        // Generator Struct Variable Initialization
        ReadBytes(Input, sizeof(SetPackets_Arg_10->Raw), (VOID *)&(SetPackets_Arg_10->Raw));
        ReadBytes(Input, sizeof(SetPackets_Arg_10->Dhcpv4), (VOID *)&(SetPackets_Arg_10->Dhcpv4));
        ReadBytes(Input, sizeof(SetPackets_Arg_10->Dhcpv6), (VOID *)&(SetPackets_Arg_10->Dhcpv6));
    
            break;
        }
    }
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(SetPackets_Arg_11->Raw), (VOID *)&(SetPackets_Arg_11->Raw));
    ReadBytes(Input, sizeof(SetPackets_Arg_11->Dhcpv4), (VOID *)&(SetPackets_Arg_11->Dhcpv4));
    ReadBytes(Input, sizeof(SetPackets_Arg_11->Dhcpv6), (VOID *)&(SetPackets_Arg_11->Dhcpv6));
    
    // Generator Struct Variable Initialization
    ReadBytes(Input, sizeof(SetPackets_Arg_12->Raw), (VOID *)&(SetPackets_Arg_12->Raw));
    ReadBytes(Input, sizeof(SetPackets_Arg_12->Dhcpv4), (VOID *)&(SetPackets_Arg_12->Dhcpv4));
    ReadBytes(Input, sizeof(SetPackets_Arg_12->Dhcpv6), (VOID *)&(SetPackets_Arg_12->Dhcpv6));
    
    Status = ProtocolVariable->SetPackets(
        ProtocolVariable,
        SetPackets_Arg_1,
        SetPackets_Arg_2,
        SetPackets_Arg_3,
        SetPackets_Arg_4,
        SetPackets_Arg_5,
        SetPackets_Arg_6,
        SetPackets_Arg_7,
        SetPackets_Arg_8,
        SetPackets_Arg_9,
        SetPackets_Arg_10,
        SetPackets_Arg_11,
        SetPackets_Arg_12
    );
    return Status;
}

