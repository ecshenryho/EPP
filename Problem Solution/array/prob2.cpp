// Array Solutions for ACM EPP Review
// Contact omolazabal@csu.fullerton.edu if you have any questions or concerns.

#include <iostream>
using namespace std;

void InsertMiddle(int*, int&, int*, int);

int main() {
    int arr1[10] = { 1, 2, 3, 4, 5, 6 };
    int arr2[4] = { 20, 21, 22, 23 };
    int size1 = 6;
    int size2 = 4;

    InsertMiddle(arr1, size1, arr2, size2);

    cout << "Array 1: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
}

void InsertMiddle(int* arr1, int &size1, int* arr2, int size2) {

    int middleIndex = (size1 / 2);

    // Shift all elements from the middle position and on x times, where x
    // represents the size of the second array. This makes room to insert the
    // second array.
    for (int i = size1 - 1; i >= middleIndex; i--)
        arr1[i + size2] = arr1[i];

   // Now insert the elements of array 2 into the free spaces of we've created in array 1
    for (int i = 0; i < size2; i++)
        arr1[middleIndex + i] = arr2[i];

    size1 = size1 + size2;  //set new size of array 1

    // Yeah, you can solve this with a single for loop but this method is
    // easier to explain.
}
