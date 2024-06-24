#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node * DeleteFirst(struct Node *Head){
    struct Node *ptr = Head;
    Head = Head->next;
    delete ptr;
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
    delete q;
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
    delete q;
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
      delete q;
   } else { 
    cout<<Data<<" is not found in linkedlist."<<endl;
   } 
    return Head;
}



void LinkedList(struct Node *Head) {
    struct Node *ptr = Head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


int main() {

    struct Node *Head = new Node;
    struct Node *Second = new Node;
    struct Node *Third = new Node;
    struct Node *Fourth = new Node;
    struct Node *Fifth = new Node;
    struct Node *Sixth = new Node;

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
    struct Node *next = nullptr;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

  return 0;

}