#include <stdio.h>
#include <stdlib.h>

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