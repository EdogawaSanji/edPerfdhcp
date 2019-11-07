#include "option.h"
#include "dhcp4Def.h"


namespace dhcp{

option::option(){}
    
option::option(uint8_t messageType){
    option_ += 0x63;
    option_ += 0x82;
    option_ += 0x53;
    option_ += 0x63;//add magic cookie

    option_ += DHO_DHCP_MESSAGE_TYPE;
    option_ += 0x01;
    option_ += messageType;
}

option::option(const option & source){
    option_ = source.option_;
}

// void option::AddEssentialOption(){
//     option_ += DHO_DHCP_CLIENT_IDENTIFIER;
//     option_ += 0x0d;
//     option_ += 0x01;
//     option_ += flagStr;

//     srand(time(NULL));
//     for (int i = 0; i < 8; i++)
//         option_ += Random(255);
// }

void option::AddEssentialOption(){
    option_ += DHO_VENDOR_CLASS_IDENTIFIER;
    option_ += 0x04;
    option_ += 'Z';
    option_ += 'D';
    option_ += 'N';
    option_ += 'S';
}

void option::EndOption(){
    option_ += DHO_END;
}

}
