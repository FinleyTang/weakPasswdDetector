//
// Created by ftang on 2023/12/6.
//

#ifndef WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
#define WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
#include <utility>
#include <string>
#include <vector>
std::vector<std::pair<std::string, std::string>>  get_linux_weak_passwd();

bool check_linux_weak_passwd(const std::pair<std::string, std::string> &pair);
#endif //WEAKPASSWDDETECTOR_LINUX_WEAK_PASSWD_H
