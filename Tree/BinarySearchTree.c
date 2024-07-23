#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    if(T == NULL) {
        printf("Memory Is Full.\n");
        exit(0);
    }
    else {
        T->left = T->right = NULL;
        T->Data = data;
        return T;
    }
  free(T);
}

bool IsBST(struct Node* Root ){
    if (Root == NULL){
        return true;
    }
    bool isLeftLess = IsBST(Root->left) && (Root->left == NULL || Root->left->Data < Root->Data);
    bool isRightGreater = IsBST(Root->right) && (Root->right == NULL || Root->right->Data > Root->Data);
  
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
    printf("Binary Tree is a BST\n");
 }
else {
    printf("Binary Tree is not a BST\n");
 }  
   return 0;
}