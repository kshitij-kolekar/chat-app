# 💬 Terminal-Based Chat Application (C++)

A real-time chat application implemented in C++ using socket programming.  
Developed by **Kshitij**.

---

## 📝 Project Overview

This is a **terminal-based real-time chat application** built in C++, using low-level socket programming. The application allows multiple clients to connect to a central server and exchange messages simultaneously, demonstrating core concepts of **networking**, **concurrency**, and **inter-process communication**.

It was designed to gain a deeper understanding of how real-time communication works at the protocol level — without relying on high-level frameworks.

---

## 🎯 Objectives

- Gain hands-on experience with TCP/IP socket programming  
- Implement server-client architecture from scratch  
- Understand and manage multi-threaded communication  
- Build a minimal yet functional text-based chat interface  

---

## 🧱 Features

- **Multi-client Support**  
  Handles multiple clients simultaneously using `std::thread` or `select()`/`poll()`  

- **Real-Time Messaging**  
  Messages are relayed to all connected clients in real-time  

- **Clean Terminal Interface**  
  Simple and intuitive CLI for sending and receiving messages  

- **Graceful Disconnection Handling**  
  Clients can exit without crashing the server or other clients  

- **Cross-Platform (POSIX-based)**  
  Works on Linux and other Unix-like systems  

---

## 🛠️ Technologies Used

- **C++** (C++11 or higher)  
- **POSIX Sockets** (BSD Sockets API)  
- **Pthreads / `std::thread`** (for concurrency)  
- **Makefile** (for easy compilation)  

---

## 📦 Directory Structure

```
chat-app/
├── server.cpp        # Chat server implementation
├── client.cpp        # Chat client implementation
└── README.md
```

---

## 🚀 Getting Started

### 🧰 Requirements

- GCC / G++ (with C++11 or higher)  
- Unix-like OS (Linux, macOS, WSL, etc.)  

---

### 🔧 Compilation

```bash
make
```

This will compile both the `server` and `client` binaries.

---

### ✅ Running the Server

```bash
./server <PORT>
```

**Example:**

```bash
./server 8080
```

---

### 🗨️ Running a Client

In a separate terminal:

```bash
./client <SERVER_IP> <PORT>
```

**Example:**

```bash
./client 127.0.0.1 8080
```

---

## 🧪 Sample Use Case

1. Open **1 terminal** for the server  
2. Open **2 or more terminals** for clients  
3. Test sending messages between them in real-time  

---

## 🔐 Notes

- This is a **basic synchronous chat** demo.  
- **No encryption** is used — for production, add TLS (OpenSSL).  
- For IPv6 or UDP support, code modifications are needed.  

---

## 📈 Potential Enhancements

- Add a GUI frontend using **ncurses** or **Qt**  
- Implement **private messaging** or **chat rooms**  
- Add **usernames and authentication**  
- Include **message timestamps** and logging  
- Add **end-to-end encryption** with OpenSSL  

---

## 👤 Author

**Kshitij**  
Systems enthusiast with a passion for low-level programming, networks, and building things from scratch.

---

## 📃 License

This project is **not currently licensed**.  
Feel free to explore the code, but please **don’t reuse or distribute it without permission**.
