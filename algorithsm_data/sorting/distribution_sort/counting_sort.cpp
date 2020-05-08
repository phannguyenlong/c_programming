#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int * inputData(int size) {
    int *arr = new int[size];
    for (int i=0; i <= size; i++) {
        arr[i] = rand() % 10;
    }
    return arr;
}
void outputData(int *arr, int size) {
    for (int i=0; i < size; i++) cout << arr[i] << "\t";
}

int findMax(int *arr, int size) {
    int max = 0;
    for (int i=0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
void countingSort(int *arr, int size) {
    int max = findMax(arr, size);
    int *f = new int[max];
    int *b = new int[size]; // array to store result
    
    for (int i = 0; i < max; i++) f[i] = 0; // make zero array
    for (int i = 0; i < size; i++) f[arr[i]-1]++; // generating f to count frequnce of element in arr
    for (int i = 1; i < max; i++) f[i] = f[i-1] + f[i]; // f to count how number less than number at position i

    // distribute element to b in sorted order
    for (int i = size - 1; i >= 0; i--) {
        
        b[f[arr[i]-1]-1] = arr[i]; // value of f[a[i]] is position of arr[i] in b
        f[arr[i]-1]--; // reduce 1 for duplicate number
    }
    // copy b to arr
    for (int i = 0; i < size; i++) { arr[i] = b[i]; }

    delete f, b;
}

int main() {
    int * array, size;
    srand(10);
    cout << "Input array size: ";
    cin >> size;
    array = inputData(size);
    
    cout << "Before: ";
    outputData(array, size);

    cout << "\nAfter: ";
    countingSort(array, size);
    outputData(array, size);
}