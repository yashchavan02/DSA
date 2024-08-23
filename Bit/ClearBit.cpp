#include<iostream>
using namespace std;

int ClearBit(int n,int i){
   return ((~(1<<i))&n);
}

int main(){
   cout<<ClearBit(5,0);
   return 0;
}