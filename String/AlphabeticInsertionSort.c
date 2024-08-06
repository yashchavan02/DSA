#include<stdio.h>
#include<string.h>

 void AlphabeticSort(char* s){  
      int length = strlen(s);
      for(int i=1;i<length;i++){
          int j=i-1;
          char Temp = s[i];
          while(j>=0 && s[j]>Temp ){
            s[j+1] = s[j];
            j--;
          }
         s[j+1] = Temp;
      }
     printf("%s",s); 
     return;
 }

int main(){
   char s[10];
   printf("Enter the word : ");
   scanf("%s",&s);
   AlphabeticSort(s);
   return 0;
}