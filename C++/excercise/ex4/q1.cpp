#include <iostream>
#include <vector>
using namespace std;

class Shape {
    public:
        virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
    public:
        void draw() {cout << "Draw circle" << endl;}
};

class Square : public Shape {
    public:
        void draw() {cout << "Draw square" << endl;}
};

class Triangle : public Shape {
    public:
        void draw() {cout << "Draw triangle" << endl;}
};

int main() {
    vector <Shape*> Type;
    
}