#ifndef DHCP4_H
#define DHCP4_H

#include <cstddef>
#include <stdint.h>
#include "IPAddress.h"
#include "hwaddr.h"
#include "option.h"

namespace dhcp{

const static size_t MAX_SNAME_LEN = 64;

const static size_t MAX_FILE_LEN = 128;

const static size_t MAX_CHADDR_LEN = 16;

const static uint16_t FLAG_BROADCST_MASK = 0x8000;



class dhcp4{
protected:
/*
 *  DHCP structure from RFC2131
 *  TODO：ip_addr & hwaddr;
 */
    uint8_t op_;
    uint8_t htype_;
    uint8_t hlen_;
    uint8_t hops_;

    uint32_t xid_;

    uint16_t secs_;
    uint16_t flags_;

    IPaddress *ciaddr_;
    IPaddress *yiaddr_;
    IPaddress *siaddr_;
    IPaddress *giaddr_;

    hwaddr *chaddr_;

    option *deferred_options_;



public:

    char sname_[MAX_SNAME_LEN];

    char file_[MAX_FILE_LEN];

    dhcp4(){};

    dhcp4(uint8_t msg_type, unsigned int increnum);

    dhcp4(const uint8_t* data, size_t len);

    ~dhcp4(){
        delete deferred_options_;
        delete chaddr_;
        delete giaddr_;
        delete siaddr_;
        delete yiaddr_;
        delete ciaddr_;
    }

    uint8_t GetOp() const {return op_;};
    void SetOp(uint8_t op) {op_ = op;};

    uint8_t GetHtype() const {return htype_;};
    void SetHtype(uint8_t htype) {htype_ = htype;};

    uint8_t GetHlen() const {return hlen_;};
    void SetHlen(uint8_t hlen) {hlen_ = hlen;};

    uint8_t GetHops() const {return hops_;};

    uint32_t GetXid() const {return xid_;};
    void SetXid(uint32_t xid) {xid_ = xid;};
    
    uint16_t GetSecs() const {return secs_;};


    void SetFlags(uint16_t flag) {flags_ = flag << 15;};
    uint16_t GetFlags() const {return flags_;};

    const IPaddress & GetCiaddr() const {return *ciaddr_;};
    const uint32_t GetCiaddr32() const {return ciaddr_->GetUint32Address();};
    //void SetCiaddr(const IPaddress *ciaddr) {ciaddr_ = ciaddr;};

    const IPaddress & GetYiaddr() const {return *yiaddr_;};
    const uint32_t GetYiaddr32() const {return yiaddr_->GetUint32Address();};

    const IPaddress & GetSiaddr() const {return *siaddr_;};
    const uint32_t GetSiaddr32() const {return siaddr_->GetUint32Address();};
  
    const IPaddress & GetGiaddr() const {return *giaddr_;};
    const uint32_t GetGiaddr32() const {return giaddr_->GetUint32Address();};

    const std::string GetChaddr() const {return chaddr_->GetHwaddr();};
    void SetChaddr(const std::string & addr);

    const std::string GetDeferredOptions() const {return deferred_options_->GetOption();};
    void AddOption();

};
}
#endif
