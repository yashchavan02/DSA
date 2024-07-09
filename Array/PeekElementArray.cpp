#include<iostream>

using namespace std;

int PeekElement(int arr[] , int size) {
    int i = 0;
    int j = 1;
    int k = 2;
    for(i = 0; i < size - 1; i++) {
        if (arr[j]>arr[i] && arr[j]>arr[k]) {
            return arr[j];
        }
        else if (j == size - 1){
            return arr[j];
        }
        else {
            j++;
            k++;
        }
    }
}

int main(){
  int size;
  cout<<"Enter the Size of an array : ";
  cin>>size;
  int arr[size];
  cout<<"Enter the elements in array : "<<endl;
   for (int i = 0; i < size ; i++){
     cin>>arr[i];
   }
  cout<<"The peek element is : "<<PeekElement(arr,size);
 return 0;
}