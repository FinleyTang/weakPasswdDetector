//
// Created by ftang on 2023/12/6.
//

#include "linux_weak_passwd.h"
#include "hash_utils.h"
#include "utils.h"
#include <string>
#include <utility>
#include <iostream>

std::vector<std::string> get_linux_shadow_info(){
    std::string pass_file = "/etc/shadow";
    std::vector<std::string> shadow_info = read_file(pass_file);
    return  shadow_info;
}

std::pair<std::string,std::string> get_name_and_hashInfo(const std::string &shadow_line ){
    std::pair<std::string, std::string> name_and_hashInfo;
    auto shadow_line_info = splitString(shadow_line, ':');
    auto name = shadow_line_info[0];

    if(shadow_line_info[1].at(0) =='$'){
        auto hash_info = shadow_line_info[1];
        name_and_hashInfo.first = name;
        name_and_hashInfo.second = hash_info;
    }
//
//    }
    return name_and_hashInfo;
}

//std::hash<std::string, std::pair<std::string, string> get_hash_


bool check_linux_one_pair_weak_passwd(const std::pair<std::string, std::string> &name_and_hash_info) {

    std::pair<std::string, std::string> result;
    std::cout << name_and_hash_info.first<< std::endl;
    std::cout << name_and_hash_info.second<< std::endl;
    std::string name = name_and_hash_info.first;
    std::string hash_info = name_and_hash_info.second;

    std::string hash_type_num = hash_info.substr(0,3);
    std::string salt_hash_info = hash_info.substr(2, hash_info.length());

    auto  salt_and_hash = splitString(salt_hash_info,'$');
    auto salt = salt_and_hash[1];
    auto hash = salt_and_hash[2];
    auto dict_content = read_file("../dict/simple");
    for (auto item: dict_content) {
        auto hashed_passwd = openssl_md5_hash_with_salt(item, salt);
        std::cout << item << "hashed: " <<hashed_passwd <<std::endl;
        if (hashed_passwd == hash_info){
            std::cout << hashed_passwd << " is weak passwd" <<std::endl;
            return true;
        }
    }

    return false;
}


bool check_linux_weak_passwd() {
    auto shadow_info = get_linux_shadow_info();
    for (auto shadow_line: shadow_info) {
        auto name_and_hash_info = get_name_and_hashInfo(shadow_line);
        if(!name_and_hash_info.second.empty()){
            bool isWeak = check_linux_one_pair_weak_passwd(name_and_hash_info);
            std::cout << isWeak <<std::endl;
        }

    }
    return true;
}
