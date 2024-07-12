#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct CirculerQueue {
    int Size;
    int *arr;
    int FrontEnd;
    int BackEnd;
    int Count;
};

bool IsEmpty(struct CirculerQueue* Q){
    return (Q->Count == 0);
}

bool IsFull(struct CirculerQueue* Q){
    return (Q->Count == Q->Size);
}


void EnQueue(struct CirculerQueue* Q , int value){
    if(IsFull(Q)){
        printf("Queue Is Overflow ! can not EnQueue %d \n",value);
    } else {
        Q->BackEnd = ((Q->BackEnd + 1) % Q->Size);
        Q->arr[Q->BackEnd] = value;
        Q->Count++;
    }
}

int DeQueue(struct CirculerQueue* Q){
    if(IsEmpty(Q)) {
        printf("Queue Is Underflow ! can not DeQueue.\n");
    } else {
        Q->FrontEnd =  ((Q->FrontEnd + 1) % Q->Size) ;        
        Q->Count--;
        return Q->arr[Q->FrontEnd];;
    }
}

void Display(struct CirculerQueue* Q){
    int StartValue = Q->FrontEnd ;
    printf("Your Queue is : ");
    for(int i = 1 ; i <= Q->Count; i++){ 
        printf("%d ", Q->arr[(StartValue + i) % Q->Size]);
    }
    printf("\n");
}

int main() {
    struct CirculerQueue* Q = (struct CirculerQueue*)malloc(sizeof(struct CirculerQueue));
    Q->Size = 10;
    Q->arr = (int*)malloc((Q->Size)*sizeof(int));
    Q->Count = Q->FrontEnd = Q->BackEnd = 0;

    EnQueue(Q ,10);
    printf("dequeue -> %d \n",DeQueue(Q));
    EnQueue(Q ,11);
    EnQueue(Q ,12);
    printf("dequeue -> %d \n",DeQueue(Q));
    printf("dequeue -> %d \n",DeQueue(Q));
    EnQueue(Q ,13);
    EnQueue(Q ,14);
    printf("dequeue -> %d \n",DeQueue(Q));
    printf("dequeue -> %d \n",DeQueue(Q));
    EnQueue(Q ,15);
    EnQueue(Q ,16);
    EnQueue(Q ,17);
    EnQueue(Q ,18);
    EnQueue(Q ,19);
    EnQueue(Q ,20);
    EnQueue(Q ,21);
    EnQueue(Q ,22);
    EnQueue(Q ,23);
    EnQueue(Q ,24);
    EnQueue(Q ,25);

    Display(Q);

    free(Q->arr);
    free(Q);
    return 0;
}
