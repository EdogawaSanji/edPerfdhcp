#include "pkt.h"
#include <arpa/inet.h>
#include "dhcp4.h"

namespace dhcp{

void pkt::uint32Pack(const uint32_t int32num){
    tempInt = int32num;
    IntexStr.val = htonl(tempInt);
    IntexStr.jointStr[4] = '\0';
    
    for (int i = 0; i < 4; i++)
        pkt_string += (char)IntexStr.jointStr[i];
}



pkt::pkt(dhcp4 &dhcp_pkt_){
    pkt_string += dhcp_pkt_.GetOp();
    pkt_string += dhcp_pkt_.GetHtype();
    pkt_string += dhcp_pkt_.GetHlen();
    pkt_string += dhcp_pkt_.GetHops();

    tempInt= dhcp_pkt_.GetXid();
    IntexStr.val = htonl(tempInt);
    IntexStr.jointStr[4] = '\0';
    
    for (int i = 0; i < 4; i++ )
	    pkt_string += (char)IntexStr.jointStr[i];    

    tempShortInt = dhcp_pkt_.GetSecs();
    ShortIntexStr.val = htons(tempShortInt);
    IntexStr.jointStr[2] = '\0';
    
    for (int i = 0; i < 2; i++)
	pkt_string += (char)ShortIntexStr.jointStr[i];
    
    tempShortInt = dhcp_pkt_.GetFlags();
    ShortIntexStr.val = htons(tempShortInt);
    IntexStr.jointStr[2] = '\0';
    
    for (int i = 0; i < 2; i++)
        pkt_string += (char)ShortIntexStr.jointStr[i];

    uint32Pack(dhcp_pkt_.GetCiaddr32());

    uint32Pack(dhcp_pkt_.GetYiaddr32());

    uint32Pack(dhcp_pkt_.GetSiaddr32());

    uint32Pack(dhcp_pkt_.GetGiaddr32());

    pkt_string += dhcp_pkt_.GetChaddr();

    for (int i = 0; i < MAX_SNAME_LEN; i++)
	    pkt_string += dhcp_pkt_.sname_[i];

    for (int i = 0; i < MAX_FILE_LEN; i++)
	    pkt_string += dhcp_pkt_.file_[i];

    pkt_string += dhcp_pkt_.GetDeferredOptions();
}
}
