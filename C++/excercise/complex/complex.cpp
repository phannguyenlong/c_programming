#include <iostream>
#include "complex.h" // including header of complex file
using namespace std;

Complex::Complex(double aReal, double aImag)
    : real(aReal), imag(aImag) {} // this is called invoking initialization list (gg for more) || apply for constructor only
// print()
void Complex::print() { cout << "(" << real << "," << imag << ")" << endl; }
// addInto() adds the given complex number (by reference) into this instance, and return this instance by reference
Complex Complex::addInto(Complex& num) { // function nhận tham chiếu (reference) của 1 object khác truyền vô rồi trả về 1 object đã được cộng 
    real += num.real;
    imag += num.imag;
    return *this; // dereference để trả về 1 object
}
/* addReturnNew adds the given complex number (by  reference) and this instance, and 
 returns a new instance of my  complex, this instance shall not change. */
Complex Complex::addReturnNew(Complex& num) { // vẫn nhận vào 1 tham chiếu của 1 object khác
    return Complex(real + num.real, imag + num.imag); // return another object , which has been plus by not this instance
}


int main()
{
    Complex c1, c2(4, 5);
    c1.print(); // (0,0)
    c2.print(); // (4,5)

    c1.setValue(0, 8);
    c1.print(); // (6,7)

    cout << boolalpha;  // print true/false instead of 0/1
    cout << "Is real? " << c1.isReal() << endl;  // false
    cout << "Is Imaginary? " << c1.isImagine() << endl; // true

    cout << "addInto running:" << endl;
    c1.addInto(c2).print(); // (4,13) || vì c1.addInto(c2) trả về 1 object chính là c1 nên nó cũng bằng với c1.print
    c1.print();  // (4,13)

    cout << "addReturnNew running:" << endl;
    c1.addReturnNew(c2).print();   // (8,18)
    c1.print();  // (4,13) - no change in c1
}