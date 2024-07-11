#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int Data;
    struct Node* next;
};

struct Node* FrontEnd = NULL;
struct Node* BackEnd = NULL;

bool IsEmpty() {
    return FrontEnd == NULL;
}

bool IsFull() {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    bool full = ptr == NULL;
    free(ptr);
    return full;
}

struct Node* EnQueue(int value){
    if (IsFull()) {
        printf("Queue Overflow! Cannot push %d\n", value);
        return FrontEnd;
    } else {
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->Data = value;
        ptr->next = NULL;
        if(IsEmpty()) {
            FrontEnd = BackEnd = ptr;
        } else {
            BackEnd->next = ptr;
            BackEnd = ptr;
        }
        return FrontEnd;
    }
}

int DeQueue() {
    if (IsEmpty()) {
        printf("Queue Underflow ! Cannot Pop Element \n");
        return 0;
    } else {
        struct Node* ptr = FrontEnd;
        int value = ptr->Data;
        FrontEnd = FrontEnd->next;
        free(ptr);
        if(FrontEnd == NULL) {
            BackEnd = NULL;
        }
        return value;
    }
}

void PrintQueue() {
    struct Node* ptr = FrontEnd;
    while (ptr != NULL) {
        printf("%d ", ptr->Data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    
    EnQueue(10);
    EnQueue(11);
    EnQueue(12);
    EnQueue(13);
    EnQueue(14);
    EnQueue(15);

    DeQueue();
    DeQueue();
    DeQueue();

    PrintQueue();

    return 0;
}
