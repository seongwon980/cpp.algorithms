#include <iostream>
using namespace std;

int GetMax(int arr[], int length, int index) {
    // 배열과 길이, 그리고 검색할 index를 인자로 받아서
    // arr[index]보다 큰 값들 중 최솟값의 index를 반환합니다.
    int num = arr[index];   // 기준이 되는 값
    int minGreaterThanNum = 99999999;
    int minGreaterThanNumIndex = -1;

    for (int i = index + 1; i < length; i++) {
        if (arr[i] > num && arr[i] < minGreaterThanNum) {
            minGreaterThanNum = arr[i];
            minGreaterThanNumIndex = i;
        }
    }
    return minGreaterThanNumIndex;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cout << "!!!";
    int T;
    cin >> T;

    int arr[T];
    int arr_index[1000001];

    for (int i = 0; i < T; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 1000001; i++)
        arr_index[i] = -1;
    
    for (int i = 0; i < T; i++) {
        arr_index[arr[i]] = i;
        printf("arr_index[%d] = %d\n", arr[i], i);
    }
    return 0;
}