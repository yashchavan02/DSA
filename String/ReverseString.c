#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Reverse(const char* s) {
    int length = strlen(s);
    char* str = (char*)malloc(sizeof(char[length + 1]));
    strcpy(str, s);
    char Temp;
    for (int i = 0; i < (length / 2); i++) {
        Temp = str[i];
        str[i] = str[(length - 1) - i];
        str[(length - 1) - i] = Temp;
    }
   printf("%s",str); 
   free(str);
}


int main(){
   char s[10];
   printf("Enter the word : ");
   scanf("%s",&s);
   Reverse(s);
   return 0;
}