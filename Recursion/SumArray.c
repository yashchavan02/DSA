#include<stdio.h>

int SumOfArray(int *arr,int i,int size){
   if(i == size) return 0;
   return arr[i] + SumOfArray(arr,i+1,size);
}

int main(){
   int arr[] = {1,9,6,4,2};
   int size = sizeof(arr)/sizeof(int);
   printf("%d",SumOfArray(arr,0,size));
   return 0;
}