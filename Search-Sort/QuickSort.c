#include<stdio.h>

int Partition(int arr[], int Low, int High){
    int Pivot = arr[Low];
    int i = Low + 1;
    int j = High;
    int Temp;

    do{
        while(arr[i] <= Pivot){
            i++;
        }
        while(arr[j] > Pivot){
            j--;
        }
        if(i >= j){
            break;
        }

        Temp = arr[i];
        arr[i] = arr[j];
        arr[j] = Temp;
        
    } while(i < j);

    Temp = arr[Low];
    arr[Low] = arr[j];
    arr[j] = Temp;

    return j;
}

void QuickSort(int arr[], int Low, int High){
    if(Low < High){
        int PivotIndex = Partition(arr, Low, High);
        QuickSort(arr, Low, PivotIndex - 1);
        QuickSort(arr, PivotIndex + 1, High);
    }
}

void PrintArray(int arr[], int Size){
    for(int i = 0; i < Size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {3, 1, 0, 5, 2, 1};
    QuickSort(arr, 0, 5);
    PrintArray(arr, 6);
    return 0;
}
