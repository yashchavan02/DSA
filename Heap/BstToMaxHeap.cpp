#include <iostream>
#include <vector>
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

void fillData(struct Node *Root, vector<int> &temp , int &i){
  if(!Root){
   return;
  } 
  fillData(Root->left,temp,i);
  fillData(Root->right,temp,i);
  Root->Data = temp[i];
  i++;
}

void inorderPush(struct Node *Root, vector<int> &temp) {
  if (Root) {
    inorderPush(Root->left, temp);
    temp.push_back(Root->Data);
    inorderPush(Root->right, temp);
  }
}

void inorderTrav(struct Node *Root) {
  if (Root) {
    inorderTrav(Root->left);
    cout<<Root->Data<<" ";
    inorderTrav(Root->right);
  }
}

int main() {

  vector<int> temp;

  struct Node *T0 = newNode(4);
  struct Node *T1 = newNode(2);
  struct Node *T2 = newNode(5);
  struct Node *T3 = newNode(1);
  struct Node *T4 = newNode(3);

  T0->left = T1;
  T1->left = T3;

  T0->right = T2;
  T1->right = T4;

  inorderPush(T0, temp);
  int i = 0;
  fillData(T0,temp,i);
  inorderTrav(T0);
  
  return 0;
}