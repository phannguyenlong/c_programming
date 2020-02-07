#include <iostream>
#include <vector>
#include "../validate.h"
using namespace std;

class Quadrilaterals {
    protected: // must use protected cause it need to be access from inherit class
        int height, width;
        double area;
    public:
        Quadrilaterals(int height = 1, int width = 1)
        : height(height), width(width) {}
        
        virtual double cal_area() {return 1;} // Khai báo là hàm ảo bởi vì nó sẽ được sửa đổi bởi các inherit class
        double print() { return cal_area();}
};

class Rectangles : public Quadrilaterals { // inherit
    public:
        Rectangles(int height = 1, int width= 1) {
            this->height = height; // must use this if u want to use parameter name same as poperties name
            this->width = width;
        }
        double cal_area() {
            area = height * width;
            return area;
        }
};

class Parallelograms : public Quadrilaterals {
    public:
        Parallelograms(int height = 1, int width = 1) {
            this->height = height;
            this->width = width;
        }
        double cal_area() {
            area = height * width;
            return area;
        }
};

class Trapeziums : public Quadrilaterals {
    protected:
        int width2;
    public:
        Trapeziums(int height=1, int width=1,int width2 = 1) {
            this->height = height;
            this->width = width;
            this->width2 = width2;
        }
        double cal_area() {
            area = (width2 + width) * height / 2;
            return area;
        }
};

int main() {
    vector <Quadrilaterals*> Shape; // create a vector of pointer type Quadrilaterals
    int input = 0, width, width2, height;
    string shapes[3] = {"Rectangle", "Parallelogram", "Trapezium"};
    while (input != 5) {
        cout << "1 to insert Rectangle, 2 to insert Parallelogram, 3 to insert Trapezium, 4 to get area of element, 5 to exit" << endl;
        cout << "Input: ";
        input = validateDigit();
        switch (input)
        {
        case 1:
        case 2:
        case 3:
            cout << "Input height of " << shapes[input-1] <<": ";
            height = validateDigit();
            cout << "Input width of " << shapes[input-1] <<": ";
            width = validateDigit();
            if (input == 3) {
                cout << "Input width 2 of " << shapes[input-1] <<": ";
                width2 = validateDigit();
            }
            if (input== 1) Shape.push_back(new Rectangles(height, width)); // allocation memory will return the
            else if (input == 2) Shape.push_back(new Parallelograms(height, width)); // address of 1st element so must use pointer
            else if (input == 3) Shape.push_back(new Trapeziums(height,width,width2));
            break;
        case 4:
            int order;
            cout << "Enter number of element want to check area: ";
            order = validateDigit();
            if (order < Shape.size() && order >= 0) {
                cout << "Area of element " << order << " is: " << Shape[order]->print() <<endl; // use -> cause it will return a pointer
            } else cout << "Element not exist" << endl;
            break;
        case 5:
        case '\n':
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
    cout << "End program with " << Shape.size() << " element in the list" << endl;
}