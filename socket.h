#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#define GATE_PORT 67
#define destPort    67
#define clentIP "10.1.104.31"

namespace dhcp{

class dhcpsocket{
private:
    int sock_Cfd;
    sockaddr_in destAddr;
    sockaddr_in clientAddr;

public:
    dhcpsocket(){
        memset(&destAddr, 0, sizeof(destAddr));
        memset(&clientAddr, 0, sizeof(clientAddr));
    }
    
    dhcpsocket(const char *destIP);

    int sendBuffer(const char *send_buf, int len);

    int recvBuffer(char *recv_buf, int len);

    void myClose(){
        close(sock_Cfd);
    }
};
}
