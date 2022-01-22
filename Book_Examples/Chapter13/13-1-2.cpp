#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len) {
    T sum = (T)0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

