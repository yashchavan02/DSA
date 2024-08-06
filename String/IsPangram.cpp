#include<iostream>
#include<string.h>

using namespace std;

bool IsPangram(string &s){
   int* arr = new int[26];
   for(int i=0;i<26;i++){
      arr[i]=0;
   }
   for(char c : s){
      arr[c - 'a']++; 
   }
   for(int i=0;i<26;i++){
      if(arr[i]==0) return false;
      else return true;
   }
  delete[] arr; 
}

int main(){
   string s;
   cout<<"Enter the word : ";
   getline(cin,s);
   if(IsPangram(s)){
      cout<<"Given word is pangram.";
   }
   else {
      cout<<"Given word is not pangram.";
   }
   return 0;
}