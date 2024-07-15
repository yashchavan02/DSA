#include <stdio.h>

int BinarySearch(int arr[], int Element){

    int Low, Mid, High;
    Low = 0;
    High = 6;

    while (Low <= High){

        Mid = (Low + High) / 2;

        if (arr[Mid] == Element){
            return Mid;
          }

        else if (arr[Mid] < Element){
            Low = Mid + 1;
          }
        else{
            High = Mid - 1;
          }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int Element = 9;
    int Result = BinarySearch(arr, Element);

    if (Result != -1){
        printf("The %d is Found at index %d ", Element, Result);
      }
    else{
        printf("The %d is not Found ", Element);
      }

  return 0;
}