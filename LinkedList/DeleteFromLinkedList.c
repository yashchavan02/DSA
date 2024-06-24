#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * DeleteFirst(struct Node *Head){
    struct Node *ptr = Head;
    Head = Head->next;
    free(ptr);
    return Head;
}

struct Node * DeleteAtIndex(struct Node *Head, int Index){
    struct Node *p= Head;
    struct Node *q = Head->next;
    for (int i = 0; i < Index - 1; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return Head;
}

struct Node * DeleteLast(struct Node *Head){
    struct Node *p= Head;
    struct Node *q = Head->next;
   while(q->next != NULL){
    p = p->next;
    q = q->next;
   }
    p->next = NULL;
    free(q);
    return Head;
}

struct Node * DeleteGivenData(struct Node *Head , int Data){
    struct Node *p= Head;
    struct Node *q = Head->next;
   while(q->data != Data && q->next != NULL){
     p = p->next;
     q = q->next;
   }
   if(q->data == Data){
      p->next = q->next;
      free(q);
   } else { 
    printf("%d is not found in linkedlist.\n",Data);
   } 
    return Head;
}



void LinkedList(struct Node *Head) {
    struct Node *ptr = Head;
    while (ptr != NULL) {
       printf("%d ",ptr->data);
        ptr = ptr->next;
    }
  printf("\n");
}


int main() {

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

    Head->data = 0;
    Head->next = Second;

    Second->data = 1;
    Second->next = Third;

    Third->data = 2;
    Third->next = Fourth;

    Fourth->data = 3;
    Fourth->next = Fifth;

    Fifth->data = 4;
    Fifth->next = Sixth;

    Sixth->data = 5;
    Sixth->next = NULL;

    LinkedList(Head);
    Head = DeleteAtIndex(Head, 2);
    Head = DeleteFirst(Head);
    Head = DeleteLast(Head);
    Head = DeleteGivenData(Head , 4);
    Head = DeleteGivenData(Head , 7);
    LinkedList(Head);
 

    struct Node *current = Head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

  return 0;

}