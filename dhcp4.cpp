#include <iostream>
#include "dhcp4.h"

#define clientIPADDR "10.1.104.31"

namespace dhcp{

dhcp4::dhcp4(uint8_t msg_type, unsigned int increnum){
    op_ = 1;
    htype_ = 1;
    hlen_ = 6;
    hops_ = 0;

    xid_ = increnum;

    secs_ = 0;
    flags_ = 0x0000;

    ciaddr_ = new IPaddress;
    yiaddr_ = new IPaddress;
    siaddr_ = new IPaddress;
    giaddr_ = new IPaddress(clientIPADDR);

    chaddr_ = new hwaddr;
    chaddr_->HwaddrExBang(increnum);

    for (int i = 0; i < MAX_SNAME_LEN; i++){
        sname_[i] = 0x00;
    }
    for (int k = 0; k < MAX_FILE_LEN; k++){
        file_[k] = 0x00;
    }

    deferred_options_ = new option(msg_type);
    //deferred_options_->AddEssentialOption();
    deferred_options_->EndOption();
}
}
