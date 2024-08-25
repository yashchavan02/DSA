#include<iostream>
using namespace std;

bool isPowerOf2(int n){
   return (n && !(n & n-1));
} 

int main(){
   cout<<isPowerOf2(128);
   return 0;
}