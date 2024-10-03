#include<iostream>
#include<queue>
using namespace std;

int main(){
   int arr[] = {1,4,7,9,3,2,0};
   int size = sizeof(arr)/sizeof(arr[0]);
   int i,k = 2;
   priority_queue<int,vector<int>,greater<int>> p;
   for(i=0;i<k;i++){
      p.push(arr[i]);
   }
   for(i=k;i<size;i++){
      if(p.top() < arr[i]){
         p.pop();
         p.push(arr[i]);
      }
   }
   cout<<p.top()<<endl;
   return 0;
}