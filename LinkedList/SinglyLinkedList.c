#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *ptr){
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

struct Node* Head;
struct Node* Second;
struct Node* Third;
struct Node* Fourth;
struct Node* Fifth;
struct Node* Sixth;

 Head = (struct Node*)malloc(sizeof(struct Node));
 Second = (struct Node*)malloc(sizeof(struct Node));
 Third = (struct Node*)malloc(sizeof(struct Node));
 Fourth = (struct Node*)malloc(sizeof(struct Node));
 Fifth = (struct Node*)malloc(sizeof(struct Node));
 Sixth = (struct Node*)malloc(sizeof(struct Node));

    Head->data = 10;
    Head->next = Second;

    Second->data = 11;
    Second->next = Third;

    Third->data = 12;
    Third->next = Fourth;

    Fourth->data = 13;
    Fourth->next = Fifth;

    Fifth->data = 14;
    Fifth->next = Sixth;

    Sixth->data = 15;
    Sixth->next = NULL;

    LinkedList(Head);
    
    free(Head);
    free(Second);
    free(Third);
    free(Fourth);
    free(Fifth);
    free(Sixth);

    return 0;
}

