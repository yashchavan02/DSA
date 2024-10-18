#include <climits>
#include <cstdio>

using namespace std;

struct node {
  int data;
  node *next;
};

class linkedlist {
private:
  node *head;
  node *tail;

public:
  linkedlist() {
    head = nullptr;
    tail = nullptr;
  }
  void insert(int val) {
    node *newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    if (!(head && tail)) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  void display() {
    node *trav = head;
    while (trav) {
      printf("%d ", trav->data);
      trav = trav->next;
    }
  }
  friend void swapNode(linkedlist &l);
};

void swapNode(linkedlist &l) {
  if (!(l.head || l.head->next))
    return;
  node *dummy = new node;
  dummy->data = INT_MIN;
  dummy->next = l.head;
  node *curr = dummy;
  node *ptr1 = l.head;
  node *ptr2 = l.head->next;
  while (ptr1 && ptr2) {
    curr->next = ptr2;
    ptr1->next = ptr2->next;
    ptr2->next = ptr1;
    if (!curr->next)
      return;
    if (!curr->next->next)
      return;
    curr = ptr1;
    ptr1 = ptr1->next;
    if (ptr1)
      ptr2 = ptr1->next;
  }
  l.head = dummy->next;
  delete dummy;
}

int main() {
  linkedlist l;
  l.insert(10);
  l.insert(11);
  l.insert(12);
  l.insert(13);
  l.insert(14);
  l.insert(15);
  l.insert(16);
  swapNode(l);
  l.display();
  return 0;
}