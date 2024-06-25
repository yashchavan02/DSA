#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *Head){
  struct Node *ptr = Head;
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != Head);
}

int main(){

    struct Node *Head = new Node;
    struct Node *Second = new Node;
    struct Node *Third = new Node;
    struct Node *Fourth = new Node;
    struct Node *Fifth = new Node;
    struct Node *Sixth = new Node;

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

    delete Head;
    delete Second;
    delete Third;
    delete Fourth;
    delete Fifth;
    delete Sixth;

    return 0;
}
