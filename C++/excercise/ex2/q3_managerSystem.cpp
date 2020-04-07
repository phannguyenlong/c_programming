#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student {
    private:
        int id;
        float GPA;
        string fname, lname, major, gender;
    public:
        Student (int id, string fname, string lname, int major_choice, int gender_choice, float GPA)
        : id(id), fname(fname), lname(lname), GPA(GPA) {
            string major_list[4] = {"computer science","information technology","software engineering","information system"};
            string gender_list[2] = {"male", "female"};
            major = major_list[major_choice];
            gender = gender_list[gender_choice];
            cout << "New Student was created" << endl;
        }
        Student (int id, string fname, string lname, string major, string gender, float GPA)
        : id(id), fname(fname), lname(lname), major(major), gender(gender), GPA(GPA) {}
        void modify() {
            string major_list[4] = {"computer science","information technology","software engineering","information system"};
            string gender_list[2] = {"male", "female"};
            int choice = 0, tmp_choice;
            while (choice != 6) {
                fflush(stdin);
                cout << "1-id\n2-name\n3-gener\n4-major\n5-gpa\n6-exit\nYour choice: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    cout << "Input ID: ";
                    cin >> id;
                    break;
                case 2:
                    fflush(stdin);
                    cout << "Input Student first name: ";
                    getline(cin, fname);
                    cout << "Input Student last name: ";
                    getline(cin, lname);
                    break;
                case 3:
                    cout << "Input Student gender (0 - male, 1 - female): ";
                    cin >> tmp_choice;
                    gender = gender_list[tmp_choice];
                    break;
                case 4:
                    cout << "0-computer science\n1-information technology\n2-software engineering\n3-information system\nChoice: ";
                    cin >> tmp_choice;
                    major = major_list[tmp_choice];
                    break;
                case 5:
                    cout << "Input GPA: ";
                    cin >> GPA;
                    break;
                case 7:
                case '\n':
                    break;
                default:
                    cout << "Must range from 1 to 6" << endl; 
                    break;
                }
            }
        }
        bool checkID(int id) { return this->id == id; }
        friend ostream& operator<<(ostream& os, Student std) {
            os <<  "ID: " << std.id << "\nName: " << std.lname << " " << std.fname;
            os << "\nGender: " << std.gender << "\nMajor: " << std.major << "\nGPA: " << std.GPA;
            return os;
        }
        friend void writeFile(const vector <Student *>&);
};

void readFile(vector <Student*>& list) {
    ifstream fin; // file pointer
    int id;
    float GPA;
    string address, lname, fname, major, gender;
    cout << "Input link to your file: ";
    cin >> address;
    fin.open(address, ios::in); // use input mode
    if (!fin) {
        cout << "Unable to reach file";
        exit(1); // break the program
    } else {
        while (!fin.eof()) {
            fin >> id;
            fin >> fname;
            getline(fin, lname, '|');
            getline(fin, gender, '|');
            getline(fin, major, '|');
            fin >> GPA;
            list.push_back(new Student(id, fname, lname, major, gender, GPA));
        }
        fin.close();
    }
}
void writeFile(const vector <Student*> &list) {
    ofstream fout; // pointer to file output
    string address;
    cout << "Input link to saved file: ";
    cin >> address;
    fout.open(address, ios::out); // set to ouput mode
    for (int i=0; i < list.size(); i++) {
        fout <<  list[i]->id << " " << list[i]->lname << list[i]->fname << "|" ;
        fout << list[i]->gender << "|" << list[i]->major << "|" << list[i]->GPA << "\n";
    }
}

int main() {
    int choice =1, major, gender, id, pos;
    float gpa;
    string fname, lname;
    vector <Student*> student_system;
    readFile(student_system);
    while (choice != 6) {
        cout << "1 - Add Record\n2 - List Record\n3 - Modify Record\n4 - Delete Record\n5 - Search Record\n6 - Exit\nInput choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Input ID: ";
                cin >> id;
                cout << "Input Student first name: ";
                fflush(stdin);
                getline(cin, fname);
                cout << "Input Student last name: ";
                getline(cin, lname);
                cout << "Input Student gender (0 - male, 1 - female): ";
                cin >> gender;
                cout << "0-computer science\n1-information technology\n2-software engineering\n3-information system\nChoice: ";
                cin >> major;
                cout << "Input GPA: ";
                cin >> gpa;
                student_system.push_back(new Student(id, fname, lname, major, gender, gpa));
                break;
            case 2:
                if (student_system.size() == 0) {cout << "There is no student yet." << endl;}
                else {
                    for (int i=0; i <student_system.size(); i++) {
                        cout << "============STUDENT " << i << "============" << endl;
                        cout << *student_system[i] << endl;
                    }
                }
                break;
            case 3:
                if (student_system.size() == 0) {cout << "There is no student yet." << endl;}
                cout << "Input postion of student to modify (0 -> " << student_system.size() - 1 << "): ";
                cin >> pos;
                student_system[pos] -> modify();
                break;
            case 4:
                cout << "Input student ID to delete: ";
                cin >> id;
                for (int i=0; i < student_system.size(); i++) {
                    if (student_system[i]->checkID(id)) {
                        student_system.erase(student_system.begin() + i);
                        cout << "Student " << i << " is removed" << endl;
                    }
                }
                break;
            case 5:
                cout << "Input student ID to search: ";
                cin >> id;
                cout << "User found:" << endl;
                for (int i=0; i < student_system.size(); i++) {
                    if (student_system[i] -> checkID(id)) {
                        cout << "============STUDENT " << i << "============" << endl;
                        cout << *student_system[i] << endl;
                    }
                }
            case '\n':
            case 6:
                break;
            default:
                cout << "Input must in range 1 to 6" << endl;
                break;
        }
    }
    writeFile(student_system);
}