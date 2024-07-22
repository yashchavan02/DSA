#include <iostream>

using namespace std;

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

void Preorder(struct Node* Root){
    if(Root != nullptr){
    cout<<Root->Data<<" ";
    Preorder(Root->left);
    Preorder(Root->right);
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

struct Node* T0 = newNode(110);
struct Node* T1 = newNode(111);
struct Node* T2 = newNode(112);
struct Node* T3 = newNode(113);
struct Node* T4 = newNode(114);

T0->left = T1;
T1->left = T3;

T0->right = T2;
T1->right = T4;

/*

            110  --- Root
           /   \
         111   112 - Child of Root
        /   \
       113  114  --- Leaf Node
        
    ans : 110 111 113 114 112

*/

   Preorder(T0);
    return 0;
}