#include<iostream>
using namespace std;

bool Binarysearch(int* arr,int i,int j,int val){
   int mid = i + ((j - i)/2);
   if(i > j) return false;
   if(arr[mid] == val) return true;
   else if(arr[mid] < val) Binarysearch(arr,mid+1,j,val );
   else Binarysearch(arr,i,mid-1,val);
}

int main(){
   int arr[] = {1,3,5,7,9,11,13,15};
   int size = (sizeof(arr)/sizeof(arr[0]) - 1);
   cout<<Binarysearch(arr,0,size,16);
   return 0;
}