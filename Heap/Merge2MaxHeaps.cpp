#include <iostream>
using namespace std;

void heapify(int arr[], int i, int size) {
  int largeI = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  if (left < size && arr[left] > arr[largeI]) {
    largeI = left;
  }
  if (right < size && arr[right] > arr[largeI]) {
    largeI = right;
  }
  if (largeI != i) {
    arr[i] = arr[i] ^ arr[largeI];
    arr[largeI] = arr[i] ^ arr[largeI];
    arr[i] = arr[i] ^ arr[largeI];
    heapify(arr, largeI, size);
  }
}

void maxHeap(int arr[], int size) {
  for (int i = (size / 2 - 1); i >= 0; i--) {
    heapify(arr, i, size);
  }
}

void printHeap(int arr[], int size, int i = 0){
   if(i == size) return;
   cout<<arr[i]<<" ";
   printHeap(arr,size,i+1);
}

int main() {
  int arr1[] = {10, 7, 9, 5, 2, 4, 3};
  int arr2[] = {15, 13, 8, 6, 0};
  const int size1 = sizeof(arr1) / sizeof(int);
  const int size2 = sizeof(arr2) / sizeof(int);
  const int size3 = size1 + size2;
  int arr3[size3];
  int i , j = 0;
  for (i = 0; i < size1; i++,j++) {
    arr3[j] = arr1[i];
  }
  for (i = 0; i < size2; i++,j++) {
    arr3[j] = arr2[i];
  }
  maxHeap(arr3, size3);
  printHeap(arr3,size3);
  return 0;
}