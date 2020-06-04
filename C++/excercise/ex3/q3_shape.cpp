#include <iostream>
#include <vector>
using namespace std;

class Shape {
    protected:
        double area=0;
    public:
        virtual void draw() {};
        virtual double calArea() {return 0;}
        friend ostream & operator<< (ostream& os, Shape* shape) {
            os << shape->area << '\t';
            return os;
        }
        bool operator < (Shape shape) { return this->area < shape.area; }
};
class Circle: public Shape {
    private:
        double radius;
    public:
        Circle(double radius): radius(radius) {}
        void draw() { cout << "Draw circle" << endl; }
        double calArea() { area = radius * radius * 3.14; return area; }
};
class Square: public Shape {
    private:
        double side;
    public:
        Square(double side): side(side) {}
        void draw() { cout << "Draw Square" << endl; }
        double calArea() { area = side * side; return area; }
};
class Triangle: public Shape {
    private:
        double height;
        double width;
    public:
        Triangle(double height, double width): height(height), width(width) {}
        void draw() { cout << "Draw Triangle" << endl;}
        double calArea() { area = height * width /2; return area; }
};

vector <Shape *> sorted(vector <Shape*> shapes) {
    Shape *temp;
    for (int i=0; i < shapes.size(); i++) {
        for (int j=0; j < shapes.size(); j++) {
            if (*shapes[i] < *shapes[j]) {
                temp = shapes[i];
                shapes[i] = shapes[j];
                shapes[j] = temp;
            }
        }
    }
    return shapes;
}

int main() {
    vector <Shape *> shapes;
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
            shapes.push_back(new Circle(radius));
            break;
        case 2:
            double side;
            cout << "Input side: ";
            cin >> side;
            shapes.push_back(new Square(side));
            break;
        case 3:
            double h,b;
            cout << "Input heigh: ";
            cin >> h;
            cout << "Input base: ";
            cin >> b;
            shapes.push_back(new Triangle(h,b));
            break;
        case 4: 
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
        if (choice==1||choice==2||choice==3) {shapes.back()->calArea();} // cal the area
    }
    cout << "Sorted is: " << endl;
    shapes = sorted(shapes);
    for (int i = 0; i < shapes.size(); i++) {
        cout << shapes[i];
    }
}
