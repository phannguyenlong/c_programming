#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node;
class RBTree;

typedef Node* Ref;
enum COLOR {RED, BLACK};

class Node {
  private:
    int key;
    int color;
    Ref parent, left, right;
  public:
    Node(int key, int color, Ref parent, Ref left, Ref right)
    : key(key), color(color), left(left), right(right), parent(parent) {}
    friend class RBTree;
    friend ostream& operator << (ostream& os, Node node) {
      os << node.key;
      string color = node.color == RED ? "(R)" : "(B)";
      os << color;
      return os;
    }
};

class RBTree {
  private:
    Ref root;
    Ref nill;
  public: 
    RBTree(): root(NULL), nill(new Node(-1, BLACK, nill, nill, nill)) {}
    
    bool insertNode(int key)  {
      if (root) {
        Ref p = root, q;
        while (p != nill) {
          q = p;
          if (p->key > key) p = p->left;
          else if (p->key < key) p = p->right;
          else return false; // mean =
        }  
        if (q->key > key) q->left = new Node(key, RED, q, nill, nill);
        else q->right = new Node(key, RED, q, nill, nill);

        // balance tree
        if (q->color == BLACK) return true; // already balance
        else { // need to rebalance
          while (q->color == RED && q->parent) {
            if (q->parent->left == q)  { // mean q is the sub left tree ==> left adjust
              if (q->parent->right->color == RED) {
                // case 1: parent and uncle is red
                q->color = q->parent->right->color = BLACK;
                if (q->parent != root) q->parent->color = RED;
                q = q->parent;
               } else {
                if (q->right->key == key) { leftRotate(q); } // case 3: rotate left back to case 2
                q->color = BLACK;
                q->parent->color = RED;
                rightRotate(q->parent); // case 2:
               }
            } else { // mean q is the sub right tree ==> right adjust
               if (q->parent->left->color == RED) {
                // case 1: parent and uncle is red
                q->color = q->parent->left->color = BLACK;
                if (q->parent != root) q->parent->color = RED;
                q = q->parent;
               } else {
                if (q->left->key == key) { rightRotate(q); } // case 3: rotate right back to case 2
                q->color = BLACK;
                q->parent->color = RED;
                leftRotate(q->parent); // case 2:
               }
            }
          }
          root->color = BLACK;
        }
      } else root = new Node(key, BLACK, nill, nill, nill);
      return true;
    }
    void leftRotate(Ref q) {
      Ref p = q->right;
      p->parent = q->parent;
      q->right = p->left;
      p->left = q;
      q->parent = p;
      if (p->parent == nill) root = p;
      else {
        if (p->parent->left == q) p->parent->left = p;
        else p->parent->right = p;
      }
    }
    void rightRotate(Ref q) {
      Ref p = q->left;
      p->parent = q->parent;
      q->left = p->right;
      p->right = q;
      q->parent = p;
      if (p->parent == nill) root = p;
      else {
        if (p->parent->left == q) p->parent->left = p;
        else p->parent->right = p;
      }
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
      if (r != nill) {
        cout << *r << "->";
        preOrder(r->left);
        preOrder(r->right);
      }
    }
    void inOrder(Ref r) {
      if (r != nill) {
        inOrder(r->left);
        cout << *r << "->";
        inOrder(r->right);
      }
    } 
    void postOrder(Ref r) {
      if (r != nill) {
        postOrder(r->left);
        postOrder(r->right);
        cout << *r << "->";
      }
    }
    void print2Dtree(Ref r, int space, int direction, bool isSearch=false, int searchKey=0) {
      if (r == nill) return; // base case
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

int main() {
  RBTree tree;
  tree.insertNode(20);
  tree.insertNode(30);
  tree.insertNode(10);
  tree.insertNode(5);
  tree.insertNode(2);
  tree.insertNode(1);
  tree.display();
}
