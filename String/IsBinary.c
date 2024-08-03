#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool IsBinary(const char* s){
    int length = strlen(s);
    for(int i=0;i<length;i++){
        if(s[i]!= '0' && s[i]!= '1'){
            return false;
        }
    }
    return true;
}

int main(){
    char s[10];
    printf("Enter the number : ");
    scanf("%s",s);
    if(IsBinary(s)){
        printf("Binary Number");
    } else {
        printf("Not a Binary Number");
    }
    return 0;
}
