#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data;

    cout << "Enter data (no spaces): ";
    cin >> data;

    string frame = "XS";

    for (char c : data)
    {
        if (c == 'X') frame += "XX";
        else frame += c;
    }

    frame += "XE";

    cout << "Stuffed frame: " << frame << endl;

    string original = "";

    int i = 2;

    while (i < (int)frame.size() - 2)
    {
        if (frame[i] == 'X' && frame[i+1] == 'X')
        {
            original += 'X';
            i += 2;
        }
        else
        {
            original += frame[i];
            i++;
        }
    }
    
    cout << "Destuffed data: " << original << endl;

    return 0;
}
