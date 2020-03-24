#include <iostream>
#include <vector>
using namespace std;

class Shape {
    public:
        virtual void draw() = 0; // pure virtual function
        virtual double area() {return 1;};
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(int r = 0) { radius = r; }
        void draw() {cout << "Draw circle" << endl;}
        double area() {return 3.14 * radius;}
};

class Square : public Shape {
    private:
        double side;
    public:
        Square(int a=0) { side = a; }
        void draw() {cout << "Draw square" << endl;}
        double area() {return side*side;}
};

class Triangle : public Shape {
    private:
        double heigh, base;
    public:
        Triangle(int h=0,int b=0) { heigh = h; base = b; }
        void draw() {cout << "Draw triangle" << endl;}
        double area() {return heigh*base/2;}
};

void printed (vector <double> arr) {
    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << "\t";
    }
}

vector <double> sorted (vector <double> arr) {
    double temp;
    for (int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr.size(); j++) {
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    vector <Shape*> shape;
    vector <double> arr;
    int choice = 0;
    while (choice != 4) {
        cout << "1 - Circle\n2 - Square\n3 - Triangle\n4 - exit\nInput choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            double radius;
            cout << "Input radius: ";
            cin >> radius;
            shape.push_back(new Circle(radius));
            break;
        case 2:
            double side;
            cout << "Input side: ";
            cin >> side;
            shape.push_back(new Square(side));
            break;
        case 3:
            double h,b;
            cout << "Input heigh: ";
            cin >> h;
            cout << "Input base: ";
            cin >> b;
            shape.push_back(new Triangle(h,b));
            break;
        case 4: 
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
        if (choice==1||choice==2||choice==3) {arr.push_back(shape.back()->area());}
        cout << "area: "<< arr.back() << endl;
    }
    arr = sorted(arr);
    printed(arr);
}