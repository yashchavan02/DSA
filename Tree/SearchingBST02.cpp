#include <iostream>

using namespace std;

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* T = new struct Node;
    if(T == NULL) {
        cout<<"Memory Is Full."<<endl;
        exit(0);
    }
    else {
        T->left = T->right = NULL;
        T->Data = data;
        return T;
    }
  delete T;
}

bool Search(struct Node* Root, int Key) {
    while (Root != NULL) {
        if (Root->Data == Key) {
            return true;
        }
        Root = (Key < Root->Data) ? Root->left : Root->right;
    }
    return false;
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

if(Search(T0,6)){
    cout<<"Element Is Present.";
}
else{
    cout<<"Elements Is Not Present.";
}
   return 0;
}