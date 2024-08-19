#include<iostream>
using namespace std;

void Lower2Upper(string &s,int i){
   if(i == -1) return;
   s[i] = 'A' + s[i] - 'a';
   Lower2Upper(s,i-1);
}

int main(){
   string s = "yash";
   Lower2Upper(s,s.size()-1);
   cout<<s;
   return 0;
}