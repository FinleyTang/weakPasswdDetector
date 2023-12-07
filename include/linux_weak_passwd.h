//
// Created by ftang on 2023/12/6.
//

#ifndef WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
#define WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
#include <utility>
#include <string>
#include <vector>
std::pair<std::string,std::string> get_name_and_hashInfo(const std::string &shadow_line);
std::vector<std::string> get_linux_shadow_info();
bool check_linux_one_pair_weak_passwd(const std::pair<std::string, std::string> &name_and_hash_info);
bool check_linux_weak_passwd();

#endif //WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
