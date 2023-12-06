//
// Created by ftang on 2023/12/6.
//

#include "../include/asset_discovery.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

bool checkService(const std::string& host, int port) {
    struct sockaddr_in serverAddress;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error opening socket" << std::endl;
        return false;
    }

    server = gethostbyname(host.c_str());
    if (server == nullptr) {
        std::cerr << "No such host" << std::endl;
        return false;
    }

    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        close(sockfd);
        return false;
    }

    close(sockfd);
    return true;
}


std::string executeCommand(const std::string & command){
    std::string result;
    FILE *pipe = popen(command.c_str(),"r");
    if (pipe){
        char buffer[128];
        while (!feof(pipe)){
            if (fgets(buffer,128, pipe)!= nullptr)
                result += buffer;
        }
        pclose(pipe);
    }
    return  result;
}