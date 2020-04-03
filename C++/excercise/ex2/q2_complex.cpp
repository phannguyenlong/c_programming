#include <iostream>
using namespace std;

class Complex {
    private:
        int real, img;
    public:
        Complex(int real=0, int img=0)
        : real(real), img(img) {}
        void setValue(int real, int img) {
            this->real = real;
            this->img = img;
        }
        Complex addInto(Complex& another) { // pass by ref
            real += another.real;
            img += another.img;
            return *this;
        }
        Complex addReturnNew(Complex& another) {
            real += another.real;
            img += another.img;
            return Complex(real, img);
        }
        bool isReal() { return img == 0; }
        bool isImagine() { return real == 0; }
        void print() {
            cout << "(" << real << "," << img << ")" << endl;
        }
        friend ostream& operator<<(ostream& os, Complex num) {
            os << "(" << num.real << "," << num.img << ")";
            return os;
        }
};

int main() {
     Complex c1, c2(4, 5);
    c1.print(); 
    c2.print();

    c1.setValue(0, 8);
    c1.print(); 
    cout << boolalpha; 
    cout << "Is real? " << c1.isReal() << endl;  
    cout << "Is Imaginary? " << c1.isImagine() << endl; 

    cout << "addInto running:" << endl;
    c1.addInto(c2).print(); 
    c1.print();  

    cout << "addReturnNew running:" << endl;
    c1.addReturnNew(c2).print();   
    c1.print(); 
}