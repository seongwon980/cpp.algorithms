#include "mm.h"

using namespace std;

MatchMaker::MatchMaker(string input_path) {
    ifstream i_f(input_path);
    string line;

    if (i_f.is_open()) {
        getline(i_f, line);     // 한 줄을 읽어서 string line에 저장
        ref_len = line.length();    
        ref_str = new char[ref_len];    // 읽은 line의 길이만큼의 char 배열을 생성
        strcpy(ref_str, line.c_str());     // line을 ref_str에 복사

        int i = 0;
        getline(i_f, line);
        output_len = stoi(line);    // Query를 할 단어의 수를 입력
        query = new char*[output_len];   // char형 포인터 배열을 생성
        query_len = new int[output_len];
        while (getline(i_f, line)) {
            query_len[i] = line.length();
            query[i] = new char[query_len[i]];
            strcpy(query[i], line.c_str());
            i++;
        }
    }

    output = new int[output_len];
}

MatchMaker::~MatchMaker() {
    delete [] ref_str;
    delete [] output;
    delete [] query_len;
    for (int i = 0; i < output_len; i++)
        delete [] query[i];
    
    delete [] query;
}

void MatchMaker::Match() {
    // TO-DO : Good Luck!
    // WARNING: You must not copy answer from anwer file!
    // Variable Explanation
    //  - ref_str : 1-D char array, reference string is stored in character units
    //  - query : 2-D char array, querys are stored sequencially in character units
    //  - output : 1-D int array, the number of repetitive occurrences of substrings would be stored in query order
    //  - ref_len: int, length of the reference string
    //  - query_len: 1-D int array, an array of lengths of each query string 
    //  - output_len: int, number of queries and also the number of outputs
    // You should store the answer in 'output' vector

    /* Code Start */
    

    /* Code End */    
    
    // Editing is Prohibited
    MakeOutputFile();
}

void MatchMaker::MakeOutputFile() {
    ofstream out("result/output.txt");

    for (int i = 0; i < output_len; i++) {
        out<<output[i]<<" ";
    }

    out.close();
}

void MatchMaker::CheckAnswer(string answer_path) {
    ifstream a_f(answer_path);
    string line, temp;
    vector<int> answer;

    if (a_f.is_open()) {
        getline(a_f, line);
        stringstream ss(line);

        while (getline(ss, temp, ' ')) {
            answer.push_back(stoi(temp));
        }
    }

    for (int i = 0; i < output_len; i++) {
        if (answer[i] != output[i]) {
            cout<<"NON-PASS!"<<endl;
            return;
        }
    }

    cout<<"PASS!"<<endl;
}