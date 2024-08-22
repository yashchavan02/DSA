#include<iostream>
using namespace std;

string RevString(string s,int start, int end){
   if(start >= end) return s;
   s[start] = s[start]^s[end];
   s[end] = s[start]^s[end];
   s[start] = s[start]^s[end];
   return RevString(s,start+1,end-1);
}

int main(){
   string s = "keshav";
   cout<<RevString(s,0,s.size()-1);
   return 0;
}