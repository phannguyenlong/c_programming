#include <iostream>
using namespace std;

template<class Type,int N> // initalize class template with 2 paremeter
class Array {
private:
    Type *data;
public:
    Array() {
        data = new Type[N];
    }
    void display() {
        cout << "Initalize array" << endl;
    }
    ~Array() {
        delete [] data;
        cout << "Delete array" << endl;
    }
};

class intArray: public Array<int, 10> { // this is inheritance class from Array class
};

int main()
{
    Array<int, 10> array; // pass paremeter to template
    array.display();
}