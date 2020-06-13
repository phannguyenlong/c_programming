#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node;
typedef Node* Ref;

struct Node {
	int val; 
	Ref next;
};

Ref getNode(int val, Ref next) {
    Ref p = new Node;
    p->next = next;
    p->val = val;
    return p;
}

void createList(Ref &head, Ref &tail) {
    int size;
    cout << "Enter list length: ";
    cin >> size;
    head = getNode(rand() % 20, NULL);
    Ref p = head;
    for (int i=0; i < size; i++) {
        p->next = getNode(rand() % 20, NULL);
        p = p->next;
    }
    tail = p;
}

void filterNode (Ref &head, Ref &tail) {
    Ref p = head;
    while (p->next != NULL) {
        if (p->val % 2 == 0) {
            Ref remove = p;
            p = p->next;
            delete remove;
        }
    }
}

void printList(Ref &head, Ref &tail) {
    Ref p = head;
    while (p != NULL) {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}

void bubbleSort(Ref &head) {
    for (Ref p = head; p != NULL; p=p->next) {
        for (Ref q = p->next; q != NULL; q = q->next) {
            if (p->val > q->val) {
                int temp = q->val;
                q->val = p->val;
                p->val = temp;
            }
        }
    }
}
void takeTurnSort(Ref &head, Ref &tail) { // this will place 1st max at pos 1, 1 min at pos 2, 2nd max pos 3, ...
  for (Ref tmp_head = head; tmp_head != NULL && tmp_head->next != NULL; tmp_head = tmp_head->next->next)
    for (Ref p = tmp_head->next->next; p != NULL; p = p->next) {
      if (p->val > tmp_head->val)
        swap(tmp_head->val, p->val);
      if (p->val < tmp_head->next->val) 
        swap(tmp_head->next->val, p->val);
    }
}

void quickSort(Ref head, Ref tail) {
    
}

int main() {
	srand(1);
    Ref head = NULL, tail = NULL, p;
    createList(head, tail);
    cout << "Before: ";
    printList(head, tail);
    bubbleSort(head);
    cout << "After: ";
    printList(head, tail);
}
