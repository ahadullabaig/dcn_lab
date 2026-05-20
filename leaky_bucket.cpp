#include <iostream>

using namespace std;

int main()
{
    int bucketSize, outputRate, n;

    cout << "Enter bucket size: ";
    cin >> bucketSize;

    cout << "Enter output rate: ";
    cin >> outputRate;
    
    cout << "Enter number of seconds: ";
    cin >> n;

    int bucket = 0;

    for (int i = 1; i <= n; i++)
    {
        int incoming;

        cout << "\nSecond " << i << " - Enter incoming packet size: ";
        cin >> incoming;

        if (bucket + incoming > bucketSize)
        {
            int dropped = (bucket + incoming) - bucketSize;
            
            cout << "Bucket overflow! Dropped " << dropped << " units.\n";
            
            bucket = bucketSize;
        }
        else
        {
            bucket += incoming;
            
            cout << "Added " << incoming << " units to bucket.\n";
        }

        int sent = (bucket >= outputRate) ? outputRate : bucket;

        bucket -= sent;
        
        cout << "Transmitted " << sent << " units.";
        cout << "\nBucket now holds " << bucket << "/" << bucketSize << " units.\n";
    }

    return 0;
}
