#include <stdio.h>

int LinearSearch(int arr[], int Element){
    for (int i = 0; i < 6; i++){
        if (arr[i] == Element){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int Element = 14;
    int Result = LinearSearch(arr, Element);   
    printf("The %d is present at index %d", Element, Result);
    return 0;
}