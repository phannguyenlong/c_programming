#ifndef  COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        double real;
        double imag;
    public:
        // constructor
        Complex (double aReal = 0.0, double aImag = 0.0);
        void setValue(double aReal, double aImag) {
            real = aReal;
            imag = aImag;
        }
        void print();
        bool isReal() {return real == 0;}
        bool isImagine() {return imag == 0;}
        Complex addInto(Complex& num);
        Complex addReturnNew(Complex& num);
};

#endif