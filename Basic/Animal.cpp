#include <stdio.h>

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
    return 0;
}