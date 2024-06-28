#include <iostream>
#include <limits.h>

using namespace std;

int main(){

    int Max, Secmax, n;
    Max = INT_MIN;
    Secmax = INT_MIN;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array:\n";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++){
        if (arr[i] > Max){
            Secmax = Max;
            Max = arr[i];
        }
        else if (arr[i] > Secmax && arr[i] != Max){
            Secmax = arr[i];
        }
    }

    cout<<"Maximum number in array is : "<<Max<<endl;
    cout<<"second maximum number in array is : "<<Secmax;
    return 0;
}
