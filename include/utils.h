//
// Created by ftang on 2023/12/6.
//

#ifndef WEAKPASSWDDETECTOR_UTILS_H
#define WEAKPASSWDDETECTOR_UTILS_H
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& str, char delimiter);
std::vector<std::string> read_file(const std::string& filename);

std::string getHashType(const std::string& hash);
#endif //WEAKPASSWDDETECTOR_UTILS_H
