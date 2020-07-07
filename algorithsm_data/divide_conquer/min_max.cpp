#include <iostream>
using namespace std;

void minMax(int *arr, int size, int left, int right, int &min, int &max) {
    if (left == right || left + 1 == right) {
        if (arr[left] > arr[right]) {
            
        }
    } 
}

int sum(int *arr, int left, int right) { // cal sum of array using divide and conquer
    if (left == right) return arr[left];
    int mid = (left + right) / 2;
    return sum(arr, left, mid) + sum(arr, mid + 1, right);
}