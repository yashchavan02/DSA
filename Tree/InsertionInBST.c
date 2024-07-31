#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int Data) {
    struct Node* T = (struct Node*)malloc(sizeof(struct Node));
    if(T == NULL) {
        printf("Memory is full.\n");
        exit(0);
    } else {
        T->left = T->right = NULL;
        T->Data = Data;
        return T;
    }
}

void InsertNode(struct Node** Root, int Data) {
    struct Node* Prev = NULL;
    struct Node* Current = *Root;

    while (Current != NULL) {
        Prev = Current;
        if (Data == Current->Data) {
            printf("Cannot insert %d, already in the tree\n", Data);
            return;
        } else if (Data < Current->Data) {
            Current = Current->left;
        } else {
            Current = Current->right;
        }
    }

    struct Node* Temp = newNode(Data);
    if (Prev == NULL) {
        *Root = Temp; 
    } else if (Data < Prev->Data) {
        Prev->left = Temp;
    } else {
        Prev->right = Temp;
    }
}

void Inorder(struct Node* Root){
    if(Root != NULL){
    Inorder(Root->left);
    printf("%d ",Root->Data);
    Inorder(Root->right);
    }
}

int main() {
    struct Node* T0 = newNode(8);
    struct Node* T1 = newNode(3);
    struct Node* T2 = newNode(10);
    struct Node* T3 = newNode(1);
    struct Node* T4 = newNode(6);
    struct Node* T5 = newNode(14);
    struct Node* T6 = newNode(13);
    struct Node* T7 = newNode(4);
    struct Node* T8 = newNode(7);

    T0->left = T1;
    T1->left = T3;
    T5->left = T6;
    T4->left = T7;
    
    T0->right = T2;
    T1->right = T4;
    T2->right = T5;
    T4->right = T8;

    /*

    Befor :

             8  
           /   \
          3     10
         / \      \
        1   6     14
           / \    /
          4   7  13


    After :

             8  
           /   \
          3     10
         / \   /  \
        1   6 9   14
           / \    /
          4   7  13

    */

    InsertNode(&T0, 9);
    Inorder(T0);
    return 0;
}
