#include "IPAddress.h"

namespace dhcp{

IPaddress::IPaddress(){
    asio_address_ = boost::asio::ip::address_v4(0);
    //asio_address_ = boost::asio::ip::address_v4(6);
}

IPaddress::IPaddress(const IPaddress & source){
    asio_address_ = source.asio_address_;
}
IPaddress::IPaddress(const std::string & address_str){
    asio_address_ = boost::asio::ip::address::from_string(address_str);
    /*
     *  TODO: throw 
     */
}

IPaddress::IPaddress(const boost::asio::ip::address & asio_address){
    asio_address_ = asio_address;
}

IPaddress::IPaddress(uint32_t v4address):
    asio_address_(boost::asio::ip::address_v4(v4address)){

}
}
