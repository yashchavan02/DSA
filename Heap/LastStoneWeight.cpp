#include<iostream>
#include<queue>
using namespace std;

int main(){
   int arr[] = {1,2,4,6,8};
   int size = sizeof(arr)/sizeof(arr[0]);
   priority_queue<int> p;
   for(int i=0;i<size;i++){
     p.push(arr[i]);
   }
   while(p.size() > 1){
     int weight = p.top();
     p.pop();
     weight -= p.top();
     p.pop();
     if(weight){
       p.push(weight);
     }
   }
   int ans = p.empty() ? 0 : p.top();
   cout<<ans<<endl;
   return 0;
}