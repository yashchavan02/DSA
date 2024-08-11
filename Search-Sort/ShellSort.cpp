#include<iostream>
#include<vector>

using namespace std;

void ShellSort(vector<int> &v){
   int N = v.size();
   int Gap = (N/2);
   while(Gap>=1){
      for(int i=Gap;i<N;i++){
         int Key = v.at(i);
         int j = (i-Gap);
         while(j>=0 && v.at(j)> Key){
            v.at(j+Gap) = v.at(j);
            j = (j-Gap);
         }
         v.at(j+Gap) = Key;
      }
     Gap /= 2; 
   }
  for(int i=0;i<N;i++){
    cout<<v.at(i)<<" ";
  } 
}

int main(){
   vector<int> v = {1487, 85, 1030, 142, 75, 57650, 4};
   ShellSort(v);
   return 0;
}