#include <iostream>
using namespace std;

int GetMaxElement(int arr[], int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

int GetMax(int arr[], int length, int index) {
    // 배열과 길이, 그리고 검색할 index를 인자로 받아서
    // arr[index]보다 큰 값들 중 최솟값의 index를 반환합니다.
    int num = arr[index];   // 기준이 되는 값
    int minGreaterThanNum = 99999999;
    int minGreaterThanNumIndex = -1;

    // cout << "비교 기준 num : " << num << "\n";
    for (int i = index + 1; i < length; i++) {
        // cout << "arr[" << i << "] : " << arr[i] << "\n";
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

    int T;
    cin >> T;
    int max;
    
    int arr[T];

    for (int i = 0; i < T; i++)
        cin >> arr[i];
    
    max = GetMaxElement(arr, T);

    int arr_index[max + 1];
    for (int i = 0; i < max + 1; i++)
        arr_index[i] = -1;
    
    for (int i = 0; i < T; i++) {
        arr_index[arr[i]] = i;
    }

    for (int i = 0; i < T; i++) {
        cout << GetMax(arr_index, max + 1, arr[i]) << " ";
    }

    return 0;
}