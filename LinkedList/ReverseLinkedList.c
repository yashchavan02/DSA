#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* ReverseLL(struct Node** Head) {
    struct Node* Prev = NULL;
    struct Node* Curr = *Head;
    struct Node* Next = NULL;
    while (Curr != NULL) {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    *Head = Prev;

    return *Head;
}

void PrintLL(struct Node* Head){
   while(Head != NULL){
      printf("%d ",Head->data);
      Head = Head->next;
   }
}

int main(){

struct Node* Head = (struct Node*)malloc(sizeof(struct Node));
struct Node* Second = (struct Node*)malloc(sizeof(struct Node));
struct Node* Third = (struct Node*)malloc(sizeof(struct Node));
struct Node* Fourth = (struct Node*)malloc(sizeof(struct Node));
struct Node* Fifth = (struct Node*)malloc(sizeof(struct Node));
struct Node* Sixth = (struct Node*)malloc(sizeof(struct Node));

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

 PrintLL(ReverseLL(&Head));

 free(Head);
 free(Second);
 free(Third);
 free(Fourth);
 free(Fifth);
 free(Sixth);

    return 0;
}

