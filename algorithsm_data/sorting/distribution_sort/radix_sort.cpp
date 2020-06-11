#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;
}
void outputArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int findMax(int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) 
        if (arr[i] > max)
            max = arr[i];
    return max;
}
int countDigit(int n) {
    int count = 0;
    while (n!=0) {
        n /= 10;
        count++;
    }
    return count;
}

void sort(int *arr, int size, int k) {
    for (int i = 0; i < size; i ++) // use bubble sort instead of counting for fast
        for (int j = i+1; j < size; j++) 
            if ( arr[i]%(10*(k+1)) > arr[j]%(10*(k+1)) )
                swap(arr[i], arr[j]);
}
void radixSort(int *arr, int size) {
    int num_of_digit = countDigit(findMax(arr, size));
    for (int i = 0; i < num_of_digit; i++)
        sort(arr, size, i);
}

int main() {
    int size;
    srand(time(NULL));

    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    inputArray(arr, size);

    cout << "Before: ";
    outputArray(arr, size);

    cout << "After: ";
    radixSort(arr, size);
    outputArray(arr, size);
}