#include <iostream>
using namespace std;

int *merge_sort(int, int *);

int main() {
    int dimension;
    cout << "Input dimension: ";
    cin >> dimension;
    int * array = new int[dimension];
    for (int i=0; i<dimension; i++) {
        cout << "Enter element " << i << ": ";
        cin >> array[i];
    }
    array = merge_sort(dimension, array);
    for (int i=0; i<dimension;i++) {
        cout << array[i] << "\t";
    }
}

int *merge_sort(int dimension, int * array) {
    if (dimension < 2) return array; // base case
    // init 2 sub array
    int * sub_arr1 = new int[dimension/2];
    int * sub_arr2 = new int[dimension - dimension/2];
    // slipt from array to 2 subarray
    for (int i=0; i < dimension/2; i++) sub_arr1[i] = array[i];
    for (int i=dimension/2; i < dimension; i++) sub_arr2[i-dimension/2] = array[i];
    // use recusive to slipt subarray to smaller subarray
    sub_arr1 = merge_sort(dimension/2, sub_arr1);
    sub_arr2 = merge_sort(dimension - dimension/2, sub_arr2);
    // order and merge 2 ordered subarray
    int *final_array = new int[dimension]; 
    int i=0, j=0, k=0; // create index
    while ( (i < dimension/2) || j < (dimension - dimension/2)) {
        if (i == dimension/2) {
            final_array[k] = sub_arr2[j];
            j++; k++;
            continue;
        } else if (j == (dimension - dimension/2)) {
            final_array[k] = sub_arr1[i];
            i++; k++;
            continue;
        }
        if(sub_arr1[i] < sub_arr2[j]){
            final_array[k] = sub_arr1[i];
            i ++;
        } else {
            final_array[k] = sub_arr2[j];
            j ++;
        };
        k++;
    }
    return final_array;
}
