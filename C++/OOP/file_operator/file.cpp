#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin; // ifstream = input file stream
    ofstream fop; // ofstream = output file stream
    fstream fio; // fstream = input/output file stream
    string data;
    string file = "draft.txt";
    // read file txt
    // iso:: in(input) | out (output) | app (append at the end of file) 
    // | ate (Mở một file cho output và di chuyển điều khiển read/write tới cuối của file)
    fin.open(file, ios::in); // open 1 file in input mode (ios:: in == input)
    if (!fin) {
        cout << "Can not open file" << endl;
        exit(1);
    } else {
        while (!fin.eof()) { // run until the end of file
            getline(fin, data);
            cout << data << endl;
        }
        fin.close();
    }
    fop.open(file, ios::app); // open 1 file in append mode
    if (!fop) {
        cout << "Unable to reach file" << endl;
        exit(1);
    } else {
        fop << "Le Duc Duy" << endl;
        fop.close();
    }
}