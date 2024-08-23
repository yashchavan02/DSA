#include <stdio.h>

int GetBit(int n, int i){
    return ((n>>i)&1);
}

int main(){
   int num = 9;
   for(int i=0;i<4;i++) printf("%d",GetBit(num,i));
   return 0;
}
