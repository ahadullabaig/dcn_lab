#include <iostream>
using namespace std;

int main() {
    int bucketSize, outputRate, n;

    cout << "Enter bucket size: ";
    cin >> bucketSize;
    cout << "Enter output (leak) rate: ";
    cin >> outputRate;
    cout << "Enter number of seconds (packets arriving): ";
    cin >> n;

    int bucket = 0;  // current water (data) in bucket

    for (int i = 1; i <= n; i++) {
        int incoming;
        cout << "\nSecond " << i << " - Enter incoming packet size: ";
        cin >> incoming;

        // Step 1: try to add incoming packet
        if (bucket + incoming > bucketSize) {
            int dropped = (bucket + incoming) - bucketSize;
            cout << "Bucket overflow! Dropped " << dropped << " units.\n";
            bucket = bucketSize;
        } else {
            bucket += incoming;
            cout << "Added " << incoming << " units to bucket.\n";
        }

        // Step 2: leak out at fixed rate
        int sent = (bucket >= outputRate) ? outputRate : bucket;
        bucket -= sent;
        cout << "Transmitted " << sent << " units. Bucket now holds "
             << bucket << "/" << bucketSize << " units.\n";
    }

    return 0;
}
