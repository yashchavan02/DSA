#include<iostream>
using namespace std;

int main(){
   int arr[] = {1,3,5,6,3,0,9,3};
   const int size = sizeof(arr)/sizeof(arr[0]);
   int prefixSum[size];
   prefixSum[0] = arr[0];
   for(int i=1;i<size;i++){
      prefixSum[i] = prefixSum[i-1] + arr[i];
   }
   for(int i=0;i<size;i++){
      cout<<prefixSum[i]<<" ";
   }
   return 0;
}