#include <iostream>
using namespace std;

int main(void) {
    char* ref_str;
    char** query;
    int* output;

    int ref_len;
    int* query_len;
    int output_len;

    ref_str = "boatboatboatboatboatboatboatchickenchicchicchicchic";
    int num = 10;
    int pnum = &num;
    cout << pnum << "\n";
    cout << ref_str << "\n";

    return 0;
}