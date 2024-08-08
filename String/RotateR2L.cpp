#include <iostream>
#include <string.h>

using namespace std;

string RotateR2L(string &s,int k){
   int length = s.length();
   for(int i=0;i<k;i++){
   char firstchar = s.at(0);
   for(int i=0;i<(length-1);i++){
       s.at(i) = s.at(i+1);
   }
   s.at(length-1) = firstchar;
 }
   return s;
}

int main(){
   string s;
   cout<<"Enter the word : ";
   cin>>s;
   string n = RotateR2L(s,1);
   cout<<n;
   return 0;
}