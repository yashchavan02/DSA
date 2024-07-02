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

int Peek(struct Stack *ptr , int pos) {
    int element = ptr->top - pos + 1;
    if(pos <= ptr->top + 1 && pos > 0){
        return  ptr->arr[element] ;
    }
    else{
        printf("Index out of range\n");
        return -1;
    }
}

int main(){

    struct Stack *S;
    S->top = -1;
    S->size = 7;
    S->arr = new int[S->size];

for(int i=25; i<30; i++){   
     Push(S,i);
}

Pop(S);

for(int i=1; i<5; i++){   
     cout<<Peek(S,i)<<" ";
}


    delete[] S->arr;
    delete S;
    
    return 0;
}
