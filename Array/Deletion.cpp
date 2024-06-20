#include <iostream>

using namespace std;

void DeletionElement(int arr[], int CurrentSize, int Index){
    for (int i =Index; i < CurrentSize; i++){
        arr[i] = arr[i + 1];
      }
}

void PrintArray(int arr[] , int CurrentSize){
    for (int i = 0; i < CurrentSize; i++){
        cout << arr[i] << " ";
    } 
  cout<<endl;  
} 

int main() {
    int arr[25] = {1, 2, 3, 5, 6, 7};
    int TotalSize = sizeof(arr) / sizeof(arr[0]);
    int CurrentSize = 6;
    int Index = 2;
    cout<<"Before Deletion"<<endl;
    PrintArray(arr,CurrentSize);

    DeletionElement(arr, CurrentSize, Index);
    CurrentSize -= 1;
    cout<<"After Deletion"<<endl;
    PrintArray(arr,CurrentSize);

    return 0;
}