#include<iostream>
using namespace std;

int UniqueNum(int* arr, int i,int size, int n){
   if(i == size) return n;
   n = n ^ arr[i];
   UniqueNum(arr,i+1,size,n);
}

int main(){
   int arr[9] = {1,2,4,3,1,4,3,2,9};
   cout<<UniqueNum(arr,0,9,0);
   return 0;
}