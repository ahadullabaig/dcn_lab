#include <iostream>
#include <string>
using namespace std;

// Character stuffing:
// Frame is delimited by DLE STX ... DLE ETX
// Any DLE inside the payload is escaped by inserting another DLE.
// Here we use: DLE='X', STX='S', ETX='E' for simplicity.

int main() {
    string data;
    cout << "Enter data (no spaces): ";
    cin >> data;

    // ---- Stuffing (sender side) ----
    string frame = "XS"; // DLE STX
    for (char c : data) {
        if (c == 'X') frame += "XX"; // escape DLE
        else frame += c;
    }
    frame += "XE"; // DLE ETX

    cout << "Stuffed frame: " << frame << endl;

    // ---- Destuffing (receiver side) ----
    string original = "";
    int i = 2; // skip starting DLE STX
    while (i < (int)frame.size() - 2) { // stop before DLE ETX
        if (frame[i] == 'X' && frame[i+1] == 'X') {
            original += 'X';
            i += 2;
        } else {
            original += frame[i];
            i++;
        }
    }
    cout << "Destuffed data: " << original << endl;

    return 0;
}
