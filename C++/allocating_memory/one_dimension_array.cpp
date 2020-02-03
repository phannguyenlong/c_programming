#include <iostream>

using namespace std;

int main() {
    // create 20 memory slot type int (4 bypte/each)
    int * array = new int[20]; // will return the address of the first number
    if ( !array ) {
        cout << "Error when allocating memory" << endl;
    } else {
        for (int i= 0; i < 20; i++) {
            array[i] = i;
        }
        for (int i = 0; i <20; i++) {
            cout << array[i] << endl;
        }
    }
    // delete memory
    delete [] array;
    for (int i=0; i<20; i++) {
        cout << array[i] <<endl;
    }
}