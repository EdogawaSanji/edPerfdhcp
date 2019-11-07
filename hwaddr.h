#ifndef HWADDR_H
#define HWADDR_H


#include <string>
#include <stdint.h>

namespace dhcp{
    
union unlong2char{
    char str[8];
    unsigned long value;
};

class hwaddr{
/*
 *  HardwareAddress: formed by htype_ & hwaddr_(vector)
 *          for _uint128_t may influence CPU performance
 *  TODO: 不同情形下的构造函数
 *  XXX：htype_是否加入有待商榷
 */
protected:
    std::string hwaddr_;
    

    
public:
    static const size_t MAX_HWADDR_LEN = 16;
    const static char HWADDR_SOURCE_NONE = 0x00;
    const static char HWADDR_SOURCE_BROADCAST = 0xff;
    
    //default constructor
    hwaddr();

    hwaddr(const hwaddr & source);

    //constructor with vector from IOinput etc.
    hwaddr(const std::string & addr);

    void HwaddrExBang(unsigned int increnum);

    const std::string GetHwaddr() const {return hwaddr_;};
};
}
#endif
