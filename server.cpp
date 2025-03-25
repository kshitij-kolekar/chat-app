// server.cpp (Windows Version)
#define _WIN32_WINNT 0x0601
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <algorithm>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

std::vector<SOCKET> clients;
CRITICAL_SECTION clientsLock;

DWORD WINAPI handleClient(LPVOID clientSocket) {
    SOCKET client = *(SOCKET*)clientSocket;
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(client, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cout << "Client disconnected." << std::endl;
            closesocket(client);
            EnterCriticalSection(&clientsLock);
            clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
            LeaveCriticalSection(&clientsLock);
            break;
        }
        std::cout << "Client: " << buffer << std::endl;
        
        // Broadcast message to all clients
        EnterCriticalSection(&clientsLock);
        for (SOCKET sock : clients) {
            if (sock != client) {
                send(sock, buffer, bytesReceived, 0);
            }
        }
        LeaveCriticalSection(&clientsLock);
    }
    return 0;
}

void startServer() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return;
    }
    
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return;
    }
    
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }
    
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }
    
    InitializeCriticalSection(&clientsLock);
    std::cout << "Server is listening on port " << PORT << "..." << std::endl;
    
    while (true) {
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);
        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Failed to accept client" << std::endl;
            continue;
        }
        
        EnterCriticalSection(&clientsLock);
        clients.push_back(clientSocket);
        LeaveCriticalSection(&clientsLock);
        
        std::cout << "New client connected!" << std::endl;
        HANDLE clientThread = CreateThread(NULL, 0, handleClient, &clientSocket, 0, NULL);
        if (clientThread == NULL) {
            std::cerr << "Failed to create client thread." << std::endl;
            closesocket(clientSocket);
        }
    }
    
    closesocket(serverSocket);
    WSACleanup();
}

int main() {
    startServer();
    return 0;
}
