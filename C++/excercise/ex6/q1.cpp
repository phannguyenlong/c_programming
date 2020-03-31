#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Student {
    private:
        string fname, lname, gender, status;
        float GPA;
    public:
        Student(string f_name, string l_name, string gender, string status, float GPA)
        : fname(f_name), lname(l_name), gender(gender), status(status), GPA(GPA) {}
        void show() {
            cout << "Name: " << lname << " " << fname << endl;
            cout << "GPA: " << setprecision(2) << GPA << ", Status: " << status << endl;
            cout << "Gender: " << gender << endl;
        }
        void bounus(float bounus) {
            GPA += bounus;
            GPA = GPA > 4.0 ? 4.0 : GPA;
        }
        // overloading operation
        Student operator=(float gpa) {
            GPA = gpa;
            GPA = GPA > 4.0 ? 4.0 : GPA;
            return *this;
        }
        bool operator>(float num) {
            return GPA > num;
        }
        bool operator>(Student another) {
            return GPA > another.GPA;
        }
        bool operator<(float num) {
            return GPA < num;
        }
        friend ostream& operator<<(ostream & os, Student std) { // using overloading for operation <<
            os << "Name: " << std.lname << " " << std.fname << endl;
            os << "GPA: " << setprecision(2) << std.GPA << ", Status: " << std.status << endl;
            os << "Gender: " << std.gender << endl;
            return os;
        }
};

int main() {
    vector <Student*> student_list; // create list of pointer to Student class
    string fname[5] = {"Nam", "Thanh", "Ngoc", "Cao", "Tien"};
    string lname[5] = {"Nguyen", "Nguyen", "Phan", "Tran", "Bui"};
    string gender[5] = {"male","male","female","male","male"};
    string status[5] = {"freshman", "sophomore", "junior", "senior"};
    float gpa[5] = {3,4,3.5,3.3,3.1};
    for (int i=0; i<5; i++) {
        student_list.push_back(new Student(fname[i],lname[i],gender[i],status[i],gpa[i])); // use new cause it return a pointer
        cout << *student_list[i] << endl; // must have * cause it is pointer
    }
    // sorted
    for (int i=0; i<5;i++) {
        for (int j=0; j<5;j++) {
            Student* ptr; // using pointer as a temp variable
            if (*student_list[i] > *student_list[j]) {
                ptr = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = ptr;
            }
        }
    }
    cout << "Sorted list: " << endl;
    for (int i=0; i<5; i++) {
        cout << *student_list[i] << endl;
    }
}