#include<iostream>
using namespace std;

struct list {
  int data;
  struct list *next;
};

class LinkedList {
  struct list *head;
  public:
  LinkedList(){
    head = nullptr;
  }
  void prepend(int);
  void append(int);
  void pop();
  void popFirst();
  void remove(int);
  void printHead();
  void printTail();
  void printlist();
};

void LinkedList :: prepend(int val){
  struct list *ptr = new list;
  ptr->data = val;
  ptr->next = head;
  head = ptr;
}

void LinkedList :: append(int val){
  struct list *ptr = new list;
  ptr->data = val;
  ptr->next = nullptr;
  if (head == nullptr) {
    head = ptr;
  } else {
    struct list *trav = head;
    while (trav->next != nullptr) {
      trav = trav->next;
    }
    trav->next = ptr;
  }
}

void LinkedList :: pop(){
  if (head == nullptr) {
    cout << "List is empty, can't delete!" << endl;
    return;
  }
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  struct list *trav = head;
  while (trav->next->next != nullptr) {
    trav = trav->next;
  }
  delete trav->next;
  trav->next = nullptr;
}

void LinkedList :: popFirst(){
  if (head == nullptr) {
    cout << "List is empty, can't delete!" << endl;
    return;
  }
  struct list *ptr = head;
  head = ptr->next;
  delete ptr;
}

void LinkedList :: printHead(){
  if (head == nullptr) {
    cout << "List is empty, can't fetch the data!" << endl;
    return;
  }
  cout << head->data << endl;
}

void LinkedList :: printTail(){
  if (head == nullptr) {
    cout << "List is empty, can't fetch the data!" << endl;
    return;
  }
  struct list *trav = head;
  while (trav->next != nullptr) {
    trav = trav->next;
  }
  cout << trav->data << endl;
}

void LinkedList :: remove(int val){
  if (head == nullptr) {
    cout << "List is empty, can't remove!" << endl;
    return;
  }
  if (head->data == val) {
    popFirst();
    return;
  }
  struct list *trav = head;
  while (trav->next != nullptr && trav->next->data != val) {
    trav = trav->next;
  }
  if (trav->next == nullptr) {
    cout << "Value not found!" << endl;
    return;
  }
  struct list *temp = trav->next;
  trav->next = trav->next->next;
  delete temp;
}

void LinkedList :: printlist(){
  struct list *ptr = head;
  while(ptr){
   cout<<ptr->data<<" ";
   ptr = ptr->next;
  }
}

int main(){
  LinkedList lst;
  lst.append(1);
  lst.append(2);
  lst.append(3);
  lst.append(4);
  lst.append(5);
  lst.append(6);
  lst.append(7);
  lst.append(8);
  lst.append(9);
  lst.remove(2);
  lst.pop();
  lst.popFirst();
  lst.printHead();
  lst.printTail();
  lst.printlist(); 
  return 0;
}
