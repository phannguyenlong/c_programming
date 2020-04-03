#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Matrix {
    private:
        int size;
        T** ptr; // it is a pointer to pointer cause 2-dim array
    public:
        Matrix(int size=0): size(size) {
            ptr = new T*[size]; // inital an array contain pointer type T
            for (int i=0; i< size; i++) {
                *(ptr + i) = new T[size]; // init each array inside;
                for (int j=0; j < size; j++) {
                    cout << "Input element [" << i << "][" << j << "]: ";
                    cin >> *(*(ptr+i) + j);
                }
            }
            cout << "Matrix size " << size << "x" << size << " is created" << endl; 
        }
        ~Matrix() {
            for (int i=0; i < size; i++) {
                delete [] *(ptr + i);
            }
            delete [] ptr;
            cout << "Deleted matrix" << endl;
        }
        float forbNorm() {
            T norm = 0;
            for (int i=0; i< size*size; i++) {
                norm += ptr[i/size][i%size] * ptr[i/size][i%size];
                // T val = *(*(ptr + i/size) + i%size);
                // norm += val * val;
            }
            return sqrt(norm);
        }
        T rowNorm() {
            T norm = 0;
            for (int i=0; i<size; i++) {
                T row=0;
                for (int j=0; j <size;j++) {
                    row += ptr[i][j];
                }
                norm = norm > row ? norm : row;
            }
            return norm;
        }
        T totalNorm() {
            T max = 0;
            for (int i=0; i < size*size; i++) {
                max = max > abs(ptr[i/size][i%size]) ? max : abs(ptr[i/size][i%size]);
            }
            return size * max;
        }
        template <class X> friend ostream& operator<<(ostream& os, Matrix<X>& array) { 
            // must pass by refferent to prevent C++ make a shallow copy (applying rule of three)
            for (int i=0; i < array.size*array.size; i++) {
                if (i % array.size == 0 && i != 0) { os << "\n"; }
                os << *(*(array.ptr + i/array.size) + i%array.size) << "\t";
            }
            return os;
        }
};

int main() {
    int size;
    cout << "Input array size: ";
    cin >> size;
    fflush(stdin);
    Matrix<int> array1(size);
    cout << "Your array is:" << endl;
    cout << array1 << endl;
    cout << "Forbenius norm is: " << array1.forbNorm() << endl;
    cout << "Row sum norm is: " << array1.rowNorm() << endl;
    cout << "Total norm is: " << array1.totalNorm() << endl;
}