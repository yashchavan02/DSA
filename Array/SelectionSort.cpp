#include <iostream>
using namespace std;

int main(){
    int Size , Index ;
    cout<<"Enter Size : ";
    cin>>Size;
    int arr[Size];

    for (int i = 0; i < Size; i++){
        cin>>arr[i];
    }

    for (int i = 0; i < Size; i++){
        Index = i;
        for (int j = i + 1; j < Size; j++){
            if (arr[j] < arr[Index]){
                Index = j;
            }
        }

        int Temp = arr[i];
        arr[i] = arr[Index];
        arr[Index] = Temp;
    }

    for (int i = 0; i < Size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
