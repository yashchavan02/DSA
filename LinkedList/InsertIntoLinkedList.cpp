#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void LinkedList(struct Node *Head) {
    struct Node *ptr = Head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

struct Node* InsertAtStart(struct Node* Head, int Data) {
    struct Node *ptr = new Node;
    ptr->data = Data;
    ptr->next = Head;
    return ptr;
}

struct Node* InsertAtIndex(struct Node* Head, int Data ,int Index) {
  struct Node *ptr = new Node;
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


struct Node* InsertAtEnd(struct Node* Head, int Data) {
  struct Node *ptr = new Node;
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

    struct Node *Head = new Node;
    struct Node *Second = new Node;
    struct Node *Third = new Node;
    struct Node *Fourth = new Node;
    struct Node *Fifth = new Node;
    struct Node *Sixth = new Node;

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
    Head = InsertAtEnd(Head, 15);
    Head = InsertAtEnd(Head, 16);

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