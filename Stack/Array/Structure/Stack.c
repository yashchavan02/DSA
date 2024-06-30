#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

bool IsEmpty(struct Stack *ptr){
    return ptr->top == -1;
}

bool IsFull(struct Stack *ptr){
    return ptr->top == ptr->size - 1;
}

int main(){

    struct Stack *S;
    S->top = -1;
    S->size = 5;
    S->arr = (int *)malloc(S->size * sizeof(int));


    if (IsEmpty(S)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }


    if (IsFull(S)){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }

    return 0;
}
