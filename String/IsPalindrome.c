#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool IsPalindrome(const char* s){
    int length = strlen(s);
    for(int i=0;i<(length/2);i++){
        if(!(s[i] == s[length-1-i])){
            return false;
        }
    }
    return true;
}

int main(){
    char s[10];
    printf("Enter the word : ");
    scanf("%s",s);
    if(IsPalindrome(s)){
        printf("Palindrom");
    } else {
        printf("Not Palindrome");
    }
    return 0;
}
