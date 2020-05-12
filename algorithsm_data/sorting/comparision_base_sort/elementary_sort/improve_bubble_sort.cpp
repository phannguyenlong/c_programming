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

void impBubbleSort(int *arr, int size) {
    bool flag = 1; // flag to notice whether the array is sorted or not to exit the loop ==> prevent unessary loop after
    int i = 0;
    while (flag) {
        flag = false; // flag will be set false at begin of each loop
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]); // this is basic operation
                flag = true; // if there is a swap ==> array not sorted at this loop yet ==> flag = true continue loop
            } // if no swap mean all the list is sorted by loop before ==> flag = false exit loop
        }
        i++;
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

    impBubbleSort(arr, size);
    cout << "After: ";
    outputData(arr, size);
}