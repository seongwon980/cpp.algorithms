#include <iostream>
using namespace std;

void MaxAndMin(int *arr, int size, int **maxPtr, int **minPtr) {
    int *tempMaxPtr;
    int *tempMinPtr;
    int i;

    tempMaxPtr = &arr[0];
    tempMinPtr = &arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *tempMaxPtr)
            tempMaxPtr = &arr[i];
        if (arr[i] < *tempMinPtr)
            tempMinPtr = &arr[i];
    }

    *maxPtr = tempMaxPtr;
    *minPtr = tempMinPtr;
}
int main(void) {
    int *maxPtr;
    int *minPtr;
    int arr[5] = {1, 2, 3, 4, 5};
    MaxAndMin(arr, 5, &maxPtr, &minPtr);
    
    printf("Maximun value : %d\n", *maxPtr);
    printf("Minimum value : %d\n", *minPtr);
    return 0;
}
