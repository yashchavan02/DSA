#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};

void LinkedList(struct Node *ptr){
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void LinkedListRevers(struct Node *ptr){
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
}

int main(){

    struct Node *Head;
    struct Node *Second;
    struct Node *Third;
    struct Node *Fourth;
    struct Node *Fifth;
    struct Node *Sixth;

    Head = (struct Node*)malloc(sizeof(struct Node));
    Second = (struct Node*)malloc(sizeof(struct Node));
    Third = (struct Node*)malloc(sizeof(struct Node));
    Fourth = (struct Node*)malloc(sizeof(struct Node));
    Fifth = (struct Node*)malloc(sizeof(struct Node));
    Sixth = (struct Node*)malloc(sizeof(struct Node));



    Head->data = 1;
    Head->next = Second;
    Head->prev = NULL;

    Second->data = 2;
    Second->next = Third;
    Second->prev = Head;

    Third->data = 3;
    Third->next = Fourth;
    Third->prev = Second;

    Fourth->data = 4;
    Fourth->next = Fifth;
    Fourth->prev = Third;

    Fifth->data = 5;
    Fifth->next = Sixth;
    Fifth->prev = Fourth;

    Sixth->data = 6;
    Sixth->next = NULL;
    Sixth->prev = Fifth;

    LinkedList(Head);
    printf("\n");
    LinkedListRevers(Sixth);
    printf("\n");
    LinkedListRevers(Fifth);

    
    free(Head);
    free(Second);
    free(Third);
    free(Fourth);
    free(Fifth);
    free(Sixth);

    return 0;
}

