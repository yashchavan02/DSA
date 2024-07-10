#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int Size;
    int *arr;
    int FrontEnd;
    int BackEnd;
};

int IsFull(struct Queue* Q){
    return (Q->BackEnd == ((Q->Size)-1));
}

int IsEmpty(struct Queue* Q){
    return (Q->BackEnd == Q->FrontEnd);
}

int Peek(struct Queue* Q , int Pos){
    Pos-=1;
    return Q->arr[Pos];
}

void EnQueue(struct Queue* Q , int value){
    if(IsFull(Q)){
        printf("Queue Is Overflow !\n");
    } else {
        Q->arr[++Q->BackEnd] = value;
    }
}

void DeQueue(struct Queue* Q){
    if(IsEmpty(Q)) {
        printf("Queue Is Underflow !\n");
    } else {
        Q->FrontEnd++; 
    }
}

void Display(struct Queue* Q){
    int StartValue = Q->FrontEnd + 1;
    for(int i = StartValue ; i <= Q->BackEnd; i++){ 
        printf("%d ", Q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->Size = 20;
    Q->arr = (int*)malloc((Q->Size)*sizeof(int));
    Q->FrontEnd = -1;
    Q->BackEnd = -1;

    // EnQueue(Q ,9);
    // EnQueue(Q ,10);
    // DeQueue(Q);
    // DeQueue(Q);
    // EnQueue(Q ,11);
    // EnQueue(Q ,12);
    // EnQueue(Q ,13);
    // EnQueue(Q ,14);
    // EnQueue(Q ,15);
    // EnQueue(Q ,16);
    // EnQueue(Q ,17);

    for(int i = 11 ; i < 21 ; i++){
        EnQueue(Q ,i); 
    }

    for(int i = 0 ; i < 5 ; i++){
        DeQueue(Q); 
    }

    Display(Q);

    free(Q->arr);
    free(Q);
    return 0;
}
