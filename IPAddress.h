#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <boost/asio/ip/address.hpp>

namespace dhcp{

class IPaddress{
private:
    boost::asio::ip::address asio_address_;
public:
    const static size_t V4ADDRESS_LEN = 4;

    IPaddress();

    IPaddress(const IPaddress & source);
    
    IPaddress(const std::string & address_str);

    IPaddress(const boost::asio::ip::address & asio_address);

    IPaddress(uint32_t v4address);

    static const IPaddress & IPV4_ZERO_ADDRESS(){
        static IPaddress address(0);
        return address;
    }

    static const IPaddress & IPV4_BROADCAST_ADDRESS(){
        static IPaddress address(0XFFFFFFFF);
        return address;
    }

    bool Equals(const IPaddress & other) const{
        return (asio_address_ == other.asio_address_);
    }

    bool IsV4Zero() const{
        return Equals(IPV4_ZERO_ADDRESS());
    }

    bool IsV4Broadcast() const{
        return Equals(IPV4_BROADCAST_ADDRESS());
    }

    uint32_t GetUint32Address() const{
        return (asio_address_.to_v4().to_ulong());
    }
};
}
#endif
