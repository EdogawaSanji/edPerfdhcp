//FINISHED FUNCTION:
//          1. DHCP package
//          2. DHCP send & receive
//          3. DHCP unpack & ouput
//          4. multiple message send(hardware Address increase)NO clientID
//FIXME:
//          sometime this project only generate 3 packets and send, DONOT know why
//TODO:
//          multithreading ,at least two threads, one to send, another to receive and consume
//          this version we add multiple message send to test. but NO ~class(){};
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <map>
#include "pkt.h"
#include "socket.h"
#include "dhcp4Def.h"

#define destIPAddr    "10.1.104.30"
using namespace dhcp;
using namespace std;

void HexStrOut(const char *str, int len){
    for (int i = 0; i < len; i++){
	std::cout << setfill('0') << setw(2);
        std::cout << hex << (unsigned int)(unsigned char)str[i] << " ";
    }
    std::cout << std::endl;
}

void HexOut(const char chr){
    std::cout << setfill('0') << setw(2);
    std::cout << hex << (unsigned int)(unsigned char)chr << std::endl;
}

int main(){
    dhcpsocket clientsock(destIPAddr);
    char send_buffer[1000];
    char recv_buffer[1000];
    map<int , dhcp4 *> dhcpMap;
    
    dhcp4 *dhcp_1;

    for (int num = 0; num <= 15; num ++){
        dhcp_1 = new dhcp4(DHCPDISCOVER, num);
        dhcpMap[num] = dhcp_1;
        pkt test1(*dhcp_1);

        memset(send_buffer, 0, sizeof(send_buffer));

        for (int i = 0; i < test1.pkt_string.length(); i ++){
            send_buffer[i] = test1.pkt_string[i];
        }

        std::cout << "Client sending!\nXID: " << (int)dhcp_1->GetXid() << ", size: " << test1.pkt_string.length() << "!" << std::endl;
        int send_num = clientsock.sendBuffer(send_buffer, test1.pkt_string.length());
        if (send_num < 0){
            printf("Sendto ERROR\n");
            return 0;
        }
        std::cout << "Client Sent: " << send_num << std::endl;
        std::cout << std::endl;
    }

    int n = 16;
    while (n--){ 
        int recv_num = clientsock.recvBuffer(recv_buffer, sizeof(recv_buffer));
        if (recv_num < 0){
            printf("Recvfrom ERROR\n");
            return 0;
        }
        std::cout << "Receive " << dec << recv_num << " bytes." << std::endl;
        unpackHeader *unpack;
        unpack = (unpackHeader *)recv_buffer;

        std::cout << "xid: ";
        HexStrOut((char *)unpack->_xid, 4);
        std::cout << "yiaddr: ";
        HexStrOut((char *)unpack->_yiaddr, 4);
        std::cout << std::endl;
    }

    clientsock.myClose();
    return 0;
}
