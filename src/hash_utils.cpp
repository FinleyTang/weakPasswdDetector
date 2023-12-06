//
// Created by ftang on 2023/12/6.
//

#include "hash_utils.h"

#include <iostream>
#include <openssl/md5.h>
#include <string>

std::string md5(const std::string& input) {
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)input.c_str(), input.length(), result);

    std::string hash;
    char buf[3];
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(buf, "%02x", result[i]);
        hash += buf;
    }

    return hash;
}

std::string saltedMd5(const std::string& input, const std::string& salt) {
    return md5(input + salt);
}