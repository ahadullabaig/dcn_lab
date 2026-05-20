#include <iostream>
#include <string>

using namespace std;

int main()
{
    string bits;

    cout << "Enter bit string (0s and 1s): ";
    cin >> bits;

    string stuffed = "";

    int count = 0;

    for (char b : bits)
    {
        stuffed += b;
    
        if (b == '1')
        {
            count++;
        
            if (count == 5)
            {
                stuffed += '0';
                count = 0;
            }
        }
        else count = 0;
    }

    cout << "Stuffed bits:   " << stuffed << endl;

    string destuffed = "";

    count = 0;

    for (int i = 0; i < (int)stuffed.size(); i++)
    {
        destuffed += stuffed[i];
    
        if (stuffed[i] == '1')
        {
            count++;
        
            if (count == 5)
            {
                i++;
                count = 0;
            }
        }
        else count = 0;
    }
    
    cout << "Destuffed bits: " << destuffed << endl;

    return 0;
}
