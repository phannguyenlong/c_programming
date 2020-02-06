#include <iostream>
using namespace std;

// inheritance
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


int main() {
    // INHERIT (class define ở phía trên)
    Chef myChef;
    myChef.makeSpecialDish(); // return "The chef makes a special dish"

    ItalianChef myItalianChef;
    myItalianChef.makeSpecialDish(); // return "The chef makes chicken parm"
}