#include <stdio.h>
#include <string.h>

int LongestPalindrome(char* s){
   int lowersum = 0 , uppersum = 0 , oddeven = 0;
   int LowerCase[26] , UpperCase[26];
   for(int i=0;i<26;i++){
     LowerCase[i] = 0;
     UpperCase[i] = 0;
   }
   for(int i=0;i<26;i++){
    if(s[i] >= 'a'){
      LowerCase[s[i] - 'a']++;
    }
    else {
      UpperCase[s[i] - 'A']++;
    }
   }

   for(int i=0;i<26;i++){
    if(LowerCase[i]%2 == 0){
       lowersum += LowerCase[i];
    }
    else {
      LowerCase[i]--;
      lowersum += LowerCase[i];
      oddeven++;
    }
   }

   for(int i=0;i<26;i++){
    if(UpperCase[i]%2 == 0){
       uppersum += UpperCase[i];
    }
    else {
      uppersum += (UpperCase[i] - 1);
      oddeven++;
    }
   }
  
  int result = oddeven > 0 ? (uppersum + lowersum + 1) : (uppersum + lowersum);
  
  return result;
}

int main(){

  char s[20];
   printf("Enter the word : ");
   scanf("%s",&s);

   int size = LongestPalindrome(s);
   printf("The max palindrome is form of size : %d",size);
   return 0;
}