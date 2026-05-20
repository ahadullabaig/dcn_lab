#include <iostream>
using namespace std;

// Hamming(7,4): 4 data bits -> 7-bit codeword
// Bit positions (1-indexed): 1=p1, 2=p2, 3=d1, 4=p4, 5=d2, 6=d3, 7=d4

int main() {
    int d[5]; // d[1]..d[4] = data bits
    int c[8]; // c[1]..c[7] = codeword

    cout << "Enter 4 data bits (d1 d2 d3 d4), each 0 or 1: ";
    for (int i = 1; i <= 4; i++) cin >> d[i];

    // Place data bits at positions 3, 5, 6, 7
    c[3] = d[1];
    c[5] = d[2];
    c[6] = d[3];
    c[7] = d[4];

    // Calculate parity bits (even parity)
    c[1] = c[3] ^ c[5] ^ c[7];   // covers positions 1,3,5,7
    c[2] = c[3] ^ c[6] ^ c[7];   // covers positions 2,3,6,7
    c[4] = c[5] ^ c[6] ^ c[7];   // covers positions 4,5,6,7

    cout << "\nGenerated Hamming code (bit1 -> bit7): ";
    for (int i = 1; i <= 7; i++) cout << c[i] << " ";
    cout << endl;

    // --- Receiver side: simulate possible error ---
    int r[8];
    cout << "\nEnter the received 7 bits (you can flip one to simulate error): ";
    for (int i = 1; i <= 7; i++) cin >> r[i];

    // Recompute parity checks
    int p1 = r[1] ^ r[3] ^ r[5] ^ r[7];
    int p2 = r[2] ^ r[3] ^ r[6] ^ r[7];
    int p4 = r[4] ^ r[5] ^ r[6] ^ r[7];

    // Error position = binary number p4 p2 p1
    int errorPos = p1 * 1 + p2 * 2 + p4 * 4;

    if (errorPos == 0) {
        cout << "No error detected.\n";
    } else {
        cout << "Error detected at bit position " << errorPos << ".\n";
        r[errorPos] ^= 1; // flip the bit to correct
        cout << "Corrected code: ";
        for (int i = 1; i <= 7; i++) cout << r[i] << " ";
        cout << endl;
    }

    return 0;
}
