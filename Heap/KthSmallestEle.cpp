#include<iostream>
#include<queue>
using namespace std;

int main(){
   int arr[] = {1,4,7,9,3,2,0};
   int size = sizeof(arr)/sizeof(arr[0]);
   int i,k = 4;
   priority_queue<int> p;
   for(i=0;i<k;i++){
      p.push(arr[i]);
   }
   
   cout<<endl;
   return 0;
}