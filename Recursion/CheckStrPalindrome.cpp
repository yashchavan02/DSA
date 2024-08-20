#include<iostream>
using namespace std;

bool isPalindrome(string s, int start, int end){
   if(start >= end) return true;
   if(s[start] != s[end]) return false;
   return isPalindrome(s,start+1,end-1);
}

int main(){
   string s;
   s = "mo0om";
   if(isPalindrome(s,0,(s.size()-1))){
      cout<<"Palindrome";
   }
   else {
      cout<<"Not Palindrome!";
   }
   return 0;
}