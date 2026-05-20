// TCP file client — connects to server, asks for a filename, prints contents.
// Compile: g++ tcp_client.cpp -o tcp_client
// Run    : ./tcp_client

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect"); return 1;
    }

    string filename;
    cout << "Enter filename to request: ";
    cin >> filename;

    send(sock, filename.c_str(), filename.size(), 0);

    char buf[4096];
    cout << "\n--- File contents from server ---\n";
    int bytes;
    while ((bytes = read(sock, buf, sizeof(buf) - 1)) > 0) {
        buf[bytes] = '\0';
        cout << buf;
    }
    cout << "\n--- End ---\n";

    close(sock);
    return 0;
}
