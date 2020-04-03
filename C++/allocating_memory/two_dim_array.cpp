#include <iostream>
using namespace std;

int main() {
    int size = 10;
    int **ptr; // pointer to pointer
    ptr = new int*[5];

    ptr = new int*[size]; // inital an array contain pointer type T
        for (int i=0; i< size; i++) {
            *(ptr + i) = new int[size]; // init each array inside;
            for (int j=0; j < size; j++) {
                *(*(ptr+i) + j) = 0;
            }
        }
        cout << "Matrix size " << size << "x" << size << " is created" << endl; 
}