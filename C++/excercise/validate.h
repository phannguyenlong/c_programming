#ifndef  COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

int validateDigit() {
    int num;
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "Wrong input. Input: ";
    }
    return num;
}

#endif