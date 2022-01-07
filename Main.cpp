#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int COUNT = 9;
    int arr[COUNT];

    for (int i = 0; i < COUNT; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < COUNT; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    
    cout << max << ' ' << maxIndex + 1 << "\n";
    return 0;
}