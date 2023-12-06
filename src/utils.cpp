//
// Created by ftang on 2023/12/6.
//
#include "../include/utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// 函数用于将字符串按照指定分隔符进行分割，返回分割后的字符串向量
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string temp;
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    result.push_back(temp);
    return result;
}


std::vector<std::string> read_file(const std::string& filename) {
    std::vector<std::string> result;
    // 打开文件
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        // 逐行读取文件内容
        while (std::getline(file, line)) {
//            std::cout << line << std::endl;
            result.push_back(line);
        }
        // 关闭文件
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return  result;
}

std::string getHashType(const std::string& hash)
{
    if (hash == "$1$")
        return "MD5";
    else if (hash == "$5$")
        return "SHA-256";
    else if (hash == "$6$")
        return "SHA-512";
    else
        return "Unknown";
}