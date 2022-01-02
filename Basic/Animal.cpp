#include <stdio.h>

int main(void)
{
    int arr[3] = {1, 2, 3};
    printf("arr : %p\n", arr);
    printf("arr[0] : %p\n", &arr[0]);
    
    return 0;
}