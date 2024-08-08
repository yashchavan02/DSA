#include <iostream>
#include <string.h>

using namespace std;

string RotateL2R(string &s,int k){
   int length = s.length();
   for(int i=0;i<k;i++){
   char lastchar = s.at(length-1);
   for(int i=(length-1);i>0;i--){
       s.at(i) = s.at(i-1);
   }
   s.at(0) = lastchar;
 }
   return s;
}

int main(){
   string s;
   cout<<"Enter the word : ";
   cin>>s;
   string n = RotateL2R(s,2);
   cout<<n;
   return 0;
}