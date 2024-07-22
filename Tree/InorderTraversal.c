#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int Data;
    struct Node* right;
};

void Inorder(struct Node* Root){
    if(Root != NULL){
    Inorder(Root->left);
    printf("%d ",Root->Data);
    Inorder(Root->right);
    }
}

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