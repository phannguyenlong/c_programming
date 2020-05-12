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

void shakeShort(int *arr, int size) {
    int left = 0, right = size-1;
    bool flag = 1; // set flag base on impBubble sort to skip all don't need loop when array is sorted
    while (left < right && flag) {
        flag = false;
        for (int j = left + 1; j <= right; j++) {
            if (arr[left] > arr[j]) {
                swap(arr[left], arr[j]); // this > is basic operation
                flag = true;
            }
        }
        left++;
        for (int j = right - 1; j >= left; j--) {
            if (arr[right] < arr[j]) {
                swap(arr[right], arr[j]); // this < is  basic operation
                flag = true;
            }
        }
        right--;
    }
}

int main() {
    int size;
    srand(time(NULL));

    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    arr = inputData(size);

    cout << "Before: ";
    outputData(arr, size);

    shakeShort(arr, size);
    cout << "After: ";
    outputData(arr, size);
}