#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[j + 1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
