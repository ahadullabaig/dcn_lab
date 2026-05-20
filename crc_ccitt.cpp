#include <iostream>
#include <string>

using namespace std;

const string GEN = "10001000000100001"; 

string getRemainder(string data, string gen)
{
    int genLen = gen.length();
    
    for (int i = 0; i <= data.length() - genLen; i++)
    {    
        if (data[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                data[i + j] = (data[i + j] == gen[j]) ? '0' : '1';
            }
        }
    }
    
    return data.substr(data.length() - 16);
}

int main()
{
    string data;

    cout << "Enter binary data: ";
    cin >> data;

    string augmented = data + string(16, '0');

    string crc = getRemainder(augmented, GEN);

    cout << "\nCRC-CCITT (16-bit) remainder: " << crc << endl;

    string transmitted = data + crc;

    cout << "Transmitted codeword: " << transmitted << endl;

    string received;

    cout << "\nEnter received codeword: ";
    cin >> received;

    string check = getRemainder(received, GEN);

    if (check == string(16, '0'))
    {
        cout << "\nNo error detected.\n";
    }
    else
    {
        cout << "\nError detected! Remainder = " << check << endl;
    }

    return 0;
}
