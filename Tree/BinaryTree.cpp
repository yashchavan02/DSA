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

int main(){

struct Node* T1 = newNode(10);
struct Node* T2 = newNode(11);
struct Node* T3 = newNode(12);
struct Node* T4 = newNode(13);
struct Node* T5 = newNode(14);

T1->left = T2;
T2->left = T4;

T1->right = T3;
T2->right = T5;

/*

            10
           /  \
          11  12
         /  \
        13  14

*/

    return 0;
}