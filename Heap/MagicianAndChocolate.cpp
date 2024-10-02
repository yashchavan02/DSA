#include<iostream>
#include<queue>
using namespace std;

int main(){
   int arr[] = {4,2,8,6,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   int time = 5;
   priority_queue<int> p;
   for(int i=0;i<size;i++){
      p.push(arr[i]);
   }
   int Tchocolate = 0;
   while(time-- && !p.empty()){
     int value = p.top();
     Tchocolate += value;
     p.pop();
     p.push(value/2);
   } 
   cout<<Tchocolate<<endl;
   return 0;
}