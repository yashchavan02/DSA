#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *arr;
};

bool IsEmpty(struct Stack *ptr) {
    return ptr->top == -1;
}

bool IsFull(struct Stack *ptr) {
    return ptr->top == ptr->size - 1;
}

int Push(struct Stack *ptr , int value){
    if (IsFull(ptr)) {
        cout<<"Stack Overflow ! Cannot push "<< value<<endl;
        return -1;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        cout<<value<<" is pushed."<<endl;
        return 0;
    }
}

int Pop(struct Stack *ptr){
      if (IsEmpty(ptr)) {
        cout<<"Stack Underflow ! Cannot Pop"<<endl;
        return -1;
    }
    else {
        int Value = ptr->arr[ptr->top];
        ptr->top--;
        return Value;
    }  
}

int main(){

    struct Stack *S;
    S->top = -1;
    S->size = 5;
    S->arr = new int[S->size];

    Push(S,25);
    Push(S,26);
    Push(S,27);
    Push(S,28);
    Push(S,29);
    Push(S,30);

    cout<<S->arr[0]<<" is pushed."<<endl;
    cout<<S->arr[1]<<" is pushed."<<endl;
    cout<<S->arr[2]<<" is pushed."<<endl;
    cout<<S->arr[3]<<" is pushed."<<endl;
    cout<<S->arr[4]<<" is pushed."<<endl;

    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);

    delete[] S->arr;
    delete S;
    
    return 0;
}
