#include <iostream>
#include "pkt.h"

using namespace dhcp;
using namespace std;

int main(){
    pkt test1(1);
    test1.pack();
    string option_out = test1.pkt_string;
    int len = option_out.length();
    cout << len << endl;
    for (int i = 0; i < len; i++){
	    cout << (int)option_out[i] <<" ";
        if ((i + 1) % 8 == 0)
            cout << endl;
    }
    cout << endl;
}
