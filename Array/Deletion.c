#include <stdio.h>

void DeletionElement(int arr[], int CurrentSize, int Index){
    for (int i =Index; i < CurrentSize; i++){
        arr[i] = arr[i + 1];
      }
}

void PrintArray(int arr[] , int CurrentSize){
    for (int i = 0; i < CurrentSize; i++){
        printf("%d ",arr[i]);
    } 
    printf("\n"); 
} 

int main() {
    int arr[25] = {10, 3, 54, 9, 43, 8 , 5 ,1};
    int TotalSize = sizeof(arr) / sizeof(arr[0]);
    int CurrentSize = 8;
    int Index = 0 ;
    printf("Before Deletion \n");
    PrintArray(arr,CurrentSize);

    DeletionElement(arr, CurrentSize, Index);
    CurrentSize -= 1;
    printf("After Deletion \n");
    PrintArray(arr,CurrentSize);

    return 0;
}