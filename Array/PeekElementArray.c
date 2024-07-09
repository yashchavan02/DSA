#include<stdio.h>

int PeekElement(int arr[] , int size) {
    int i = 0;
    int j = 1;
    int k = 2;
    for(i = 0; i < size - 1; i++) {
        if (arr[j]>arr[i] && arr[j]>arr[k]) {
            return arr[j];
        }
        else if (j == size - 1){
            return arr[j];
        }
        else {
            j++;
            k++;
        }
    }
}

int main(){
  int size;
  printf("Enter the Size of an array : ");
  scanf("%d",&size);
  int arr[size];
  printf("Enter the elements in array : \n");
   for (int i = 0; i < size ; i++){
     scanf("%d",&arr[i]);
   }
  printf("The peek element is : %d",PeekElement(arr,size));
 return 0;
}