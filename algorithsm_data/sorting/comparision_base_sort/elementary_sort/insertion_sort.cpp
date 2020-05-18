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
  for (int i= 1; i < size; i++ ) {
    int insert_element = arr[i];
    int j = i - 1; // index to search in sorted part;
    while (j >= 0  && arr[j] > insert_element) {
      arr[j+1] = arr[j]; // move the list
      j--;
    } 
    arr[j + 1] = insert_element;
  }
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

    insertionSort(arr, size);
    cout << "After: ";
    outputData(arr, size);
}
