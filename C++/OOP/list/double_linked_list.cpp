#include <iostream>
using namespace std;

template <class T> class Dblist;

template <class T> 
class Tnode {
    private:
        Tnode* next;
        Tnode* prev;
        T value;
    public:
        Tnode(Tnode* next, Tnode* prev)
        : next(next), prev(prev) {}
        Tnode(Tnode* next, T value)
        : next(next), value(value) {}
        template <class X> friend ostream& operator<<(ostream& os, Tnode<X>& node) {
            os << node.value << " -> ";
            return os;
        }
        friend class Dblist;
};

template <class T>
class Dblist {
    private:
        Tnode<T>* head;
        Tnode<T>* tail;
        Tnode<T>* current;
        int size;
    public:
        Dblist() {
            tail = new Tnode<T>(NULL);
            head = new Tnode<T>(tail);
            current = head;
            cout << "List created" << endl;
        }
        //===============OPERATION Function==============
        void append(T value) {

        }
        void insertAfter(T value) {
            current->next = new Tnode<T>(current->next, value);
            size++;
        }
        void goTop() { current = head-> next; }
        void goLast() { current = tail->prev; }
};

int main() {
    cout << "Hello ";
}