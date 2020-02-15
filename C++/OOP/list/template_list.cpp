#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T> class Tlist; // define here to use in Tnode

template <class T>
class Tnode { // this is 1 node in the list
    friend class Tlist<T>; // set Tlist be a friend class
    private: // include 2 things
        T value; // data
        Tnode *next; // pointer to the next node
    public:
        Tnode(): next(NULL) {} // use for dummy node
        Tnode (const T& value) // recieve value and set pointer of
        : value(value), next(NULL) {} // inintial node to NULL
        Tnode * getNext() {return next;}
        template <class X> friend ostream & operator << (ostream & os, Tnode<X> node) { // must friend or it will error (explanin?)
            os << node.value << "->"; // ostream to take and return the output
            return os;
        }
};

// head node -> first node -> ... -> last node -> tail node
template <class T>
class Tlist { // friend with Tnode
    private:
        Tnode<T> * head; // dummy head 
        Tnode<T> * tail; // dummy tail
        Tnode<T> * current;
        int size = 0;
    public:
        Tlist() {
            head = new Tnode<T>; 
            tail = new Tnode<T>; 
            head -> next = tail; // set next of head be the pointer to the last node(tail)
            current = head;
        }
        ~Tlist() {
            clear();
            delete head;
            delete tail;
        }
        void goTop() {current = head -> next;};
        void goLast() {
            while (current->next != tail)  {current = current -> next;} // if current->next is the address of last node (tail) => break
        }
        int getSize() {return size;}
        // head -> ... -> node -> new_node -> ... -> tail
        void insertAfter(const T& node_val) { // insert after
            Tnode<T> * p = new Tnode<T>(node_val);
            p->next = current->next; // point new node to after node
            current->next = p; // point previous node to new node
            current = p; // point current to new node
            size++; // increase size
        }
        // head -> ... -> new_node -> tail
        void append(const T& value) { // add a node at bottom
            goLast();
            insertAfter(value);
            size++;
        }
        // head -> new_node -> ... -> tail
        void prepend(const T& value) {; // add a node at begin
            goTop();
            insertAfter(value);
            size++;
        }
        int find(T index) { // find a node - return -1 if no
            int res = -1, i=0;
            goTop();
            while(current -> next != tail) {
                if (index == current->value) {return i;}
                i++;
            }
            return res;
        }
        T get() {return current->value;} // get a node at current position
        void replace(T content) {current->value = content;} // replace a content of current node
        bool isEmpty() {return size == 0? true: false;} // return true if list is empty
        void remove() { // remove a node at current position
            Tnode<T> * p = current;
            current = current -> next;
            delete p;
            size--;
        }
        void clear() {
            current = head->next;
            while (current->next != tail) {remove();}
            current = head;
            head->next = tail;
            size = 0;
        }
        // handle operation cout <<
        template <class X> friend ostream & operator<< (ostream & os, Tlist<X> node){ // must be type like this
            if (node.isEmpty()) {return os << "Emply list";}
            Tnode<T> *p = node.head->getNext();
            while (p != node.tail) {
                os << *p;
                p = p->getNext();
            }
            return os;
        }
};

int main() {
    
}