#include<iostream>
#include<cmath>

using namespace std;

int Maxsizeint(int arr[],int size){
    int countDigit , maxint = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] > maxint) maxint = arr[i];
    return countDigit = (maxint == 0) ? 1 : static_cast<int>(log10(abs(maxint))) + 1;
}

void RadixSort(int arr[], int size){
    int d = 0;
    int TempArr[size] = {0};
    int maxDigits = Maxsizeint(arr, size);
    for (d = 0; d < maxDigits; d++){
        int CountArr[10] = {0};
        for (int i = 0; i < size; i++) CountArr[static_cast<int>(arr[i] / pow(10, d)) % 10]++;
        for (int i = 1; i < 10; i++) CountArr[i] += CountArr[i - 1];
        for (int i = size - 1; i >= 0; i--) {
            TempArr[CountArr[static_cast<int>(arr[i] / pow(10, d)) % 10] - 1] = arr[i];
            CountArr[static_cast<int>(arr[i] / pow(10, d)) % 10]--;
        }
        for (int i = 0; i < size; i++) arr[i] = TempArr[i]; 
    }
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int main() {
    int arr[] = {24,564,87,0,430,505,34532};
    int size = sizeof(arr) / sizeof(int);
    RadixSort(arr, size);
    return 0;
}