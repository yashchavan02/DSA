#include<iostream>
using namespace std;

bool isVowel(char ch){

   switch(ch){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
        return false;
   }

}

int CountVowels(string s,int i){
   if(i == -1) return 0;
   if(isVowel(s[i])) return 1 + CountVowels(s,i-1);
   else return CountVowels(s,i-1);
}


int main(){
   string s;
   s = "mouoi";
   cout<<CountVowels(s,s.size()-1);
   return 0;
}