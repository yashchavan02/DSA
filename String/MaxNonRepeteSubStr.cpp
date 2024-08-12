#include<iostream>
#include<string.h>

using namespace std;

int MaxNonRepeteSubStr(string &s){

   int first = 0, second = 0, currentLen = 0, maxLen = 1;
   int arr[26] = {0};
   while(second < s.length()){
      arr[s[second] - 'a'] ++;
      if(arr[s[second] - 'a'] < 2){
         currentLen++;
         maxLen = maxLen >= currentLen ? maxLen : currentLen;
         second++;
      }
      else if(arr[s[first] - 'a'] == 1){
         arr[s[first] - 'a']--;
         first++;
         currentLen--;
      }
      else {
         arr[s[first] - 'a']--;
         first++;
         second++;
      }
   }
  return maxLen;
}

int main(){

   string s;
   s = "abcdaef";
   cout<<MaxNonRepeteSubStr(s);

   return 0;
}
