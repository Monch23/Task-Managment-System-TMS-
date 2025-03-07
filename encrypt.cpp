#include <string>
#include <iostream>
#include "encrypt.h"

void decode(const std::string &passwd) {
    std::string tmp{passwd};
    size_t len = passwd.length();
    
    for (int i = 0; i < len / 2; ++i) {
        tmp[i] ^= tmp[len - i - 1];
        tmp[len - 1 - i] ^= tmp[i];
        tmp[i] ^= tmp[len - i - 1];
    }

    for (int i = 0; i < len; ++i) {
        if ( tmp[i] > 64 && tmp[i] < 91 ) {
            tmp[i] -= 23;
        } else {
            tmp[i] += 4;
        }
    }


    std::cout << tmp << std::endl;
}

void encode(std::string &passwd) {
    size_t len = passwd.length();

    for (int i = 0; i < len; ++i) {
        if (passwd[i] > 41 && passwd[i] < 91 ) {
            passwd[i] += 23;
        } else {
            passwd[i] -= 4;
        }
    }

    for (int i = 0; i < len / 2; ++i) {
        passwd[i] ^= passwd[len - i - 1];
        passwd[len - i - 1] ^= passwd[i];
        passwd[i] ^= passwd[len - i - 1];
    }
}