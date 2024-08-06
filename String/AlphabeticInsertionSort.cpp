#include<iostream>
#include<string.h>

using namespace std;

   AlphabeticSort(string &s){  
      int length = s.length();
      for(int i=1;i<length;i++){
          int j=i-1;
          char Temp = s.at(i);
          while(j>=0 && s.at(j)>Temp ){
            s.at(j+1) = s.at(j);
            j--;
          }
         s.at(j+1) = Temp;
      }
     cout<<s; 
   }

int main(){
   string s;
   cout<<"Enter the word : ";
   getline(cin,s);
   AlphabeticSort(s);
   return 0;
}