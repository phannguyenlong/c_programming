#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *inputData(int size) {
    int *arr = new int[size];
    for (int i=0; i < size; i++) {
        arr[i] = rand() % 20;
    }
    return arr;
}
void outputData(int *arr, int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void insertionSort(int *arr, int size) {
    
}

int main() {
    int size;
    srand(1);

    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];

    arr = inputData(size);
    cout << "Before: ";
    outputData(arr, size);

    cout << "After: ";
}