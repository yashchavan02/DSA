#include<iostream>
using namespace std;

int main(){

   // height of edge , if only one node is present return 1

   int arr[] = {1,3,2,4,5,6,7,9};
   
   /*     
                  1
                /   \
               3     2
              / \   / \
             4   5 6   7
            /
           9   

   */
   
   int size = sizeof(arr)/sizeof(arr[0]);
   if(size == 1){
      cout<<"1"<<endl;
      return 0;
   }
   int height = 0;
   int n = size;
   while(n > 1){
     n /= 2;
     height++;
   } 
   cout<<height<<endl;
   return 0;
}