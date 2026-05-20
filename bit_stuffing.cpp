#include <iostream>
#include <string>
using namespace std;

// Bit stuffing:
// Whenever sender sees 5 consecutive 1's in the data,
// it inserts a 0 right after them so the bit pattern
// can never be confused with the frame delimiter 01111110.

int main() {
    string bits;
    cout << "Enter bit string (0s and 1s): ";
    cin >> bits;

    // ---- Stuffing ----
    string stuffed = "";
    int count = 0;
    for (char b : bits) {
        stuffed += b;
        if (b == '1') {
            count++;
            if (count == 5) {
                stuffed += '0'; // stuff a 0
                count = 0;
            }
        } else count = 0;
    }
    cout << "Stuffed bits:   " << stuffed << endl;

    // ---- Destuffing ----
    string destuffed = "";
    count = 0;
    for (int i = 0; i < (int)stuffed.size(); i++) {
        destuffed += stuffed[i];
        if (stuffed[i] == '1') {
            count++;
            if (count == 5) {
                i++; // skip the stuffed 0
                count = 0;
            }
        } else count = 0;
    }
    cout << "Destuffed bits: " << destuffed << endl;

    return 0;
}
