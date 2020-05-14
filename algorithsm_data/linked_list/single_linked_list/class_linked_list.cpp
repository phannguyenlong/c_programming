#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Tnode;
class Tlist;
typedef Tnode* Ref;

class Tnode {
    private:
        int key;
        Ref next;
    public:
        Tnode(Ref next, int key): next(next), key(key) {}
        int getKey() { return key; }
        friend class Tlist;
};

class Tlist {
    private:
        Ref head;
        Ref tail;
        Ref p;
    public:
        Tlist(): head(NULL), tail(NULL) {};
        void insertLast(int val) {
            tail->next = new Tnode(NULL,val);
            tail = tail->next;
        }
        void insertAfter(int val) {
            p->next = new Tnode(p->next, val);
        }
        void insertBefore(int val) {
            int temp = p->key;
            p->key = val;
            insertAfter(temp);
        }
        void insert(int val) {
            p = head;
            if (head == NULL) {
                head = tail = new Tnode(NULL,val);
            } else {
                // input and sorting
                while (p != tail) {
                    if ((p)->key > val) break;
                    p = p->next;
                }
                if (p == tail && p->key < val) insertLast(val);
                else insertBefore(val);
            }
        }
        void printList() {
            for (p = head; p; p=p->next) {
                cout << p->getKey() << " -> ";
            }
            cout << endl;
        }
};

void initalList(Tlist &list) {
    int size;
    cout << "Enter number of element: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        int num = rand()%100;
        cout << num << "\t";
        list.insert(num);
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    Tlist list;
    // list.insert(20);
    // list.insert(30);
    // list.insert(40);
    initalList(list);
    list.printList();
}