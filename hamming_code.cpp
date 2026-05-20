#include <iostream>

using namespace std;

int main()
{
    int d[5];
    int c[8];

    cout << "Enter 4 data bits (0 or 1): ";

    for (int i = 1; i <= 4; i++) cin >> d[i];

    c[3] = d[1];
    c[5] = d[2];
    c[6] = d[3];
    c[7] = d[4];

    c[1] = c[3] ^ c[5] ^ c[7];
    c[2] = c[3] ^ c[6] ^ c[7];
    c[4] = c[5] ^ c[6] ^ c[7];

    cout << "\nGenerated Hamming code (7 bits): ";

    for (int i = 1; i <= 7; i++) cout << c[i] << " ";

    cout << endl;

    int r[8];

    cout << "\nEnter the received 7 bits: ";

    for (int i = 1; i <= 7; i++) cin >> r[i];

    int p1 = r[1] ^ r[3] ^ r[5] ^ r[7];
    int p2 = r[2] ^ r[3] ^ r[6] ^ r[7];
    int p4 = r[4] ^ r[5] ^ r[6] ^ r[7];

    int errorPos = p1 * 1 + p2 * 2 + p4 * 4;

    if (errorPos == 0)
    {
        cout << "\nNo error detected.\n";
    }
    else
    {
        cout << "\nError detected at bit position " << errorPos << ".";

        r[errorPos] ^= 1;

        cout << "\nCorrected code: ";

        for (int i = 1; i <= 7; i++) cout << r[i] << " ";

        cout << endl;
    }

    return 0;
}
