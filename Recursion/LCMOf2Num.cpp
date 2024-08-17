#include<iostream>
using namespace std;

int GCD(int a,int b){
   if(b == 0) return a;
   return GCD(b,a%b);
}

int LCM(int a,int b){
   int gcd = GCD(a,b);
   return ((gcd)*(a/gcd)*(b/gcd));
}

int main(){
  int a = 13 , b = 52;
  cout<<LCM(a,b);
}