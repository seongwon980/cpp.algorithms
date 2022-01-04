#include <iostream>
using namespace std;

<<<<<<< HEAD
void printArray(int* pArr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", pArr[i]);
    }
}
int main(void) {
    const char *arr[3] = {"Hello", "Why?", "GOGO"};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }
=======
int main(void) {
    cout << "Hello!!"<<endl;
>>>>>>> cf8c225be1e31ab43aaa5b5af9ac10001f2712ed
    return 0;
}