#ifndef  COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <limits>
using namespace std;

int validateDigit() {
    int num;
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore (numeric_limits < streamsize >::max (), '\n'); // This line ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cout << "Wrong input. Input: ";
    }
    return num;
}

#endif