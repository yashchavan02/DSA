#include<iostream>
using namespace std;

void heapify(int arr[],int i,int size){
   int largeI = i;
   int left = i*2 + 1;
   int right = i*2 + 2;
   if(left < size && arr[left] > arr[largeI]){
      largeI = left;
   }
   if(right < size && arr[right] > arr[largeI]){
      largeI = right;
   }
   if(largeI != i){
      arr[i] = arr[i]^arr[largeI];
      arr[largeI] = arr[i]^arr[largeI];
      arr[i] = arr[i]^arr[largeI];
      heapify(arr,largeI,size);
   }
}


void BuildMaxHeap(int arr[],int size){
   for(int i=(size/2)-1;i>=0;i--){
       heapify(arr,i,size);
   }
}

void printHeap(int arr[],int size){
   for(int i=0;i<size;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
   int arr[] = {1,4,2,9,6,0,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   BuildMaxHeap(arr,size);
   printHeap(arr,size);
   return 0;
}