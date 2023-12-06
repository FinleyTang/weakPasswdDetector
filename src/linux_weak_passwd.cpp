//
// Created by ftang on 2023/12/6.
//

#include "linux_weak_passwd.h"
#include "hash_utils.h"
#include "utils.h"
#include <string>
#include <utility>
#include <iostream>

std::vector<std::pair<std::string, std::string>> get_linux_weak_passwd(){
    std::vector<std::pair<std::string, std::string>> host_passwd;
    std::string pass_file = "/etc/shadow";

    std::vector<std::string> file_content = read_file(pass_file);
    for (auto shadowLine: file_content) {
        auto shadow_line_info = splitString(shadowLine, ':');
        auto name = shadow_line_info[0];

        if(shadow_line_info[1].at(0) =='$'){
            auto hash_type_num = shadow_line_info[1].substr(0,3);
            auto hashed_pass = shadow_line_info[1].substr(3, shadow_line_info[1].length());
            std::cout<<"hash_type:" << hash_type_num<<"pass:  " <<hashed_pass <<std::endl;
            auto hashType = getHashType(hash_type_num);
            std::cout <<hashType<<std::endl;
            std::pair<std::string, std::string> hash_pair;
            hash_pair.first = hashType;
            hash_pair.second = hashed_pass;
            host_passwd.push_back(hash_pair);
        }

    }
    return  host_passwd;
}


bool check_linux_weak_passwd(const std::pair<std::string, std::string> &pair) {
    std::cout << pair.first << pair.second<< std::endl;
    std::string hash_type = "ZMdduAeH";
    std::string passwd = "test";
    auto hashed_passwd = saltedMd5(passwd, hash_type);
    std::cout << hashed_passwd << std::endl;
    return false;
}