#include <iostream>

using namespace std;

int LinearSearch(int arr[], int Element){
    for (int i = 0; i < 6; i++){
        if (arr[i] == Element){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int Element = 5;
    int Result = LinearSearch(arr, Element);   
    if (Result == -1) {      
       cout<<"The "<<Element<<" is not present in array. "<<endl;
    }
    else{
       cout<<"The "<<Element<<" is present at "<<Result<<endl;
    }
    return 0;
}