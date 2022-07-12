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
    query_len = new int[3];
    query[0] = 4;
    query[1] = 7;
    query[2] = 4;
    
    query[0] = "boat";
    query[1] = "chicken";
    query[2] = "chic";

    for (int i = 0; i < 3; i++)
        cout << query[i] << "\n";

    for (int i = 0; i < 3; i++) {
        
        
        cout << count << " ";
    }
    return 0;
}