#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class TNode;
class Stack;
typedef TNode* Ref;


class TNode {
  private:
      Ref next;
      int key;
  public:
    TNode(int key, Ref next): key(key), next(next) {}
    int getKey() { return key; }
    friend class Stack;
};

class Stack {
  private:
      Ref s;
  public:
      Stack(): s(NULL) {};
      void push(int key) {
        Ref p = isEmpty() ? new TNode(key, NULL): new TNode(key, s);
        s = p;
      }
      bool pop() {
        if (isEmpty()) return false;
        Ref p = s;
        s = p->next;
        delete p;
        return true;
      }
      bool isEmpty() { return s==NULL; }
      int top () { return s->key; }
};

bool checkBalance(string s) {
  Stack check;
  for (int i=0; i < s.size(); i++) {
    if (s[i] == '(') { check.push(1); }
    else if (s[i] == ')') {
      if (check.isEmpty()) { return false; }
      check.pop();
    }
  }
  return check.isEmpty();
}

int main() {
  // in oder to check ((())) is balance or not (mean check close bracket or not) using stack
  string s;
  cout << "Enter a string: ";
  getline(cin, s);
  cout << s << endl;

  if (checkBalance(s)) { cout << "The string is balance";}
  else { cout << "The string is not balance"; }
}
