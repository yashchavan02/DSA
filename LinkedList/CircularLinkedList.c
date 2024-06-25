#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *Head){
  struct Node *ptr = Head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr != Head);
}

int main(){

    struct Node *Head ;
    struct Node *Second ;
    struct Node *Third ;
    struct Node *Fourth ;
    struct Node *Fifth ;
    struct Node *Sixth ;

   Head = (struct Node*)malloc(sizeof(struct Node));
   Second = (struct Node*)malloc(sizeof(struct Node));
   Third  = (struct Node*)malloc(sizeof(struct Node));
   Fourth = (struct Node*)malloc(sizeof(struct Node));
   Fifth = (struct Node*)malloc(sizeof(struct Node));
   Sixth = (struct Node*)malloc(sizeof(struct Node));

    Head->data = 1;
    Head->next = Second;

    Second->data = 2;
    Second->next = Third;

    Third->data = 3;
    Third->next = Fourth;

    Fourth->data = 4;
    Fourth->next = Fifth;

    Fifth->data = 5;
    Fifth->next = Sixth;

    Sixth->data = 6;
    Sixth->next = Head;

    LinkedList(Head);

    free(Head);
    free(Second);
    free(Third);
    free(Fourth);
    free(Fifth);
    free(Sixth);

    return 0;
}
