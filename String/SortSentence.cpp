#include<iostream>
#include<string.h>

using namespace std;

bool IsInt(char ch){
   if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'){
      return true;
   }
   else return false;
}

void SortSentence(string &s){
   string arr[11];
   string str;

   for(int i=0;i<10;i++){
      arr[i] = "0";
   }  

   for(char c : s){
     if(!IsInt(c) && c != ' '){
       str.push_back(c);
     }
     else if(c == ' '){
       continue;
     }
     else {
       int index = (c - '0');
       arr[index] = str; 
       str.clear();
     }
   }

   string AnsString;
   for(int i=0;i<10;i++){
      if(arr[i] != "0"){
        AnsString += arr[i];
        AnsString += " ";
      }     
   } 
   cout<<AnsString;
}

/* is2 sentence4 this1 a3 */

int main(){
   string s;
   cout<<"Enter the sentence : ";
   getline(cin, s);
   SortSentence(s);
   return 0;
}