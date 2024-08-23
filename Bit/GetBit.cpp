#include<iostream>
using namespace std;

int GetBit(int n, int i){
    return ((n>>i)&1);
}

int main(){
   int num = 6;
   for(int i=0;i<4;i++) cout<<GetBit(num,i)<<"";
   return 0;
}