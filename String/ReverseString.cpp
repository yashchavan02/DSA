#include <iostream>
#include <string.h>

using namespace std;

void Reverse(string &s) {
    int length = s.length();
    char Temp;
    for (int i = 0; i < (length / 2); i++) {
        Temp = s.at(i);
        s.at(i) = s.at((length - 1) - i);
        s.at((length - 1) - i) = Temp;
    }
   cout<<s; 
}


int main(){
   string s;
   cout<<"Enter the word : ";
   getline(cin,s);
   Reverse(s);
   return 0;
}