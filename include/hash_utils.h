//
// Created by ftang on 2023/12/6.
//

#ifndef WEAKPASSWDDETECTOR_HASH_UTILS_H
#define WEAKPASSWDDETECTOR_HASH_UTILS_H


#include <string>

std::string openssl_md5_hash(const std::string& password);
std::string openssl_md5_hash_with_salt(const std::string& password, const std::string& salt);


#endif //WEAKPASSWDDETECTOR_HASH_UTILS_H
