#include <iostream>
#include <typeinfo>
#include <string>
#include <stdint.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <pthread.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
//#include <condition_variable> //头文件
#include <mutex>
#include <thread>
#include <chrono>
#include <float.h>
#include <limits.h>
#include <x86intrin.h>
#include <bitset>
#include <bits/stdc++.h>

#pragma pack(4)
using namespace std;

#define setbit(x, y) x |=  ( 1 << y )
#define clrbit(x, y) x &= ~( 1 << y )

class VarLen {
public:
    static int Transform(uint8_t *num, size_t len) {
        if (!num || len <= 0) {
            return -1;
        }

        // prevent overflow ...
        uint8_t filter = (1 << len) - 1;
        uint8_t highBits = filter & (*(num + len - 1) >> (7 - (len - 1)));
        if (highBits != 0) {
            std::cout << "var len overflow ..." << std::endl;
            return -1;
        }

        // calculate varlen ...
        bool isFirst = true;
        for (int32_t i = len - 1; i >= 0; --i) {
            uint8_t filter = (1 << (i + 1)) - 1;
            uint8_t highBits = filter & (*(num + i) >> (7 - i));
            *(num + i) <<= (i + 1);
            *(num + i) >>= 1;
            if (highBits) {
                if (i != (int(len - 1))) {
                    *(num + i + 1) |= highBits;
                }
            }
            if (i != (int(len - 1)) && *(num + i + 1) != 0) {
                isFirst = false;
            }
            if (isFirst == true &&i != (int(len - 1)) && *(num + i + 1) == 0) {
                --len;
            }
        }

        // set flag on last 8 bits ...
        if (len == 0) {
            setbit(*(num), 7);
        } else {
            setbit(*(num + len - 1), 7);
        }
        return len;
    }

    static int16_t Parse(uint8_t* num) {
        if (!num) { return -1; }

        uint8_t maxCircle = 8, curCircle = 0;//prevent excessive circle ...

        uint32_t len = 0;
        uint8_t lowBits = 0;

        //decode varlen to fixedlen ...
        while(!(*(num + len) & 0x80) && curCircle++ < maxCircle) {
            uint8_t filter = (1 << len) - 1;
            lowBits = (*(num + len) & filter) << (8 - len);
            if (lowBits) {
                if (len != 0) {
                    *(num + len - 1) |= lowBits;
                }
            }
            *(num + len) >>= len;
            ++len;
        }

        //clear flag on last bytes ...
        clrbit(*(num + len), 7);

        //decode last bytes...
        uint8_t filter = (1 << len) - 1;
        lowBits = (*(num + len) & filter) << (8 - len);
        if (lowBits) {
            if (len != 0) {
                *(num + len - 1) |= lowBits;
            }
        }
        *(num + len) >>= len;
        ++len;
        return len;
    }};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "./main varlen ." << endl;
        return -1;
    }

    uint32_t num = atoi(argv[1]);

    VarLen vl;
    uint32_t realLen(vl.Transform((uint8_t *)&num, 4));

    /*if (realLen == 1 || realLen == 0) {
        bitset<8> bt(num);
        std::cout << "1. " << bt << std::endl;
    }
    else if (realLen == 2) {
        bitset<16> bt(num);
        std::cout << "2. " << bt << std::endl;
    }
    else if (realLen == 4) {
        bitset<32> bt(num);
        std::cout << "4. " << bt << std::endl;
    }
    else if (realLen == 3) {
        bitset<24> bt(num);
        std::cout << "3. " << bt << std::endl;
    }
    else {
        std::cout << "else : " << realLen << std::endl;
    }*/

    std::cout << "len : " << vl.Parse((uint8_t *)&num) << std::endl;
    cout << "res : " << (uint32_t)num << endl;
    return 0;
}
