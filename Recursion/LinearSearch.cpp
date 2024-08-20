#include<iostream>
using namespace std;

bool LinearSearch(int* arr,int i,int val){
   if(i == (sizeof(arr)/sizeof(arr[0]))) return false;
   if(arr[i] == val) return true;
   LinearSearch(arr,i+1,val);
}

int main(){
   int arr[] = {1,3,5,2,4,7,6,9};
   if(LinearSearch(arr,0,1)) cout<<"Element Found";
   else cout<<"Element Not Found";
   return 0;
}