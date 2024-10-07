#include <iostream>
using namespace std;

struct Node {
  struct Node *left;
  int Data;
  struct Node *right;
};

struct Node *newNode(int data) {
  struct Node *T = new struct Node;
  if (T == nullptr) {
    cout << "Memory Is Full." << endl;
    exit(0);
  } else {
    T->left = T->right = nullptr;
    T->Data = data;
    return T;
  }
  delete T;
}

int TotalCount(struct Node *Root) {
  if (!Root) {
    return 0;
  }
  return 1 + TotalCount(Root->left) + TotalCount(Root->right);
}

bool isCBT(struct Node *Root, int TotalCount, int i = 0) {
  if (!Root) {
    return 1;
  }
  if (i >= TotalCount) {
    return 0;
  }
  return isCBT(Root->left, TotalCount, 2 * i + 1) &&
         isCBT(Root->right, TotalCount, 2 * i + 2);
}

bool isHeap(struct Node *Root) {
  if (Root->left) {
    if (Root->Data < Root->left->Data) {
      return 0;
    }
    if (!isHeap(Root->left)) {
      return 0;
    }
  }
  if (Root->right) {
    if (Root->Data < Root->right->Data) {
      return 0;
    }
    return isHeap(Root->right);
  }
  return 1;
}

int main() {

  struct Node *T1 = newNode(100);
  struct Node *T2 = newNode(99);
  struct Node *T3 = newNode(97);
  struct Node *T4 = newNode(30);
  struct Node *T5 = newNode(50);

  T1->left = T2;
  T2->left = T4;
  
  T1->right = T3;
  T2->right = T5;

  /*

              100 --- Root
             /   \
            99   97 - Child of Root
           /  \
          30   50 --- Leaf Node

  */

  int totalNodes = TotalCount(T1);
  if (isCBT(T1, totalNodes) && isHeap(T1)) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}