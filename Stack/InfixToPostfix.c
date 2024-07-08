#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Stack {
    int Top;
    int Size;
    char* arr;
};

bool IsEmpty(struct Stack *ptr) {
    return ptr->Top == -1;
}

bool IsFull(struct Stack *ptr) {
    return ptr->Top == ptr->Size - 1;
}

int StackTop(struct Stack *ptr ){
    return ptr->arr[ptr->Top];
}

int Push(struct Stack *ptr , int value){
    if (IsFull(ptr)) {
        printf("Stack Overflow ! Cannot push %d\n", value);
        return -1;
    } else {
        ptr->Top++;
        ptr->arr[ptr->Top] = value;
        return 0;
    }
}

int Pop(struct Stack *ptr){
    if (IsEmpty(ptr)) {
        printf("Stack Underflow ! Cannot Pop \n");
        return -1;
    } else {
        int Value = ptr->arr[ptr->Top];
        ptr->Top--;
        return Value;
    }
}

int Precedence(char ch) {
    if(ch=='?' || ch==':'){
        return 3;
    }
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else
        return 0;
}

int Operator(char ch){
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-' ||ch=='?' || ch==':'){
        return 1;
    }
    return 0;
}

char* InfixToPostfix(char* Infix) {
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
    S->Size = 25;
    S->Top = -1;
    S->arr = (char*)malloc(S->Size*sizeof(char));
    char* Postfix = (char*)malloc((strlen(Infix)+1)*sizeof(char));
    int i = 0;
    int j = 0;
    while(Infix[i] != '\0'){
        if(!Operator(Infix[i])){
            Postfix[j] = Infix[i] ;
            j++;
            i++;
        }
        else {
            if(IsEmpty(S) || Precedence(Infix[i]) > Precedence(StackTop(S))){
                Push(S,Infix[i]);
                i++;
            }
            else{
                Postfix[j] = Pop(S);
                j++;
            }
        }
    }
    while(!IsEmpty(S)){
        Postfix[j] = Pop(S);
        j++;
    }
    Postfix[j] = '\0';
    return Postfix;
}

int main(){
    char* Infix = "a+b-c/r";
    printf("The Postfix is %s",InfixToPostfix(Infix));
    return 0;
}

