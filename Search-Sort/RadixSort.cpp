#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

int Maxsizeint(int arr[],int size){
    int maxint = arr[0];
    int i = 1;
    for(int i;i<size;i++) if(arr[i]>arr[0]) maxint = arr[i];
    return (to_string(maxint)).length();
}

void RadixSort(int arr[], int size){
    int d = 0;
    int TempArr[size] = {0};
    for(d=0;d<Maxsizeint(arr,size);d++){
        int CountArr[10] = {0};
        for(int i=0;i<size;i++) CountArr[int(arr[i]/pow(10,d))%10]++;
        for(int i=1;i<10;i++) CountArr[i] = (CountArr[i] + CountArr[i-1]);
        for(int i=8;i>=0;i--) CountArr[i+1] = CountArr[i];
        CountArr[0] = 0;
        for(int i=0;i<size;i++){
            TempArr[CountArr[int(arr[i]/pow(10,d))%10]] = arr[i];
            CountArr[int(arr[i]/pow(10,d))%10]++;
        }
        for(int i=0;i<size;i++) arr[i] = TempArr[i]; 
     }
   for(int i=0;i<size;i++) cout<<TempArr[i]<<" ";
}

int main(){
    int arr[] = {1487,85,1030,142,75,57650,4};
    int size = (sizeof(arr)/sizeof(int));
    RadixSort(arr,size);
    return 0;
}