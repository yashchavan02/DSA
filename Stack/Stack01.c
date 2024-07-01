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
        printf("%d is pushed.\n", value);
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

int main(){

    struct Stack *S;
    S->top = -1;
    S->size = 5;
    S->arr = (int *)malloc(S->size * sizeof(int));

    Push(S,25);
    Push(S,26);
    Push(S,27);
    Push(S,28);
    Push(S,29);
    Push(S,30);

    printf("%d is in array \n" ,S->arr[0]);
    printf("%d is in array \n" ,S->arr[1]);
    printf("%d is in array \n" ,S->arr[2]);
    printf("%d is in array \n" ,S->arr[3]);
    printf("%d is in array \n" ,S->arr[4]);

    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    
    return 0;
}
