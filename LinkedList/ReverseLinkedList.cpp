#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node* ReverseLL(struct Node** Head) {
    struct Node* Prev = nullptr;
    struct Node* Curr = *Head;
    struct Node* Next = nullptr;
    while (Curr != nullptr) {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    *Head = Prev;

    return *Head;
}

void PrintLL(struct Node* Head){
   while(Head != nullptr){
      cout<<Head->data<<" ";
      Head = Head->next;
   }
}

int main(){

struct Node* Head = new struct Node;
struct Node* Second = new struct Node;
struct Node* Third = new struct Node;
struct Node* Fourth = new struct Node;
struct Node* Fifth = new struct Node;
struct Node* Sixth = new struct Node;

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
Sixth->next = nullptr;

 PrintLL(ReverseLL(&Head));

 delete Head;
 delete Second;
 delete Third;
 delete Fourth;
 delete Fifth;
 delete Sixth;

  return 0;
}

