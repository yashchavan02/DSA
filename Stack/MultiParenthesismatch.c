#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


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
        printf("Stack Overflow ! Cannot push %d\n", value);
        return -1;
    } else {
        ptr->arr[++ptr->Top] = value; 
        return 0;
    }
}

int Pop(struct Stack *ptr){
    if (IsEmpty(ptr)) {
        printf("Stack Underflow ! Cannot Pop \n");
        return -1;
    } else {
        return ptr->arr[ptr->Top--];
    }
}

int MatchParenthesis(char a , char b){
    if((a =='{') && (b =='}')){
        return 1;
    }

    if((a =='(') && (b ==')')){
        return 1;
    }

    if((a =='[') && (b ==']')){
        return 1;
    }

    return 0;
}

void CheckMatch (struct Stack *S , char *arr) {
    int i;
    for (i = 0; i < strlen(arr); i++) {
        if ((arr[i] == '{') || (arr[i] == '(') || (arr[i] == '[')) {
            Push(S, arr[i]);
        } else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') {
            if (IsEmpty(S)) {
                printf("Mismatched parentheses");
                return;
            } else {
                char pop_element = Pop(S);
                if(!MatchParenthesis(pop_element , arr[i])){
                   printf("Not balanced equation.\n");
                }
            }
        }
    }
    if (!IsEmpty(S)) {
        printf("Mismatched parentheses");
    } else {
        printf("All parentheses are correctly matched\n");
    }
}


int main() {
    struct Stack *S;
    S = (struct Stack*)malloc(sizeof(struct Stack)); 
    S->Top = -1;
    S->size = 20;
    S->arr = (char*)malloc(S->size * sizeof(char));

    char *str = "{(12/2)[-1}";
    strcpy(S->arr, str);

    CheckMatch (S, S->arr);

    free(S->arr);
    free(S); 

    return 0;
}
