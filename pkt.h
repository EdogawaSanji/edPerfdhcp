#include <iostream>
#include "dhcp4.h"

namespace dhcp{

union Int2Str{
    uint32_t val;
    char jointStr[5];
};

union ShortInt2Str{
    uint16_t val;
    char jointStr[3];
};

class pkt{
public:

    Int2Str IntexStr;
    uint32_t tempInt;
    ShortInt2Str ShortIntexStr;
    uint16_t tempShortInt;

    std::string pkt_string;

    pkt(){};

    pkt(dhcp4 &dhcp_pkt_);

    void uint32Pack(const uint32_t int32num);

};

struct unpackHeader{
    uint8_t _op;
    uint8_t _htype;
    uint8_t _hlen;
    uint8_t _hops;

    uint8_t _xid[4];

    uint8_t _secs[2];
    uint8_t _flags[2];

    uint8_t _ciaddr[4];
    uint8_t _yiaddr[4];
    uint8_t _siaddr[4];
    uint8_t _giaddr[4];

    uint8_t _chaddr[16];

    uint8_t _sname[64];

    uint8_t _file[128];
};
}
