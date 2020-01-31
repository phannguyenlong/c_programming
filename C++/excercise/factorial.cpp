#include <iostream>

using namespace std;

int factorial(int);

int main() {
    int num;
    cout << "Enter your number: ";
    cin >> num;
    factorial(num) == -1 ?
    cout << "Not exist factorial of "<< num << endl :
    cout << "Factorual of "<< num << " is: " << factorial(num) << endl; 
}

int factorial(int num) {
    if (num < 0) {
        return -1;
    } else  {
        return num == 0 ? 1 : num * factorial(num - 1);
    };
}