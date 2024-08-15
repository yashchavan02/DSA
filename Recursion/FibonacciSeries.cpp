#include<iostream>
using namespace std;

int FiboAtPos(int pos){
    if(pos == 1 || pos == 0) return pos;
    return FiboAtPos(pos - 1) + FiboAtPos(pos - 2);
}

int main(){
   int index;
   cout<<"Enter the index : ";
   cin>>index;
   cout<<"At index "<<index<<" -> "<<FiboAtPos(index);
   return 0;
}