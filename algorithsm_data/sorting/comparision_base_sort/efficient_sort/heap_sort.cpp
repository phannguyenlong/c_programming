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

void shift_down(int *arr, int left, int right) {
  int i = left, j = 2*left;
  int x = arr[i];
  while (j <= right) {
    if ( j < right ) {
      if (arr[j] < arr[j+1]) j++;
    }
    if (arr[i] < arr[j]) break;
    arr[i] = arr[j];
    i = j;
    j = 2 * i;
  }
  arr[i] = x;
}
void heapSort(int *arr, int size) {
  int left = size/2;
  // Creating a heap array 
  while (left >= 0) {
    shift_down(arr, left, size-1);
    left--;
  }
  cout << "\n Heap: ";
  outputData(arr, size);
  int n = size - 1;
  while (n > 0) {
    swap(arr[0], arr[n]);
    n--;
    shift_down(arr, n/2, n);
  }
}

int main() {
  int *arr, size;
  srand(1);
  
  cout << "Enter array size: ";
  cin >> size;
  arr = inputData(size);

  cout << "Before: ";
  outputData(arr, size);

  cout << "After: ";
  heapSort(arr, size);
  outputData(arr, size);
}
