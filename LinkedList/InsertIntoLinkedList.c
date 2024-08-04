#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void LinkedList(struct Node *ptr){
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* InsertAtStart(struct Node* Head, int Data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = Data;
    ptr->next = Head;
    return ptr;
}

struct Node* InsertAtIndex(struct Node* Head, int Data ,int Index) {
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  struct Node *p = Head;
  int i = 0;

  while (i != Index - 1) {
    p = p->next;
    i++;
  }

  ptr->data = Data;
  ptr->next = p->next;
  p->next = ptr;
  
  return Head;
}

struct Node* InsertAfter(struct Node* Head, struct Node* GivenNode, int Data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = Data;
    ptr->next = GivenNode->next; 
    GivenNode->next = ptr; 
    return Head;
}



struct Node* InsertAtEnd(struct Node* Head, int Data) {
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = Data;
  ptr->next = NULL;
  struct Node *p = Head;

  while (p->next != NULL) {
     p = p->next;
  } 

    p->next = ptr; 
    return Head; 
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

    Head->data = 5;
    Head->next = Second;

    Second->data = 7;
    Second->next = Third;

    Third->data = 8;
    Third->next = Fourth;

    Fourth->data = 10;
    Fourth->next = Fifth;

    Fifth->data = 11;
    Fifth->next = Sixth;

    Sixth->data = 12;
    Sixth->next = NULL;

    Head = InsertAtStart(Head, 4);
    Head = InsertAtStart(Head, 3);   
    Head = InsertAtStart(Head, 2);   
    Head = InsertAtStart(Head, 1); 

    Head = InsertAtIndex(Head,6,5);   
    Head = InsertAtIndex(Head,9,8);

    Head = InsertAtEnd(Head, 13);
    Head = InsertAtEnd(Head, 14);
    Head = InsertAtEnd(Head, 16);
    
    struct Node * Temp = (struct Node*)malloc(sizeof(struct Node));
    Temp = Head; 

    while(Temp->data != 14 ) Temp = Temp->next;
                                   
    Head = InsertAfter(Head,Temp,15);
    
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