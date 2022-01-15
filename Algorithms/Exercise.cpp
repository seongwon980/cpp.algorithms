#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char input_str[101];
    cin >> input_str;
    int size = strlen(input_str);
    int count = 0;

    for (int i = 0; i < size; i++) {
        count += 1;
        if (input_str[i] == 'c') {
            // 'c=' or 'c-'
            if (input_str[i + 1] == '=' || input_str[i + 1] == '-')
                i += 1;
        } else if (input_str[i] == 'd') {
            // 'dz=' or 'd-'
            if (i <= size - 2 && input_str[i + 1] == 'z' && input_str[i + 2] == '=')
                i += 2;
            else if (i <= size - 1 && input_str[i + 1] == '-')
                i += 1;
        }  else if (input_str[i])
    }
}