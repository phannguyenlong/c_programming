#include <iostream>
using namespace std;

template <class T> class Tlist;

template <class T>
class Tnode {
    private:
        T value; // value of node
        Tnode *next; // pointer to next node
    public:
        Tnode (Tnode *next): next(next) {}
        Tnode(T value, Tnode *next)
        : value(value), next(next) { cout << "Added new element" << endl;} 
        Tnode<T>* getNext() {return next;}
        template<class X> friend ostream& operator<<(ostream& os, Tnode<X> node) { // config output for Tnode
            os << node.value << "->";
            return os;
        }
        friend class Tlist<T>; // set friend class to accsess to private
};

template <class T>
class Tlist {
    private:
        Tnode<T> *head;
        Tnode<T> *tail;
        Tnode<T> *current;
        int size=0;
    public:
        Tlist() {
            tail = new Tnode<T>(NULL);
            head = new Tnode<T>(tail);
            current = head;
            cout << "List created" << endl;
        }
        void append(T value) {
            goLast(); // to the end of list
            insertAfter(value);
        };
        void prepend(T value) {
            current = head; // set pointer back to top
            insertAfter(value);
            current = head->next;
        }
        void insertAfter(T value) {
            current->next = new Tnode<T> (value, current->next);
            size ++;
        }
        T getValue() { return current->value; }
        bool find(T value) {
            Tnode<T> *ptr = current;
            goFist();
            while (current->next != tail) {
                if (current->value == value) {
                    current = ptr;
                    return 1;
                }
            }
            current = ptr;
            return 0;
        }
        void replace(T value) {current->value = value;}
        void removeAfter() {
            Tnode<T> *ptr = current->next;
            ptr = ptr->next; // get next of the after node
            delete current->next;
            current->next = ptr;
            size--;
        }
        int getSize() {return size;}
        bool isEmpty() {return size == 0;}
        void goLast() {
            while (current->next != tail) { current = current->next; }
        }
        void goFist() { current = head->next; }
        // ouput session
        template <class X> friend ostream& operator<<(ostream& os, Tlist<X> list) {
            Tnode<X> *ptr = (list.head)->getNext(); // use getNext cause next is in private
            while (ptr != list.tail) {
                os << *ptr;
                ptr = ptr->getNext();
            }
            return os;
        }
};

int main() {
    Tlist<int> list;
    list.append(12334);
    list.append(4567234);
    list.prepend(65233);
    cout << list;
}