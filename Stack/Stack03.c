#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int Data;
    struct Node* next;
};

bool IsEmpty(struct Node* Top) {
    return Top == NULL;
}

bool IsFull() {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    bool full = ptr == NULL;
    free(ptr); 
    return full;
}

struct Node* Push(struct Node* Top, int value) {
    if (IsFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return Top;
    } else {
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->Data = value;
        ptr->next = Top;
        Top = ptr;
        return Top;
    }
}

int Pop(struct Node** Top) {
    if (IsEmpty(*Top)) {
        printf("Stack Underflow ! Cannot Pop Element \n");
        return 0;
    } else {
        struct Node* ptr = *Top;
        int value = ptr->Data;
        *Top = ptr->next;
        free(ptr);
        return value;
    }
}

void PrintLinkedList(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->Data);
        ptr = ptr->next;
    }
    printf("\n"); 
}

int main() {
    struct Node* Top = NULL;

    Top = Push(Top, 10);
    Top = Push(Top, 11);
    Top = Push(Top, 12);
    Top = Push(Top, 13);
    Top = Push(Top, 14);
    Top = Push(Top, 15);
    Top = Push(Top, 16);
    Top = Push(Top, 17);
    Top = Push(Top, 18);
    Top = Push(Top, 19);
    Top = Push(Top, 20);

    printf("Popped element: %d\n", Pop(&Top));

    PrintLinkedList(Top);


    bool checkIsEmpty = IsEmpty(Top);

    if(checkIsEmpty==0){
        printf("Have some elements in linkedlist");
    }
    
    return 0;
}
