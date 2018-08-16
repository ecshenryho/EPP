// Array Solutions for ACM EPP Review
// Contact omolazabal@csu.fullerton.edu if you have any questions or concerns.

#include <iostream>
using namespace std;

int FindSum(int*, int&);

int main() {

    int arr[7] = { 4, -2, 6, 1, -3, -9, -5 };
    int size = 7;

    cout << "Sum: " << FindSum(arr, size) << endl;

    cout << "New array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

int FindSum(int* arr, int &size) {

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            // If element is negative...
            if (i == size - 1) {
                // Decrement the size if the element is the last element of the array.
                size--;
            }
            else {
                // Else, shift the elements over by 1 to remove the element.
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                i--;
            }
        }
    }

    int sum = 0;
    // Find the sum.
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}
