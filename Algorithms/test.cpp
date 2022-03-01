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
    
    query = new char*[3];
    query[0] = "boat";
    query[1] = "chicken";
    query[2] = "chic";

    output = new int[3];
    ref_len = sizeof(ref_str);
    
    query_len = new int[3];
    query_len[0] = 4;
    query_len[1] = 7;
    query_len[2] = 4;

    output_len = 3;



    for (int i = 0; i < 3; i++)
        cout << query[i] << "\n";

    return 0;
}