#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("Stack Overflow ! Cannot push %d\n", value);
        return -1;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return 0;
    }
}

int Pop(struct Stack *ptr){
      if (IsEmpty(ptr)) {
        printf("Stack Underflow ! Cannot Pop \n");
        return -1;
    }
    else {
        int Value = ptr->arr[ptr->top];
        free(ptr->arr);
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

int StackTop(struct Stack *ptr ){
    return ptr->arr[ptr->top];
}

int StackBottom(struct Stack *ptr){
    return ptr->arr[0];
}
int main(){

    struct Stack *S;
    S->top = -1;
    S->size = 25;
    S->arr = (int *)malloc(S->size * sizeof(int));

for(int i = 1; i < 11; i++){
        Push(S,i);
    
}

Pop(S);

for(int i = 1; i < 10; i++){
  printf("%d ",Peek(S,i));
}

printf("\nTop element: %d", StackTop(S));
printf("\nBottom element: %d", StackBottom(S));
    
    return 0;
}
