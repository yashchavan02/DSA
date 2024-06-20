#include <iostream>

using namespace std;

void InsertElement(int arr[], int CurrentSize, int Index, int Element){
    for (int i = CurrentSize - 1; i >= Index; i--){
        arr[i + 1] = arr[i];
      }
    arr[Index] = Element;
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
    int Index = 3;
    int Element = 4;
    cout<<"Before Insert"<<endl;
    PrintArray(arr,CurrentSize);

    InsertElement(arr, CurrentSize, Index, Element);
    CurrentSize += 1;
    cout<<"After Insert"<<endl;
    PrintArray(arr,CurrentSize);

    return 0;
}