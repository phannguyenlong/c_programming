#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node;
class binaryTree;
typedef Node* Ref;

class Node {
  private:
      int key;
      Ref left, right;
  public:
      Node(int key, Ref left, Ref right): key(key), left(left), right(right) {};
      friend class binaryTree;
      friend ostream& operator<< (ostream& os, Node node) {
        os << node.key;
        return os;
      }
};

class binaryTree {
  private:
    Ref root;
  public:
    binaryTree(): root(NULL) {};

    bool insertNode(int key){
      if (root) {
        Ref p = root, q; // q to hold the previous node
        while (p) {
          q = p;
          if (p->key < key) {
            p = p->right;
          } else if (p->key > key) {
            p = p->left;
          } else {  // mean = ==> already exist ==> break
            return false;
          }
        }
        if (q->key < key) { q->right = new Node(key, NULL, NULL);  }
        else { q->left = new Node(key, NULL, NULL); }
      } else { root = new Node(key, NULL, NULL); }
      return true;
    }
    bool deleteNode(int key) { // this will find the key in tree | if it has 2 child ==> find Predecessor to replace the node delete
      Ref p = root, *q; // q is pass by referrence of q->left or q->right
      while (p) {
        if ((p)->key < key) { q = &(p->right); p = (p)->right; }
        else if ((p)->key > key) { q = &(p->left); p = (p)->left; }
        else { // mean =
          if ((p)->left == NULL) *q = ((p)->right);
          else if ((p)->right == NULL) *q = ((p)->left);
          else {
            while (p->right) p = p->right;
            int temp = p->key;
            deleteNode(p->key);
            (*q) -> key = temp;
          }
          break;
        }
      }
      delete p;
      return p ? true: false; // if p== NULL ==> p has run to the end ==> not found node to delete ==> false 
    }
    bool searchTree(int key) {
      Ref p = root;
      while (p) {
        if (p->key < key) {p = p->right;}
        else if (p->key > key) { p = p->left; }
        else { 
          cout << "Found " << key << " in the tree: " << endl;
          print2Dtree(root, 0, 0, true, key); 
          return true;
        }
      }
      return false;
    }

    void display() {
      cout << "Pre-order display: ";
      preOrder(root);
      cout << "\nIn-order display: ";
      inOrder(root);
      cout << "\nPost-oder display: ";
      postOrder(root);
      cout << "\n2D tree: " << endl;
      print2Dtree(root, 0, 0);
      cout << endl;
    }
    void preOrder(Ref r) {
      if (r) {
        cout << *r << "->";
        preOrder(r->left);
        preOrder(r->right);
      }
    }
    void inOrder(Ref r) {
      if (r) {
        inOrder(r->left);
        cout << *r << "->";
        inOrder(r->right);
      }
    } 
    void postOrder(Ref r) {
      if (r) {
        postOrder(r->left);
        postOrder(r->right);
        cout << *r << "->";
      }
    }
    void print2Dtree(Ref r, int space, int direction, bool isSearch=false, int searchKey=0) {
      if (r == NULL) return; // base case
      space += 5; // space between level
      print2Dtree(r->right, space, 1, isSearch, searchKey); // process right node

      // priting session
      cout << endl;
      for (int i = 8; i < space; i++) { cout << " "; }
      if (direction == 1) {cout << ".----"; } // 1 mean left
      else if (direction == 2) { cout << "`----"; } // 2 mean right
      cout << *r;
      if (isSearch)
        if (r->key == searchKey) cout << "(*)";

      print2Dtree(r->left, space, 2, isSearch, searchKey); // process left child

    }
};

binaryTree inputData() {
  binaryTree tree;
  int size;
  cout << "Enter number of node: ";
  cin >> size;
  for (int i=0; i < size; i++) {
    tree.insertNode(rand() % 20);
  }
  return tree;
}

int main() {
  binaryTree tree;
  srand(1);

  tree = inputData();
  tree.display();

  int option=1, key;
  while (option) {
    cout << "\n0 - exit\n1 - Display tree\n2 - Search for key\n3 - Delete\n4 - Insert node\n";
    cout << "Enter your option: ";
    cin >> option;
    switch (option) {
      case 1: 
        tree.display();
        break;
      case 2:
        cout << "Enter key to search: ";
        cin >> key;
        if (tree.searchTree(key) == false) cout << "Key not in the tree" << endl;
        break;
      case 3:
        cout << "Enter key to delete: ";
        cin >> key;
        if (tree.deleteNode(key) == false) cout << "Key not in the tree" << endl;
        break;
      case 4:
        cout << "Enter key to insert: ";
        cin >> key;
        if (tree.insertNode(key) == false) cout << "Key is already in the tree" << endl;
      case 0:
      case '\n':
        break;
      defaul:
        cout << "Wrong input. Try again \n";
        break;    
    }
  }
}
