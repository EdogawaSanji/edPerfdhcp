#include "hwaddr.h"
#include <iostream>
namespace dhcp{

hwaddr::hwaddr(){
    for (size_t i = 0; i < 6; i++)
        hwaddr_ += HWADDR_SOURCE_NONE;
        //hwaddr_ += 0x08;
    for (size_t i = 6; i < MAX_HWADDR_LEN; i++)
        hwaddr_ += HWADDR_SOURCE_NONE;
}

hwaddr::hwaddr(const hwaddr & source){
    hwaddr_ = source.hwaddr_;
}

hwaddr::hwaddr(const std::string & addr){
    hwaddr_ = addr;
    int hw_size = addr.length();
    if (hw_size > MAX_HWADDR_LEN){
        /*
         *  TODO:ADD throw  
         */
    }
    else {
        for (int i = hw_size; i < MAX_HWADDR_LEN; i++)
            hwaddr_ += HWADDR_SOURCE_NONE;
    }
}

void hwaddr::HwaddrExBang(unsigned int increnum){
    unlong2char templong;
    templong.str[6] = 0x00;
    templong.str[7] = 0x00;
    for(int i = 0; i < 6; i++)
        templong.str[i] = hwaddr_[i];
    templong.value += increnum + 1;
    //std::cout << increnum << " ";

    for (int i = 0; i < 6; i++){
        hwaddr_[5 - i] = templong.str[i];
    }
}

}
