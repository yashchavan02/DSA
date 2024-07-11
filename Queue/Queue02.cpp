#include<iostream>

using namespace std;

struct Node {
    int Data;
    struct Node* next;
};

struct Node* FrontEnd = nullptr;
struct Node* BackEnd = nullptr;

bool IsEmpty() {
    return FrontEnd == nullptr;
}

bool IsFull() {
    struct Node* ptr = new struct Node;
    bool full = ptr == nullptr;
    delete ptr;
    return full;
}

struct Node* EnQueue(int value){
    if (IsFull()) {
        cout<<"Queue Overflow! Cannot push "<<value<<endl;
        return FrontEnd;
    } else {
        struct Node* ptr = new struct Node;
        ptr->Data = value;
        ptr->next = nullptr;
        if(IsEmpty()) {
            FrontEnd = BackEnd = ptr;
        } else {
            BackEnd->next = ptr;
            BackEnd = ptr;
        }
        return FrontEnd;
    }
}

int DeQueue() {
    if (IsEmpty()) {
        cout<<"Queue Underflow ! Cannot Pop Element "<<endl;
        return 0;
    } else {
        struct Node* ptr = FrontEnd;
        int value = ptr->Data;
        FrontEnd = FrontEnd->next;
        delete ptr;
        if(FrontEnd == nullptr) {
            BackEnd = nullptr;
        }
        return value;
    }
}

void PrintQueue() {
    struct Node* ptr = FrontEnd;
    while (ptr != nullptr) {
        cout<<ptr->Data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    
    EnQueue(110);
    EnQueue(111);
    EnQueue(112);
    EnQueue(113);
    EnQueue(114);
    EnQueue(115);
    EnQueue(116);
    EnQueue(117);
    EnQueue(118);

    DeQueue();
    DeQueue();

    PrintQueue();

    return 0;
}
