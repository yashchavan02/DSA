#include<iostream>
using namespace std;

long facrorial(int n){
    if(n == 0 || n == 1)return 1;
    else return (n * facrorial(n-1));
}

int main(){
   cout<<facrorial(8);
   return 0;
}