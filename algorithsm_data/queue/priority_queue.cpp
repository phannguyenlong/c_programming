#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node;
typedef Node *Ref;

class Node {
    private:
        int key, weight;
        Ref next;

    public:
        Node(int key, int weight, Node* next)
        : key(key), weight(weight), next(next) {}
        Ref getNext() { return next; }

        friend class PriorityQueue;
        friend ostream& operator<< (ostream& os, Node node) {
            os << node.key << "(" << node.weight << ")" << " -> ";
            return os;
        }
};

class PriorityQueue {
    private:
        Ref front, rear;
    public:
        PriorityQueue(): front(NULL), rear(NULL) {}
        void insert(int key, int weight) {
            cout << key << ":" << weight << "\t";
            if (front != NULL) {
                Ref p = front;
                while (p->next) {
                    if(p->next->weight > weight) break;
                    p = p->next;
                }
                if (rear != front) {
                    p->next = new Node(key, weight, p->next);
                    if (p== rear)
                        rear = p->next;
                    if (p == front)
                        front = new Node(key, weight, p);
                } else {
                    if (p->weight <= weight)
                        p->next = rear = new Node(key, weight, p->next);
                    else {
                        front = new Node(key, weight, p);
                    }
                }
            } else {
                front = rear = new Node(key, weight, NULL);
            }
        }
        bool isEmpty() { return front == NULL; }
        friend ostream& operator<<(ostream& os, PriorityQueue queue) {
            for (Ref p = queue.front; p != NULL; p = p->getNext()) {
                os << *p;
            }
            return os;
        }
};

PriorityQueue inputData(PriorityQueue queue, int size) {
    for (int i = 0; i < size; i++) {
        queue.insert(rand() % 20, rand() % 3 + 1);
    }
    return queue;
}

int main() {
    srand(1);
    int size;
    cout << "Enter size: ";
    cin >> size;
    PriorityQueue waiting_list;

    waiting_list = inputData(waiting_list, size);
    cout << endl;
    cout << waiting_list;
}