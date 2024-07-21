#include<iostream>

using namespace std;

struct CirculerQueue {
    int Size;
    int *arr;
    int FrontEnd;
    int BackEnd;
    int Count;
};

bool IsEmpty(struct CirculerQueue* Q){
    return (Q->Count == 0);
}

bool IsFull(struct CirculerQueue* Q){
    return (Q->Count == Q->Size);
}


void EnQueue(struct CirculerQueue* Q , int value){
    if(IsFull(Q)){
        cout<<"Queue Is Overflow ! can not EnQueue "<<value<<endl;
    } else {
        Q->BackEnd = ((Q->BackEnd + 1) % Q->Size);
        Q->arr[Q->BackEnd] = value;
        Q->Count++;
    }
}

int DeQueue(struct CirculerQueue* Q){
    if(IsEmpty(Q)) {
        cout<<"Queue Is Underflow ! can not DeQueue."<<endl;
    } else {
        Q->FrontEnd =  ((Q->FrontEnd + 1) % Q->Size) ;        
        Q->Count--;
        return Q->arr[Q->FrontEnd];
    }
}

void Display(struct CirculerQueue* Q){
    int StartValue = Q->FrontEnd ;
    printf("Your Queue is : ");
    for(int i = 1 ; i <= Q->Count; i++){ 
        cout<<Q->arr[(StartValue + i) % Q->Size]<<" ";
    }
    cout<<endl;
}

int main() {
    struct CirculerQueue* Q = new struct CirculerQueue;
    Q->Size = 10;
    Q->arr = new int[Q->Size];
    Q->Count = Q->FrontEnd = Q->BackEnd = 0;

    EnQueue(Q ,10);
    cout<<"dequeue : "<<DeQueue(Q)<<endl;
    EnQueue(Q ,11);
    EnQueue(Q ,12);
    cout<<"dequeue : "<<DeQueue(Q)<<endl;
    cout<<"dequeue : "<<DeQueue(Q)<<endl;
    EnQueue(Q ,13);
    EnQueue(Q ,14);
    cout<<"dequeue : "<<DeQueue(Q)<<endl;
    cout<<"dequeue : "<<DeQueue(Q)<<endl;
    EnQueue(Q ,15);
    EnQueue(Q ,16);
    EnQueue(Q ,17);
    EnQueue(Q ,18);
    EnQueue(Q ,19);
    EnQueue(Q ,20);
    EnQueue(Q ,21);
    EnQueue(Q ,22);
    EnQueue(Q ,23);
    EnQueue(Q ,24);
    EnQueue(Q ,25);

    Display(Q);

    delete Q->arr;
    delete Q;
    return 0;
}
