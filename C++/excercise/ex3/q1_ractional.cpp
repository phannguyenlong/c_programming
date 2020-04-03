#include <iostream>
#include <limits> // for validating
#include "../validate.h"
using namespace std;

int findGcd(int, int);

class Ractional {
    private:
        int numerator;
        int denumerator;
    public:
        Ractional(int numerator=1, int denumerator=1) 
        : numerator(numerator), denumerator(denumerator) {} // constructor initalizaition list
        Ractional(Ractional& another) 
        : numerator(another.numerator), denumerator(another.denumerator) {}
        int getNumerator() {return numerator;}
        int getDenumerator() {return denumerator;}
        void shorten() {
            int gcd; 
            gcd = findGcd(numerator, denumerator);
            numerator = numerator / gcd;
            denumerator = denumerator / gcd;
        }
};

int main() {
    int num, denum;
    // validating
    cout << "Input numerator: ";
    num = validateDigit();
    cout << "Input denumerator: ";
    denum = validateDigit();
    Ractional a(num,denum);
    cout << a.getNumerator() << "/" << a.getDenumerator() << endl;
    a.shorten();
    cout << "Shorten ractional is: " << a.getNumerator() << "/" << a.getDenumerator() << endl;
    return 0;
}

int findGcd(int a, int b) {
    return b==0 ? a : findGcd(b, a%b); // still correct whether a > b or b > a
}