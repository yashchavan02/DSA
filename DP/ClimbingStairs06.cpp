#include<iostream>
using namespace std;

int main(){
   int n;
   cin>>n;
   int curr , prev1 = 0 , prev2 = 1;
   for(int i = 0;i < n;i++){
      curr = prev1 + prev2;
      prev1 = prev2;
      prev2 = curr;
   }
   cout<<curr<<endl;
   return 0;
}