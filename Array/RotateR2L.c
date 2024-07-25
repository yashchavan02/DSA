#include <stdio.h>

void InputArray(int arr[],int size){
   for(int i=0;i<size;i++){
     scanf("%d",&arr[i]);
   }
}

void PrintArray(int arr[],int size){
   for(int i=0;i<size;i++){
     printf("%d ",arr[i]);
   }
}

void RotateArray(int arr[],int size,int k){
   for (int i = 0; i < k; i++) {
   int temp = arr[0];
   for (int j = 1 ; j < size; j++) {
   arr[j-1] = arr[j];
   }
   arr[size-1] = temp;
   }
}

int main() {
   
  int size,k;
  printf("Enter the size of an array : ");
  scanf("%d",&size);
  int arr[size];
  printf("Enter the elements:\n");
  InputArray(arr, size);
  printf("Enter how many times rotate : ");
  scanf("%d",&k);
  RotateArray(arr, size, k);
  printf("Rotated array is : ");
  PrintArray(arr, size);
  return 0;
  
}