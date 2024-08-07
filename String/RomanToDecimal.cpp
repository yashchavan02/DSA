#include<iostream>
#include<string>

using namespace std;

int InDecimal(char ch){
    switch((char)toupper(ch)){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int RomanToDecimal(string &s){
    int length = s.length();
    int Decimal = 0;
    for(int i = 0; i < length; i++){
        if(i < length - 1 && InDecimal(s.at(i)) < InDecimal(s.at(i + 1))){
            Decimal -= InDecimal(s.at(i));
        } else {
            Decimal += InDecimal(s.at(i));
        }
    }
    return Decimal;
}

int main(){
    string s;
    cout<< "Enter the Roman numeral : ";
    cin>>s;
    cout<<RomanToDecimal(s)<<endl;  
    return 0;
}
