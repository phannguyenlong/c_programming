#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

class Complex {
    private:
        int real, img;
    public:
        Complex(int real=0, int img=0)
        : real(real), img(img) {}
        float countValue() {
            return sqrt(real*real + img*img);
        }
        bool operator>(Complex another) { return this->countValue() > another.countValue(); }
        void operator=(Complex another) {
            real = another.real;
            img = another.img;
        }
        friend ostream& operator<<(ostream& os, Complex num) {
            os << "(" << num.real << "," << num.img << ")";
            return os;
        }
};

int main() {
    vector <Complex*> complex_list;
    srand(1);
    for (int i=0; i<10; i++) {
        complex_list.push_back(new Complex(rand() % 20, rand() % 20));
        cout << *complex_list[i] << "\t";
    }
    // sorted
    cout << "\n============Sorted list==============" << endl;
    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            Complex* temp;
            if (*complex_list[i] > *complex_list[j]) {
                temp = complex_list[i];
                complex_list[i] = complex_list[j];
                complex_list[j] = temp; 
            }
        }
    }
    for (int i=0; i < 10; i++) { cout << *complex_list[i] << "\t"; }
}