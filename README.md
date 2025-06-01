💬 Terminal-Based Chat Application (C++)
A real-time chat application implemented in C++ using socket programming.
Developed by Kshitij.

📝 Project Overview
This is a terminal-based real-time chat application built in C++, using low-level socket programming. The application allows multiple clients to connect to a central server and exchange messages simultaneously, demonstrating core concepts of networking, concurrency, and inter-process communication.

It was designed to gain a deeper understanding of how real-time communication works at the protocol level, without relying on high-level frameworks.

🎯 Objectives
Gain hands-on experience with TCP/IP socket programming

Implement server-client architecture from scratch

Understand and manage multi-threaded communication

Build a minimal yet functional text-based chat interface

🧱 Features
Multi-client Support
Handles multiple clients simultaneously using threads or select()/poll()

Real-Time Messaging
Messages are relayed to all connected clients in real-time

Clean Terminal Interface
Simple and intuitive CLI for sending and receiving messages

Graceful Disconnection Handling
Clients can exit without crashing the server or other connections

Cross-Platform (POSIX-based)
Works on Linux and other Unix-like systems

🛠️ Technologies Used
C++ (C++11 or higher)

POSIX Sockets (BSD Sockets API)

Pthreads / std::thread (for concurrency)

Makefile (for easy compilation)

📦 Directory Structure
bash
Copy
Edit
chat-app/
├── server.cpp        # Chat server implementation
├── client.cpp        # Chat client implementation
└── README.md
🚀 Getting Started
🧰 Requirements
GCC / G++ (C++11+)

Unix-like OS (Linux, macOS, WSL)

🔧 Compilation
bash
Copy
Edit
make
This will compile both server and client binaries.

✅ Running the Server
bash
Copy
Edit
./server <PORT>
Example:

bash
Copy
Edit
./server 8080
🗨️ Running a Client
In a separate terminal:

bash
Copy
Edit
./client <SERVER_IP> <PORT>
Example:

bash
Copy
Edit
./client 127.0.0.1 8080
Now you can start chatting across terminals!

🧪 Sample Use Case
Open 1 terminal for the server

Open 2+ terminals for clients

Test sending messages between them in real-time

🔐 Notes
This is a basic demo of a synchronous chat system.
No encryption is used — for production use, add TLS (OpenSSL).

For IPv6 or UDP support, code adjustments are required.

📈 Potential Enhancements
Add a GUI frontend using ncurses or Qt

Implement private messaging or chat rooms

Add login/usernames and authentication

Message timestamps and logs

End-to-end encryption with OpenSSL

👤 Author
Kshitij
Systems enthusiast with a passion for low-level programming, networks, and building things from scratch.

## 📃 License

This project is not currently licensed.  
Feel free to explore the code, but please don’t reuse or distribute it without permission.
