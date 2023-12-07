#include <iostream>
#include "include/asset_discovery.h"
#include "include/utils.h"
#include "include/linux_weak_passwd.h"
#include <vector>

bool check_linux_weak_passwd(const std::pair<std::string, std::string> &pair);

int main() {
    std::string host = "localhost";  // 目标主机
    int port = 3306; // 目标端口，比如 MySQL 默认端口为 3306

    if (checkService(host, port)) {
        std::cout << "Service found on " << host << ":" << port << std::endl;
    } else {
        std::cout << "Service not found on " << host << ":" << port << std::endl;
    }

//    std::string command;
//    #ifdef _WIN32
//        command = "tasklist";
//    #else
//        command = "ps -ef";
//    #endif
//
//        std::string output = executeCommand(command);
//        std::cout << output << std::endl;

    auto host_pass = check_linux_weak_passwd();
    std::cout<< host_pass <<std::endl;

    return 0;
}


