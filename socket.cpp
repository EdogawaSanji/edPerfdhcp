#include "socket.h"


namespace dhcp{

dhcpsocket::dhcpsocket(const char *destIP){
    sock_Cfd = socket(AF_INET, SOCK_DGRAM, 0);
    destAddr.sin_family = AF_INET;
    destAddr.sin_addr.s_addr = inet_addr(destIP);
    destAddr.sin_port = htons(destPort);
    
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    clientAddr.sin_port = htons(GATE_PORT);

    int opt = 1;
    if (setsockopt(sock_Cfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
    	//std::cout << "!!!" << std::endl;
    };
    int bind_num;
    if ((bind_num = bind(sock_Cfd, (sockaddr*) &clientAddr, sizeof(clientAddr))) < 0){
        /*TODO: throw*/
    }
    //std::cout << "BOUND: " << bind_num  << std::endl;
}

int dhcpsocket::sendBuffer(const char *send_buf, int len){
    int send_num = sendto(sock_Cfd, send_buf, len, 0, (sockaddr *)&destAddr, sizeof(destAddr));
    return send_num;
}

int dhcpsocket::recvBuffer(char *recv_buf, int len){
    int addrLen = sizeof(destAddr);
    int recv_num = recvfrom(sock_Cfd, recv_buf, len, 0, (sockaddr *)&destAddr, (socklen_t *)&addrLen);
    return recv_num;
}
}
