#include <iostream>
using namespace std;

template <class Type> // define a template with 1 parameter type
void swap(Type &a, Type &b) {
    Type temp = a; // define type is Type (belong to template) for variable temp
    a = b;
    b = temp;
}

template <class Type1, class Type2> // define a templates with 2 paramenter type
void arrayInput(Type1 array, Type2 length) { // array here is a pointer (pass by references)
    for (Type2 i=0; i < length; i++) {
        cout << "Value " << i << ": ";
        cin >> array[i];
    }
}

template <class Type1, class Type2> // define a templates with 2 paramenter type
void arrayOuput(Type1 array, Type2 length) { // array here is a pointer (pass by references)
    for (Type2 i=0; i < length; i++) {
        cout << array[i] << "\t";
    }
    cout << '\n';
}


class Person {
    private:
        int id;
    public:
        Person(int id): id(id) {}
        int getID() {return id;}
};

int main() {
    int a = 10, b=20;
    ::swap(a,b); // must use this cause swap have same name with other function in std (standard library)
    cout << "a: " << a << " b: " << b << endl; // return a: 20 b:10

    Person p1(100), p2(200);
    ::swap(p1,p2); // must use this cause swap have same name with other function in std (standard library)
    cout << "p1: " << p1.getID() << " p2: " << p2.getID() << endl;// return p1: 200 p2: 100

    // array input
    const unsigned tempCount = 3; 
    float temperature[tempCount];  
    arrayInput(temperature, tempCount); // type float
    arrayOuput(temperature, tempCount);

    const unsigned stationCount = 4; 
    string station[stationCount];
    arrayInput(station, stationCount); // type string
    arrayOuput(station, stationCount);
}