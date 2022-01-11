#include <iostream>
#include <cstring>
using namespace std;

int Average(double* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int CountGreaterThan(double* arr, int size, double average) {
    /*
        Count the number of elements greater than 'average' and
        return it.
    */
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > average) {
            count += 1;
        }
    }
    return count;
}

int main(void) {
    int num_of_tc;
    int num_of_students;
    int count_above_average;
    double students[1000];
    double sum;
    double average;
    double ratio;

    cin >> num_of_tc;
    for (int i = 0; i < num_of_tc; i++) {
        cin >> num_of_students;
        for (int j = 0; j < num_of_students; j++) {
            cin >> students[j];
        }
        average = Average(students, num_of_students);
        // cout << "average: " << average << endl;
        count_above_average = CountGreaterThan(students, num_of_students, average);
        // cout << "count_above_average: " << count_above_average << endl;
        ratio = 100 * (double)count_above_average / (double)num_of_students;

        // Set cout precision and print the result

        cout << fixed;
        cout.precision(3);
        cout << ratio << "%" << endl;
    }


    return 0;
}