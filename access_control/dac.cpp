#include <iostream>
#include <string>
#include <vector>
using namespace std;

class acmUser {
    private:
        string user_name;
        bool own, read, write, execute;
    public:
        acmUser(string user, bool o=false, bool r=false, bool w=false, bool e=false)
        : user_name(user) ,own(o), read(r), write(r), execute(e) {}
        friend bool Determine(string subject, char action, vector <acmUser*> object); // friend cause it need to access private
};

bool Determine(string subject, char action, vector <acmUser*> object) {
    for (int i=0; i < object.size(); i++) {
        if (subject == object[i]->user_name) {
            if (action == 'o') return object[i]->own;
            else if (action == 'r') return object[i]->read;
            else if (action == 'w') return object[i]->write;
            else if (action == 'e') return object[i]->execute;
        }
    }
    return 0;
}

int main() {
    // init ACM
    vector <acmUser*> file1;
    vector <acmUser*> file2;
    vector <acmUser*> file3;
    vector <acmUser*> file4;
    vector <acmUser*> file5;

    file1.push_back(new acmUser("Alice",true,true,true,true));
    file1.push_back(new acmUser("Bob",false,false,false,true));
    file1.push_back(new acmUser("Maco",false,true,false,false));

    file2.push_back(new acmUser("Alice",false,true,true,false));
    file2.push_back(new acmUser("Bob",false,true,false,false));
    file2.push_back(new acmUser("Oscar",true,true,true,true));
    file2.push_back(new acmUser("Mary",false,true,false,false));

    file3.push_back(new acmUser("Bob",true,true,true,true));
    file3.push_back(new acmUser("Maco",false,false,true,false));
    file3.push_back(new acmUser("Mary",false,true,false,false));

    file4.push_back(new acmUser("Alice",false,true,false,true));
    file4.push_back(new acmUser("Bob",false,false,true,false));
    file4.push_back(new acmUser("Oscar",false,false,false,true));
    file4.push_back(new acmUser("Maco",true,true,true,true));

    file5.push_back(new acmUser("Alice",false,false,true,false));
    file5.push_back(new acmUser("Maco",false,false,false,true));
    file5.push_back(new acmUser("Mary",true,true,true,true));

    // input session
    string user, file_name, res;
    char action;
    cout << "Input user: ";
    getline(cin, user);
    cout << "o - own\nr - read\nw - write\ne - execute\nInput option: ";
    action = getchar();
    cin.get(); // cosume the new line from get char
    cout << "Input file name: ";
    getline(cin, file_name);
    
    if (file_name == "file1") res = Determine(user, action, file1) ? "Access granted": "Permission denied";
    else if (file_name == "file2") res = Determine(user, action, file2) ? "Access granted": "Permission denied";
    else if (file_name == "file3") res = Determine(user, action, file3) ? "Access granted": "Permission denied";
    else if (file_name == "file4") res = Determine(user, action, file4) ? "Access granted": "Permission denied";
    else if (file_name == "file5") res = Determine(user, action, file5) ? "Access granted": "Permission denied";
    else res = "No file found";
    cout << res;
    return 0;
}