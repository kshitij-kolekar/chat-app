// client.cpp (Windows Version)
#define _WIN32_WINNT 0x0601
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

DWORD WINAPI receiveMessages(LPVOID sockParam) {
    SOCKET sock = *(SOCKET*)sockParam;
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cout << "Connection closed or error occurred." << std::endl;
            break;
        }
        std::cout << "Friend: " << buffer << std::endl;
    }
    return 0;
}

void startClient(const std::string& serverIP) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation error" << std::endl;
        WSACleanup();
        return;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    serv_addr.sin_addr.s_addr = inet_addr(serverIP.c_str());
    if (serv_addr.sin_addr.s_addr == INADDR_NONE) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    std::cout << "Connected to server!" << std::endl;
    HANDLE recvThread = CreateThread(NULL, 0, receiveMessages, &sock, 0, NULL);
    if (recvThread == NULL) {
        std::cerr << "Failed to create receive thread." << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    char buffer[BUFFER_SIZE];
    while (true) {
        std::cin.getline(buffer, BUFFER_SIZE);
        send(sock, buffer, strlen(buffer), 0);
    }
    closesocket(sock);
    WSACleanup();
}

int main() {
    std::string serverIP;
    std::cout << "Enter server IP: ";
    std::cin >> serverIP;
    std::cin.ignore();
    startClient(serverIP);
    return 0;
}
