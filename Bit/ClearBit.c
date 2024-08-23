#include <stdio.h>

int ClearBit(int n,int i){
   return ((~(1 << i)) & n);
}
int main(){
   printf("%d",ClearBit(7,1));
   return 0;
}