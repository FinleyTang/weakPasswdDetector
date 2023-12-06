#include <iostream>
#include "include/asset_discovery.h"
#include "include/utils.h"
#include "include/linux_weak_passwd.h"
#include <vector>
int main() {
    std::string host = "localhost";  // 目标主机
    int port = 3306; // 目标端口，比如 MySQL 默认端口为 3306

    if (checkService(host, port)) {
        std::cout << "Service found on " << host << ":" << port << std::endl;
    } else {
        std::cout << "Service not found on " << host << ":" << port << std::endl;
    }

    std::string command;
    #ifdef _WIN32
        command = "tasklist";
    #else
        command = "ps -ef";
    #endif

        std::string output = executeCommand(command);
        std::cout << output << std::endl;


//    std::string shadowLine = "ubuntu:$1$ZMdduAeH$iyAykWUp4aDadw6I0VNek0:19675:0:99999:7:::"; //changed
//
//    // 使用分割函数将字符串分割成字段
//    std::vector<std::string> fields = splitString(shadowLine, ':');
//
//    // 输出各个字段值
//    std::cout << "Username: " << fields[0] << std::endl;
//    std::cout << "Encrypted Password: " << fields[1] << std::endl;
    std::vector<std::pair<std::string, std::string>>   host_pass = get_linux_weak_passwd();


    return 0;
}
