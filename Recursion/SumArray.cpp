#include<iostream>
using namespace std;

int SumOfArray(int *arr,int i,int size){
   if(i == size) return 0;
   return arr[i] + SumOfArray(arr,i+1,size);
}

int main(){
   int arr[] = {1,2,3,4,5};
   int size = sizeof(arr)/sizeof(int);
   cout<<SumOfArray(arr,0,size);
   return 0;
}