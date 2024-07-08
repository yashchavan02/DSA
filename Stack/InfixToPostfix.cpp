#include<iostream>
#include<string.h>

using namespace std;

typedef class Stack {
    public:
    int Size;
    int Top;
    char *arr;
} stack;

bool IsFull(stack *S){
  return S->Top == S->Size;
}

int StackTop(stack *S){
    return S->arr[S->Top];
}

bool IsEmpty(stack *S){
  return S->Top == -1;
}

void Push(stack *S , char ch){
   if(IsFull(S)){
    cout<<"Stack is Overflow"<<endl;
   } else {
     S->arr[++S->Top] = ch;
   }
}

int Pop(stack *S){
   if(IsEmpty(S)){
    cout<<"Stack is Underflow"<<endl;
    return 0;
   } else {
     int Popedvalue = S->arr[S->Top];
     S->Top--;
     return Popedvalue;
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

char* InfixToPostfix(const char* Infix){

stack *S = new stack;
  S->Size = 20;
  S->Top = -1;
  S->arr = new char[S->Size]; 

  char* Postfix = new char[strlen(Infix) + 1];
  int i = 0;
  int j = 0;

while(Infix[i] != '\0'){
  if(!Operator(Infix[i])){
     Postfix[j] = Infix[i];
     j++;
     i++;
  } else {
    if(IsEmpty(S) || (Precedence(Infix[i]) > Precedence(StackTop(S)))){
          Push(S,Infix[i]);
          i++;
    } else {
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

const char* Infix = "a+b-c/r+k";
cout<<"Postfix of "<<Infix<<" is "<<InfixToPostfix(Infix)<<endl;
    return 0;
}