#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Tnode;
class Queue;
typedef Tnode* Ref;

class Tnode {
  private:
    Ref next;
    int key;
  public:
    Tnode(int key, Ref next): key(key), next(next) {}
    int getKey() { return key; }
    Ref getNext() { return next; }
    
    friend class Queue;
    friend ostream& operator<< (ostream& os, Tnode node) {
      os << node.key << "->";
      return os;
    }
};

// front -> a2 -> a3 -> ... -> rear
class Queue {
  private:
    Ref front;
    Ref rear;
  public:
    Queue(): front(NULL), rear(NULL) {}
    void enQueue(int key) { // add to last (right)
      if (isEmpty()) {
        front = rear = new Tnode(key, NULL);
      } else {
        rear->next = new Tnode(key, NULL);
        rear = rear->next;
      }

    }
    void deQueue() { // remove at first (one the left)
      Ref p = front;
      front = front->next;
      delete p;
    }

    int readFront() { return (*front).key; }
    bool isEmpty() { return front == NULL; }

    friend ostream& operator<< (ostream& os, Queue list) {
      for (Ref p = list.front; p != NULL; p = p->getNext()) {
        os << *p;
      }
      return os;
    }
};

int main() {
  Queue list;
  cout << "Inserted the list:";
  list.enQueue(20);
  list.enQueue(30);
  cout << list ;

  cout << "\nUnqueue 1 element from list: ";
  list.deQueue();
  cout << list;
}
