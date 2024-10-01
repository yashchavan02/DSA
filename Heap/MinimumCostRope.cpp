#include<iostream>
#include<queue>
using namespace std;

int main(){
   int arr[] = {2,5,1,7,9,3,8};
   int size = sizeof(arr)/sizeof(arr[0]);
   priority_queue<int,vector<int>,greater<int>> pq;
   for(int i=0;i<size;i++){
      pq.push(arr[i]);
   }
   int cost,Tcost = 0;
   while(pq.size() > 1){
     cost = 0;
     int value = pq.top();
     pq.pop();
     cost = value + pq.top();
     pq.pop();
     Tcost += cost;
     pq.push(cost);
   }
   cout<<Tcost<<endl;
   return 0;
}