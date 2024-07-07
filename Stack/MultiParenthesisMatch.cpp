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

void CheckMatch (struct Stack *S , const char *arr) {
    int i;
    for (i = 0; i < strlen(arr); i++) {
        if ((arr[i] == '{') || (arr[i] == '(') || (arr[i] == '[')) {
            Push(S, arr[i]);
        } else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') {
            if (IsEmpty(S)) {
                cout<<"Mismatched parentheses"<<endl;
                return;
            } else {
                char pop_element = Pop(S);
                if(!MatchParenthesis(pop_element , arr[i])){
                   cout<<"Not balanced equation.\n";
                }
            }
        }
    }
    if (!IsEmpty(S)) {
        cout<<"Mismatched parentheses";
    } else {
        cout<<"All parentheses are correctly matched\n";
    }
}


int main() {
    struct Stack *S;
    S = new struct Stack ; 
    S->Top = -1;
    S->size = 20;
    S->arr = new char[S->size = 20];

    const char *str = "{(12/2)-1}";
    strcpy(S->arr, str);

    CheckMatch (S, S->arr);

    delete S->arr;
    delete S; 

    return 0;
}
