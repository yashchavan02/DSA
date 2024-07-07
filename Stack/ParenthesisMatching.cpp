#include<iostream>
#include<string.h>
using namespace std;

struct Stack {
    int Top;
    int size;
    char *arr;
};

bool IsEmpty(struct Stack *ptr) {
    return ptr->Top == -1;
}

bool IsFull(struct Stack *ptr) {
    return ptr->Top == ptr->size - 1;
}

int Push(struct Stack *ptr , int value){
    if (IsFull(ptr)) {
        cout<<"Stack Overflow ! Cannot push "<<value<<endl;
        return -1;
    } else {
        ptr->arr[++ptr->Top] = value;
        return 0;
    }
}

int Pop(struct Stack *ptr){
    if (IsEmpty(ptr)) {
        cout<<"Stack Underflow ! Cannot Pop "<<endl;
        return -1;
    } else {
        return ptr->arr[ptr->Top--];
    }
}

void CheckMatch (struct Stack *S , const char *arr) {
    int i;
    for (i = 0; i < strlen(arr); i++) {
        if (arr[i] == '(') {
            Push(S, arr[i]);
        } else if (arr[i] == ')') {
            if (IsEmpty(S)) {
                cout<<"Mismatched parentheses"<<endl;
                return;
            } else {
                Pop(S);
            }
        }
    }
    if (!IsEmpty(S)) {
        cout<<"Mismatched parentheses"<<endl;
    } else {
        cout<<"All parentheses are correctly matched"<<endl;
    }
}

int main() {
    struct Stack *S;
    S = new struct Stack;
    S->Top = -1;
    S->size = 20;
    S->arr = new char[S->size];
    const char *str = "((12/2)-1)";
    strcpy(S->arr, str);
    CheckMatch (S, str);
    delete[] S->arr;
    delete S;
    return 0;
}
