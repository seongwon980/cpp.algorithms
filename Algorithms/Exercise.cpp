#include <iostream>
#include <cstring>
using namespace std;


bool IsGroupWord(char* str, int size) {
    bool alphabets[26] = {false,};
    int currentIndex = 0;
    while (currentIndex < size) {
        char currentChar = str[currentIndex];
        alphabets[currentChar - 'a'] = true;        // mark as explored
        
        while (str[currentIndex] == currentChar) currentIndex++;     // skip same letters
        if (currentIndex >= size) return true;      // Reached the end of string

        // Found a new letter
        currentChar = str[currentIndex];
        if (alphabets[currentChar - 'a'])       // Already explored -> not a group
            return false;
    }

    return true;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_of_tc;
    cin >> num_of_tc;
    char input_str[101];
    int size;
    int count = 0;

    for (int i = 0; i < num_of_tc; i++) {
        cin >> input_str;
        size = strlen(input_str);
        if (IsGroupWord(input_str, size))
            count += 1;
    }

    cout << count << endl;
    return 0;
}

