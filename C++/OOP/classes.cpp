#include <iostream>
using namespace std;

class TypeA {
    private: 
        int a;
    public:
        TypeA(int value = 10) {a = value;}; // contructor function set inital value for a is 10
        // there are 2 type of declare function in class
        void setA(int); // declare a protype here and definantion outside
        int getA() {return a;}; // declare and definition inside the class
        friend class TypeB; // set friend class cho TypeB
};
void TypeA::setA(int value) {a = value;} // defination for function outside the class

class TypeB { // TypeB is a friend class of TypeA so it can access private of it otherwise not
    public:
        void showDoubleA(TypeA name) {cout << "A in b is: " << name.a * 2 << endl;};
};

int main() {
    TypeA a(5), c; TypeB b; // init 2 object a and b
    cout << "a in TypeA now is: " << a.getA() << endl; // return 5
    c = a; // copy constructor 
    c.setA(20);
    cout << "a in TypeA now is: " << c.getA() << endl; // return 20
    b.showDoubleA(c); // return 40
}
