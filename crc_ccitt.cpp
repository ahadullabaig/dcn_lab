#include <iostream>
#include <string>
using namespace std;

// CRC-CCITT generator polynomial: x^16 + x^12 + x^5 + 1
// Binary: 1 0001 0000 0010 0001  (17 bits)
const string GEN = "10001000000100001";

// XOR two equal-length binary strings
string xorStr(const string &a, const string &b) {
    string res = "";
    for (int i = 1; i < (int)a.size(); i++) // skip first bit (always 0)
        res += (a[i] == b[i]) ? '0' : '1';
    return res;
}

// Perform binary division -> returns remainder (CRC)
string crcRemainder(string data, const string &gen) {
    int n = gen.size();
    string tmp = data.substr(0, n);

    for (int i = n; i <= (int)data.size(); i++) {
        if (tmp[0] == '1')
            tmp = xorStr(tmp, gen) + (i < (int)data.size() ? string(1, data[i]) : "");
        else
            tmp = xorStr(tmp, string(n, '0')) + (i < (int)data.size() ? string(1, data[i]) : "");
    }
    return tmp;
}

int main() {
    string data;
    cout << "Enter binary data: ";
    cin >> data;

    // Append 16 zeros (degree of generator = 16)
    string augmented = data + string(16, '0');

    string crc = crcRemainder(augmented, GEN);
    cout << "CRC-CCITT (16-bit) remainder: " << crc << endl;

    string transmitted = data + crc;
    cout << "Transmitted codeword: " << transmitted << endl;

    // --- Receiver side ---
    string received;
    cout << "\nEnter received codeword: ";
    cin >> received;

    string check = crcRemainder(received, GEN);
    bool errorFree = true;
    for (char c : check) if (c == '1') { errorFree = false; break; }

    if (errorFree) cout << "No error detected.\n";
    else cout << "Error detected! Remainder = " << check << endl;

    return 0;
}
