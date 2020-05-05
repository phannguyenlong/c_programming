#include <iostream> 
using namespace std;

class Number {
    private: 
        int n;
    public:
        Number (int n=0): n(n) {};
        Number (Number& another): n(another.n) {}
        int getNum() { return n; }
        // ++a prefix - execute than run line
        Number operator++() {
            n ++;
            return *this;
        }
        // --a prefix
        Number operator--() {
            n--;
            return *this;
        }

        // a++ postfix - execute after line done
        Number operator++(int) { // must have int to distingish between postfix and prefix
            Number *copy = new Number(n); // make a copy
            ++(*this);
            return *copy;
        }
        Number operator--(int) {
            Number *copy = new Number(n);
            --(*this);
            return *copy;
        }

        Number operator+(Number another) {
            int res_val = n + another.n;
            Number *res = new Number(res_val);
            return *res;
        }
        Number operator-(Number another) {
            int res_val = n - another.n;
            Number *res = new Number(res_val);
            return *res;
        }
};

int main() {
    Number a(10);
    cout << "Num is: " << a.getNum() << endl;
    cout << "++a is: " << (++a).getNum() << endl;
    cout << "a++ is: " << (a++).getNum() << endl;
    cout << "a is: " << a.getNum() << endl;

    Number b(20);
    cout << "a + b is: " << (a+b).getNum() << endl;

    Number c(15);
    cout << "a + b - c is: " << (a+b-c).getNum() << endl;
}
