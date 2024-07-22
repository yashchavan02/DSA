#include <iostream>

using namespace std;

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

void Inorder(struct Node* Root){
    if(Root != nullptr){
    Inorder(Root->left);
    cout<<Root->Data<<" ";
    Inorder(Root->right);
    }
}

struct Node* newNode(int data) {
    struct Node* T = new struct Node;
    if(T == nullptr) {
        cout<<"Memory Is Full."<<endl;
        exit(0);
    }
    else {
        T->left = T->right = nullptr;
        T->Data = data;
        return T;
    }
  delete T;
}

int main(){

struct Node* T0 = newNode(0);
struct Node* T1 = newNode(1);
struct Node* T2 = newNode(2);
struct Node* T3 = newNode(3);
struct Node* T4 = newNode(4);

T0->left = T1;
T1->left = T3;

T0->right = T2;
T1->right = T4;

/*

            0 --- Root
           / \
          1   2 - Child of Root
         / \
        3   4 --- Leaf Node
        
    ans : 3 1 4 0 2

*/

   Inorder(T0);
    return 0;
}