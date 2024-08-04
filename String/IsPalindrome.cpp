#include<iostream>
#include<cstring>

using namespace std;

bool IsPalindrome(const string &s){
    int length = s.length();
    for(int i=0;i<(length/2);i++){
        if(!(s.at(i) == s.at(length-1-i))){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter the word : ";
    getline(cin,s);
    if(IsPalindrome(s)){
        cout<<"Palindrom";
    } else {
        cout<<"Not Palindrome";
    }
    return 0;
}
