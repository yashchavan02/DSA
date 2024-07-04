#include <iostream>
using namespace std;

struct Node {
    int Data;
    struct Node* next;
};

bool IsEmpty(struct Node* Top) {
    return Top == NULL;
}

bool IsFull() {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    bool full = ptr == NULL;
    delete ptr; 
    return full;
}

struct Node* Push(struct Node* Top, int value) {
    if (IsFull()) {
        cout<<"Stack Overflow ! Cannot push "<<value<<endl;
        return Top;
    } else {
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->Data = value;
        ptr->next = Top;
        Top = ptr;
        return Top;
    }
}

void PrintLinkedList(struct Node* ptr) {
    while (ptr != NULL) {
        cout<<ptr->Data<<" ";
        ptr = ptr->next;
    }
     cout<<endl; 
}

int main() {
    struct Node* Top = NULL;

    Top = Push(Top, 110);
    Top = Push(Top, 111);
    Top = Push(Top, 112);
    Top = Push(Top, 113);
    Top = Push(Top, 114);
    Top = Push(Top, 115);
    Top = Push(Top, 116);
    Top = Push(Top, 117);
    Top = Push(Top, 118);
    Top = Push(Top, 119);
    Top = Push(Top, 120);

    PrintLinkedList(Top);

    bool checkIsEmpty = IsEmpty(Top);

    if(checkIsEmpty==0){
        cout<<"Linkedlist is not Empty it have some elements";
    }
    
    return 0;
}
