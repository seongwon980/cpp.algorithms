#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int alphabets[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    
    char input_str[16];
    cin >> input_str;
    int count = 0;

    for (int i = 0; i < strlen(input_str); i++) {
        count += alphabets[input_str[i] - 'A'];
    }

    cout << count;

}