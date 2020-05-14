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

void createList() {
  cout << "Hello Wordl";
}

int main() {
    srand(1);
    Ref head = NULL, tail = NULL;
    createList();
}
