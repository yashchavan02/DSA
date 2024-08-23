#include <stdio.h>

int SetBit(int n,int i){
   return ((1 << i) | n);
}

int main(){
   printf("%d",SetBit(9,1));
   return 0;
}