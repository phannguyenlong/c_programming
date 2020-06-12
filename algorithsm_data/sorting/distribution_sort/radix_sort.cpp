#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 200;
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
int getDigit(int num, int k) {
    for (int i = 0; i < k - 1; i++)
        num /= 10;
    return num % 10;
}

void countingSort(int *arr, int size, int k) {
    int f[10] = {0};
    int *b = new int[size];
    for (int i = 0; i < size; i++)
        f[getDigit(arr[i], k + 1)]++;
    for (int i = 1; i < 10; i++)
        f[i] = f[i] + f[i - 1];
    for (int i = size-1; i >= 0; i-- ) { // NOTE: distribute from right to left
        b[f[getDigit(arr[i], k + 1)] - 1] = arr[i];
        f[getDigit(arr[i], k + 1)]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = b[i];
}
void radixSort(int *arr, int size) {
    int num_of_digit = countDigit(findMax(arr, size));
    for (int i = 0; i < num_of_digit; i++)
        countingSort(arr, size, i);
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