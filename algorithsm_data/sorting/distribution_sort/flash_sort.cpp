#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputData(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;
}
void outputData(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

int findMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) 
        if (arr[i] > max)
            max = arr[i];
    return max;
}
int findMin(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) 
        if (arr[i] < min)
            min = arr[i];
    return min;
}
void flashSort(int *arr, int size, int m = 5) { // defaul number of class in 5
    int max = findMax(arr, size);
    int min = findMin(arr, size);
    int *L = new int[m];
    for (int i = 0; i < m; i++) L[i] = 0; // init 0 for all elements

    // classification
    for (int i = 0; i < size; i++) {
        int k = ((m - 1) * (arr[i] - min)) / (max - min);
        L[k]++;
    }
    outputData(L, m);
    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];
    outputData(L, m);
    // permutation
    int i = 0, k = m-1;
    for (int count = 0; count < m; count++) {
        cout << k << endl;
        while (i > (L[k]-2) && i < size - 1) {
            i++;
            cout << i << endl;
            k = ((m - 1) * (arr[i] - min)) / (max - min);
        }
        int x = arr[i];
        cout << x << endl;
        while (i != L[k] - 1) {
            k = ((m - 1) * (x - min)) / (max - min);
            swap(x, arr[L[k]-1]);
            L[k]--;
        } 
        outputData(arr, size);
        outputData(L, m);
    }
    outputData(L, m);
    // sorting
    for (int i = 0; i < m; i ++) {
        int stop = i + 1 == m ? size : L[i + 1];
        for (int j = L[i] + 1; j < stop; j++) 
            for (int z = L[i] + 1; z < stop; z++) 
                if (arr[j] < arr[z])
                    swap(arr[j], arr[z]);
    }
}

int main() {
    srand(time(NULL));
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    inputData(arr, size);

    cout << "Before: ";
    outputData(arr, size);

    cout << "After: ";
    flashSort(arr, size);
    outputData(arr, size);
}