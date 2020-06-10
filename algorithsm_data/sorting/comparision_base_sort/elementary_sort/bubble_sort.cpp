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

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) { // this is basic operation
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) 
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
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

    bubbleSort(arr, size);
    cout << "After: ";
    outputData(arr, size);
}