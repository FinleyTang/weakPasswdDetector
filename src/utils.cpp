//
// Created by ftang on 2023/12/6.
//
#include "../include/utils.h"
#include <string>
#include <vector>

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