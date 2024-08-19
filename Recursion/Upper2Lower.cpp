#include<iostream>
using namespace std;

void Upper2Lower(string &s,int i){
   if(i == -1) return;
   s[i] = s[i] - 'A' +  'a';
   Upper2Lower(s,i-1);
}

int main(){
   string s = "YASH";
   Upper2Lower(s,s.size()-1);
   cout<<s;
   return 0;
}