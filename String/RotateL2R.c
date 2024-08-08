#include <stdio.h>
#include <string.h>

char* RotateL2R(char* s,int k){
   int length = strlen(s);
   for(int i=0;i<k;i++){
   char lastchar = s[length-1];
   for(int i=(length-1);i>0;i--){
       s[i] = s[i-1];
   }
   s[0] = lastchar;
 }
   return s;
}

int main(){
   char s[10];
   printf("Enter the word : ");
   scanf("%s",&s);
   char* n = RotateL2R(s,2);
   printf("%s",n);
   return 0;
}