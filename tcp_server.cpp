// TCP file server — listens on port 8080, sends back contents of requested file.
// Compile: g++ tcp_server.cpp -o tcp_server
// Run    : ./tcp_server

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

#define PORT 8080

int main() {
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) { perror("socket"); return 1; }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(serverFd, (sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); return 1; }
    if (listen(serverFd, 5) < 0) { perror("listen"); return 1; }

    cout << "Server listening on port " << PORT << "...\n";

    while (true) {
        sockaddr_in client{};
        socklen_t len = sizeof(client);
        int clientFd = accept(serverFd, (sockaddr*)&client, &len);
        if (clientFd < 0) { perror("accept"); continue; }

        char buf[1024] = {0};
        read(clientFd, buf, sizeof(buf) - 1);
        string filename(buf);
        // strip trailing newline/whitespace
        while (!filename.empty() && (filename.back() == '\n' || filename.back() == '\r' || filename.back() == ' '))
            filename.pop_back();

        cout << "Client requested: '" << filename << "'\n";

        ifstream fin(filename);
        string response;
        if (!fin) {
            response = "ERROR: File '" + filename + "' not found on server.\n";
        } else {
            stringstream ss;
            ss << fin.rdbuf();
            response = ss.str();
        }
        send(clientFd, response.c_str(), response.size(), 0);
        close(clientFd);
        cout << "Response sent.\n\n";
    }

    close(serverFd);
    return 0;
}
