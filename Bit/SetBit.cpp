#include<iostream>
using namespace std;

int SetBit(int n,int i){
  return ((1 << i) | n);
}

int main(){
   cout<<SetBit(5,1);
   return 0;
}