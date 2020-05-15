#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node;
typedef Node* Ref;

struct Node {
  int val;
  Ref next;
  Ref prev;
};

Ref getNode(int val, Ref prev, Ref next) {
  Ref p = new Node;
  p->next = next;
  p->prev = prev;
  p->val = val;
  return p;
}

int createList(Ref &head, Ref &tail) {
  int size;
  cout << "Enter size: ";
  cin >> size;
  Ref p = getNode(rand()%20, NULL, NULL);
  head = p;
  for (int i=0; i < size; i++) {
    p->next = getNode(rand()%20, p, NULL);
    p = p->next;
  }
  tail = p;
  return size;
}
void printList(Ref head, int size) {
  for (Ref p=head; p != NULL; p=p->next) {
    cout << p->val << "\t";
  }
  cout << endl;
}
void clearList(Ref &head, Ref &tail) {
  while(head) {
    head = head->next;
    delete head->prev;
    head->prev = NULL;
  }
  tail = NULL;
}

void insertBefore(int val, Ref node) {
  node->prev = getNode(val, node->prev, node);
  (node->prev)->prev->next = node->prev;
}
void insertAfter(int val, Ref node) {
  node->next = getNode(val, node, node->next);
  (node->next)->next->prev = node->next;
}
void prepend(int val, Ref &head, Ref &tail) {
  if (head) {
    head = getNode(val, NULL, head);
    head->next->prev = head;
  } else {
    head = tail = getNode(val, NULL, NULL);
  }
}
void append(int val, Ref &head, Ref &tail) {
  if (head) {
    tail = getNode(val, tail, NULL);
    tail->prev->next = tail;
  }else {
    head = tail = getNode(val, NULL, NULL);
  }
}

int main() {
  srand(1);
  Ref head = NULL, tail = NULL;
  int size = createList(head, tail);
  cout << "Before: ";
  printList(head, size);

  append(200, head, tail);
  prepend(100, head, tail);
  cout << "After: ";
  printList(head, size);

  // Sum of large large number 
  //int num_size;
  //cout << "How many digit you want: ";
  //cin >> num_size;
}




