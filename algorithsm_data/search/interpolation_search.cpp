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
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    return arr;
}

bool interpolationSearch(int *arr, int size, int key) {
    int left = 0, right = size - 1;
    while (arr[left] != arr[right] && arr[left] <= key && arr[right] >= key) {
        int x = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        cout << "X: " << x << "arr[x]" << arr[x] <<  endl;
        if (arr[x] < key)
            left = x + 1;
        else if (arr[x] > key)
            right = x - 1;
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

    cout << "============Interpolation Search============" << endl;
    arr = sortArray(arr, size);
    outputData(arr, size);
    cout << "Enter key to search: ";
    cin >> key;
    string res = interpolationSearch(arr, size, key) ? "Yes" : "No";
    cout << res;
}