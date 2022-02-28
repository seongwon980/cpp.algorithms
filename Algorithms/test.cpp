#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    char* ref_str;
    char** query;
    int* output;

    int ref_len;
    int* query_len;
    int output_len;

    ref_str = "boatboatboatboatboatboatboatchickenchicchicchicchic";
    string ref_str_string(ref_str);
    int num = 10;
    
    query = new char*[3];
    output = new int[3];

    query[0] = "boat";
    query[1] = "chicken";
    query[2] = "chic";

    for (int i = 0; i < 3; i++)
        cout << query[i] << "\n";

    for (int i = 0; i < 3; i++) {
        int count = 0;
        int pos = ref_str_string.find(query[i], 0);
        while (pos != string::npos) {
            count++;
            pos = ref_str_string.find(query[i], pos + 1);
        }
        
        cout << count << " ";
    }
    return 0;
}