#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};

void LinkedList(struct Node *ptr){
    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void LinkedListRevers(struct Node *ptr){
    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
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
    cout<<endl;
    LinkedListRevers(Sixth);
    cout<<endl;
    LinkedListRevers(Fifth);

    
    delete Head;
    delete Second;
    delete Third;
    delete Fourth;
    delete Fifth;
    delete Sixth;

    return 0;
}

