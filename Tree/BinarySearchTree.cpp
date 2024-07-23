#include <iostream>

using namespace std;

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* T = new struct Node;
    if(T == nullptr) {
        cout<< "Memory Is Full."<<endl;
        exit(0);
    }
    else {
        T->left = T->right = nullptr;
        T->Data = data;
        return T;
    }
  delete T;
}

bool IsBST(struct Node* Root ){
    if (Root == nullptr){
        return true;
    }
    bool isLeftLess = IsBST(Root->left) && (Root->left == nullptr || Root->left->Data < Root->Data);
    bool isRightGreater = IsBST(Root->right) && (Root->right == nullptr || Root->right->Data > Root->Data);
  
    return isLeftLess && isRightGreater;
 
}

int main(){

struct Node* T0 = newNode(4) ;   
struct Node* T1 = newNode(2) ;   
struct Node* T2 = newNode(5) ;   
struct Node* T3 = newNode(1) ;   
struct Node* T4 = newNode(3) ;

T0->left = T1;
T1->left = T3;

T0->right = T2;
T1->right = T4;

/*

        4  -- Root
       / \
      2   5 - Child Node Of Root
     / \
    1   3 --- Leaf Node

*/

if(IsBST(T0)){
    cout<<"Binary Tree is a BST"<<endl;
 }
else {
    cout<<"Binary Tree is not a BST"<<endl;
 }  
   return 0;
}