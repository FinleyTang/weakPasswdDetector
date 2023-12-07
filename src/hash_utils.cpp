//
// Created by ftang on 2023/12/6.
//

#include "hash_utils.h"

#include <iostream>
#include <string>
#include <cstring>
#include <crypt.h>

std::string openssl_md5_hash(const std::string& password) {
    // 使用 crypt 函数进行 MD5 加密
    std::string hashed_password = crypt(password.c_str(), "$1$");
    return hashed_password;
}

std::string openssl_md5_hash_with_salt(const std::string& password, const std::string& salt) {
    // 使用 crypt 函数进行 MD5 加密
    std::string hashed_password = crypt(password.c_str(), ("$1$" + salt).c_str());
    return hashed_password;
}

