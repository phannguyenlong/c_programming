#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int * inputData(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20;
    }
    return arr;
}
void outputData(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int * sortArray(int *arr, int size) {
    for (int i = 0; i < size;i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

bool linearSearch(int *arr, int size, int key) {
    int i = 0;
    while (i < size && arr[i] != key)
        i++;
    return arr[i] == key;
}
bool binarySearch(int *arr, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key)
            right = mid - 1;
        else if (arr[mid] > key)
            left = mid + 1;
        else
            return true;
    }
    return false;
}

int main() {
    int *arr, size, key;
    srand(time(NULL));
    
    cout << "Enter size of array: ";
    cin >> size;
    arr = new int[size];
    arr = inputData(arr, size);
    outputData(arr, size);

    cout << "Enter key to search: ";
    cin >> key;

    cout << "==========Linear Search=============" << endl;
    string res = linearSearch(arr, size, key) ? "Yes" : "No";
    cout << res;

    cout << "\n==========Binary Search=============" << endl;
    arr = sortArray(arr, size);
    outputData(arr, size);
    string res2 = binarySearch(arr, size, key) ? "Yes" : "No";
    cout << res2;
}