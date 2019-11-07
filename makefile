objects = simClient.o pkt.o socket.o  dhcp4.o option.o hwaddr.o IPAddress.o

perfDHCP: $(objects)
	g++ -g -o perfDHCP $(objects) -l boost_system

simClient.o: simClient.cpp pkt.h socket.h
	g++ -g -c simClient.cpp
pkt.o: pkt.cpp pkt.h dhcp4.h
	g++ -g -c pkt.cpp
socket.o: socket.cpp socket.h
	g++ -g -c socket.cpp
dhcp4.o: dhcp4.cpp dhcp4.h option.h
	g++ -g -c dhcp4.cpp
option.o: option.cpp dhcp4Def.h option.h
	g++ -g -c option.cpp
hwaddr.o: hwaddr.cpp hwaddr.h
	g++ -g -c hwaddr.cpp
IPAddress.o: IPAddress.cpp IPAddress.h
	g++ -g -c IPAddress.cpp
.PHONY : clean
clean:
	-rm -rf perfDHCP $(objects)
