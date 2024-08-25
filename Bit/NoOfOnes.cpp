#include<iostream>
using namespace std;

int NoOfOnes(int n ,int count){
   if(n == 0) return count;
   int temp =  n & (n - 1); 
   if(temp == 0) return count + 1; 
   return NoOfOnes(temp , count + 1);
}

int main(){
   cout << NoOfOnes(7,0);
   return 0;
}
