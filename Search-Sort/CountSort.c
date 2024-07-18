#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void CountSort(int arr[] , int Size){
    int MaxElement = INT_MIN;
    for(int i = 0; i < Size; i++){
        if(arr[i] > MaxElement)
        MaxElement = arr[i];
    }
    int CountarrLen =(MaxElement + 1);

    int* countarr = (int*)malloc(CountarrLen*sizeof(int));

    for(int i = 0; i < CountarrLen; i++){
        countarr[i] = 0;
    }

    for(int i = 0; i < Size; i++){
       countarr[arr[i]]++;
    }

    int j = 0;
    for(int i = 0; i < CountarrLen; i++){
        while(countarr[i] > 0){
            arr[j] = i;
            j++;
            countarr[i]--;
        }
    }
  free(countarr);
}

void PrintArray(int arr[], int Size){
    for(int i = 0; i < Size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 0, 0};
    CountSort(arr,8);
    PrintArray(arr,8);
    return 0;
}