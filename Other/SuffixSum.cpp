#include<iostream>
using namespace std;

int main(){
   int arr[] = {1, 3, 5, 6, 3, 0, 9, 3};
   const int size = sizeof(arr) / sizeof(arr[0]);
   int SuffixSum[size];
   SuffixSum[size - 1] = arr[size - 1];
   for (int i = size - 2; i >= 0; i--){ 
      SuffixSum[i] = SuffixSum[i + 1] + arr[i];
   }
   for (int i = 0; i < size; i++){
      cout << SuffixSum[i] << " ";
   }
   return 0;
}
