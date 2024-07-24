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

bool Search(struct Node* Root, int Key) {
    if (Root == NULL){
        return false;
    } 
    if (Root->Data == Key){
        return true;
    } 
    else if (Key < Root->Data){
        return Search(Root->left, Key);
    } 
    else{
        return Search(Root->right, Key);
    }
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
if(Search(T0,4)){
    printf("Element Is Present.");
}
else{
    printf("Elements Is Not Present.");
}
   return 0;
}