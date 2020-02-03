#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void sayHello( int age = 10, string name="Some random name"); // set defaul parameter

// class and object
class Book {
    public: 
        string title;
        string author;
        int pages;
        // this can have parameter in contructor function instead if this
        Book() { // contructor funciton: will run when an object is create (MUST BE SAME NAME WITH CLASS)
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter pages: ";
            cin >> pages;
        };
        bool isLongBook() { // object function, will be call in main
            return pages >= 100 ? true : false;
        }
};

// getter and setter
class Movie {
    private: // những thuộc tính trong private thì chỉ có chỉnh bởi những function nằm trong class movie, những cái nằm ngoài không chỉnh được
        string rating;
    public:
        string title;
        string director;
        Movie() { // create initial value for class if there are none of information
            title= "no title";
            director = "no director";
            setRating("NG");
        }
        Movie( string aTitle, string aDirector, string aRating) {
            title = aTitle;
            director = aDirector;
            setRating(aRating); // must use like this to controll the input
        };
        void setRating(string aRating) {
            rating = aRating == "good" ? aRating : "NG"; // controll that the rating always set to be good :)))
        };
        string getRating() {
            return rating;
        }
};

// inherit
class Chef{
    public:
        void makeChicken(){
            cout << "The chef makes chicken" << endl;
        }

        void makeSalad(){
            cout << "The chef makes salad" << endl;
        }

        void makeSpecialDish(){
            cout << "The chef makes a special dish" << endl;
        }
};
class ItalianChef : public Chef{ // thừa hưởng (inherit) các thuộc tính có sẵn của class chef (có thể thừa hưởng từ nhiều class, để ý thứ tự)
    public:
        void makePasta(){
            cout << "The chef makes pasta" << endl;
        }

        // override: có thể ghi đè và thay đổi thuộc tính mà nó được thừa hưởng mà không ảnh hưởng tới class bị thừa hưởng
        void makeSpecialDish(){
            cout << "The chef makes chicken parm" << endl;
        }
};

int main()
{
    // basic print out
    string name = "Phan Nguyen Long";
    int age = 10;
    double age1 = 10.5;
    cout<<"Hello "<< name << "age is: "<< age << endl;
    cout << name.find("heo", 0) << endl;
    cout << string::npos <<endl; // string::nops la ko tim thay trong string..find()
    age > age1 ? cout << age + age1 << endl: cout << "hello" << endl; // short if function
    
    // user input
    int usrAge; // interger input
    cout << "Enter ur age: ";
    cin >> usrAge ;
    cout << "Age is: " << usrAge << endl;
    
    // while (getchar() != '\n'); // must have this or C++ will pass '\n' to next input, bullshit
    fflush(stdin);  // can use this instead of while above to delete '\n'
    
    string usrName; // input string
    cout << "Enter ur name: ";
    getline(cin, usrName);
    cout << "Your name is: " << usrName << endl;

    // array y chang trong C
    // function giong C, C++ co them defaul parameter: được thêm ở prototype ở trên
    sayHello();

    /*=======================BASIC OOP===============================*/

    // classes (nằm ở trên đầu) and object trong C
    Book book1; // define an object with datatype is book
    // can modify content after create
    book1.title = "Long tom";
    book1.author = "the grate long tom";
    book1.pages = 10;
    // calling an object function declare before
    cout << book1.isLongBook() << endl;// return true if pages > 100, this is call object function

    // GETTER and SETTER
    Movie movie1("Titanic", "Long Tom", "bab"); // tạo class movie
    // movie1.rating = "shit" // will cause error cause rating is in private can not be modify here like public
    cout << "Rating of the movie is: " <<movie1.getRating(); // must use the function to get Rating

    // INHERIT (class define ở phía trên)
    Chef myChef;
    myChef.makeChicken();

    ItalianChef myItalianChef;
    myItalianChef.makeChicken();

    return 0;
}

void sayHello( int age, string name) {
    cout << age << "Hello my name is  " << name << endl;
}