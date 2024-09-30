#include <functional>
#include<iostream>
#include <queue>
using namespace std;

int main(){

   priority_queue<int> p1; // use maxheap
   p1.push(10);
   p1.push(11);
   p1.push(13);
   p1.push(18);
   p1.push(20);
   p1.push(67);
   p1.push(85);
   cout<<p1.top()<<endl;
   while(!p1.empty()){
      cout<<p1.top()<<" ";
      p1.pop();
   }
   cout<<endl;

   priority_queue<int,vector<int>,greater<int>> p2; // use minheap
   p2.push(10);
   p2.push(11);
   p2.push(13);
   p2.push(18);
   p2.push(20);
   p2.push(67);
   p2.push(85);
   cout<<p2.top()<<endl;
   while(!p2.empty()){
      cout<<p2.top()<<" ";
      p2.pop();
   }
   cout<<endl;

   return 0;
}