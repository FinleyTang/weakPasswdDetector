//
// Created by ftang on 2023/12/6.
//

#ifndef WEAKPASSWDDETECTOR_HASH_UTILS_H
#define WEAKPASSWDDETECTOR_HASH_UTILS_H


#include <string>

std::string md5(const std::string& input);
std::string saltedMd5(const std::string& input, const std::string& salt);

#endif //WEAKPASSWDDETECTOR_HASH_UTILS_H
