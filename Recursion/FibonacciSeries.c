#include<stdio.h>

int FiboAtPos(int pos){
    if(pos == 1 || pos == 0) return pos;
    return FiboAtPos(pos - 1) + FiboAtPos(pos - 2);
}

int main(){
   int index;
   printf("Enter the index : ");
   scanf("%d",&index);
   printf("At index %d -> %d",index,FiboAtPos(index));
   return 0;
}