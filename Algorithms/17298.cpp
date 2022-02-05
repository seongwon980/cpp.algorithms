#include <iostream>
using namespace std;

int GetMax(int arr[], int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

int GetMax(int arr[], int length, int index) {
    // �迭�� ����, �׸��� �˻��� index�� ���ڷ� �޾Ƽ�
    // arr[index]���� ū ���� �� �ּڰ��� index�� ��ȯ�մϴ�.
    int num = arr[index];   // ������ �Ǵ� ��
    int minGreaterThanNum = 99999999;
    int minGreaterThanNumIndex = -1;

    // cout << "�� ���� num : " << num << "\n";
    for (int i = index + 1; i < length; i++) {
        // cout << "arr[" << i << "] : " << arr[i] << "\n";
        if (arr[i] > num && arr[i] < minGreaterThanNum) {
            minGreaterThanNum = arr[i];
            minGreaterThanNumIndex = i;
        }
    }
    return minGreaterThanNumIndex;
}

int arr_index[1000001];

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;
    
    int arr[T];

    for (int i = 0; i < T; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 1000001; i++)
        arr_index[i] = -1;
    
    for (int i = 0; i < T; i++) {
        arr_index[arr[i]] = i;
    }

    for (int i = 0; i < T; i++) {
        cout << GetMax(arr_index, 1000001, arr[i]) << " ";
    }

    return 0;
}