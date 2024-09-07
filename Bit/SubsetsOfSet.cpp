#include<iostream>
using namespace std;

void Subsets(int* arr,int size){
   for(int i=0;i < (1<<size); i++){
       for(int j=0;j<size;j++){
         if(i & (1<<j)) cout<<arr[j]<<" ";
       }
     cout<<endl;
   }
}
   
int main(){
   int arr[3] = {1,3,2};
   Subsets(arr,3);
   return 0;
}