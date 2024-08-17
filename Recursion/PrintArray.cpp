#include <iostream>
using namespace std;

void PrintArray(int* arr, int i, int size){
   if(i == size) return;
   cout<<arr[i]<<" ";
   PrintArray(arr, i + 1, size);
}

void PrintArrayRev(int* arr, int i){
   if(i == -1) return;
   cout<<arr[i]<<" ";
   PrintArrayRev(arr, i - 1);
}

int main(){
   int arr[] = {1, 3, 2, 5, 4, 9, 7, 6, 8};
   int size = sizeof(arr) / sizeof(arr[0]); 
   PrintArray(arr, 0, size);
   cout<<endl;
   size--;
   PrintArrayRev(arr,size);
   return 0;
}
