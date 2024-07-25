#include <iostream>

using namespace std;

void InputArray(int arr[],int size){
   for(int i=0;i<size;i++){
     cin>>arr[i];
   }
}

void PrintArray(int arr[],int size){
   for(int i=0;i<size;i++){
     cout<<arr[i]<<" ";
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
  cout<<"Enter the size of an array : ";
  cin>>size;
  int arr[size];
  cout<<"Enter the elements:"<<endl;
  InputArray(arr, size);
  cout<<"Enter how many times rotate : ";
  cin>>k;
  RotateArray(arr, size, k);
  cout<<"Rotated array is : ";
  PrintArray(arr, size);
  return 0;
  
}