#include<iostream>

using namespace std;

typedef class Queue {
    public:
      int Size;
      int *arr;
      int FrontEnd;
      int BackEnd;
}queue;

int IsFull(queue* Q){
    return (Q->BackEnd == ((Q->Size)-1));
}

int IsEmpty(queue* Q){
    return (Q->BackEnd == Q->FrontEnd);
}

int Peek(queue* Q , int Pos){
    Pos-=1;
    return Q->arr[Pos];
}

void EnQueue(queue* Q , int value){
    if(IsFull(Q)){
        cout<<"Queue Is Overflow !"<<endl;
    } else {
        Q->arr[++Q->BackEnd] = value;
    }
}

void DeQueue(queue* Q){
    if(IsEmpty(Q)) {
        cout<<"Queue Is Underflow !"<<endl;
    } else {
        Q->FrontEnd++; 
    }
}

void Display(queue* Q){
    int StartValue = Q->FrontEnd + 1;
    for(int i = StartValue ; i <= Q->BackEnd; i++){ 
        cout<<Q->arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    queue* Q = new queue;
    Q->Size = 25;
    Q->arr = new int[Q->Size];
    Q->FrontEnd = -1;
    Q->BackEnd = -1;

    for(int i = 21 ; i < 31 ; i++){
        EnQueue(Q ,i); 
    }

    for(int i = 0 ; i < 3 ; i++){
        DeQueue(Q); 
    }

    Display(Q);

    delete Q->arr;
    delete Q;
    return 0;
}
