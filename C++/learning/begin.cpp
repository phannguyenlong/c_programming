#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void sayHello( int age = 10, string name="Some random name"); // set defaul parameter

int main()
{
    // basic print out
    string name = "Phan Nguyen Long";
    int age = 10;
    double age1 = 10.5;
    cout<<"Hello "<< name << "age is: "<< age << endl;
    cout << name.find("heo", 0) << endl;
    cout << string::npos <<endl; // string::nops la ko tim thay trong string..find()
    age > age1 ? cout << age + age1 << endl: cout << "hello" << endl;
    
    // user input
    int usrAge; // interger input
    cout << "Enter ur age: ";
    cin >> usrAge ;
    cout << "Age is: " << usrAge << endl;
    
    while (getchar() != '\n'); // must have this or C++ will pass '\n' to next input, bullshit
    
    string usrName; // input string
    cout << "Enter ur name: ";
    getline(cin, usrName);
    cout << "Your name is: " << usrName << endl;

    // array y chang trong C
    // function giong C, C++ co them defaul parameter: được thêm ở prototype ở trên
    sayHello();

    return 0;
}

void sayHello( int age, string name) {
    cout << age << "Hello my name is  " << name << endl;
}