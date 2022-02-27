#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

class MatchMaker {
public:
    MatchMaker(string input_path);
    ~MatchMaker();

    void Match();
    void CheckAnswer(string answer_path);
private:
    char* ref_str;  // Input으로 들어오는 문자열 포인터
    char** query;   // 검색을 할 대상인 문자열 배열
    int* output;    // 검색 결과 int 배열

    int ref_len;
    int* query_len;
    int output_len;
    
    void MakeOutputFile();
};