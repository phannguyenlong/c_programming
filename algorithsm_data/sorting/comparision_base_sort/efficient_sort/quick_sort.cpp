#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// handle data
int * inputData(int size) {
    int * arr = new int[size];
    for (int i=0; i < size; i++) {
        arr[i] = rand() % 50;
    }
    return arr;
}
void outputData(int * arr, int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void swap(int &a, int &b) { // pass it by reference
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int left, int right) {
    int i=left+1, j=right;
    int pivot = arr[left];
    do {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        swap(arr[i], arr[j]);
    } while (i < j);
    swap(arr[i], arr[j]); // undo last swap when i > j
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(int * arr, int left, int right) {
    int pivot_pos;
    if (left < right) {
        pivot_pos = partition(arr, left, right);
        quickSort(arr, left, pivot_pos -1);
        quickSort(arr, pivot_pos + 1, right);
    }
}

int main() {
    int * arr, size;
    srand(time(NULL));

    cout << "Input size of array: ";
    cin >> size;
    arr = inputData(size);
    cout << "Before:" << endl;
    outputData(arr,size);

    quickSort(arr, 0, size-1); 
    cout << "After: " << endl;
    outputData(arr, size);   
}
