#include <stdio.h>
#include <string.h>

char* RotateR2L(char* s,int k){
   int length = strlen(s);
   for(int i=0;i<k;i++){
   char firstchar = s[0];
   for(int i=0;i<(length-1);i++){
       s[i] = s[i+1];
   }
   s[(length-1)] = firstchar;
 }
   return s;
}

int main(){
   char s[10];
   printf("Enter the word : ");
   scanf("%s",&s);
   char* n = RotateR2L(s,1);
   printf("%s",n);
   return 0;
}