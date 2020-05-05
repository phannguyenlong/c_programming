#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    protected:
        string name;
        int age;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};
class Professor: public Person {
    private:
        string publication;
        static int count;
        int curl_id;
    public:
        void getdata() {
            cin >> name >> age >> publication;
            curl_id = ++count;
        }
        void putdata() {
            cout << name << " " << age << " " << publication << " " << curl_id << endl;
        }
};

class Student : public Person {
    private:
        int marks[6];
        static int count;
        int curl_id;
    public:
        void getdata() {
            cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
            curl_id = ++count;
        }
        void putdata() {
            int sum_marks = 0;
            for (int i = 0; i < 6; i ++) sum_marks += marks[i];
            cout << name << " " << age << " " << sum_marks << " " << curl_id << endl;
        }
};

// initialize static member for Professor and Student
int Professor::count = 0;
int Student:: count = 0 ;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[6];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
