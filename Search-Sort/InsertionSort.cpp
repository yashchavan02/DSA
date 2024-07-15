#include <iostream>
using namespace std;

int main() {
    int Size, i, j, Element;

    cout << "Enter the size: ";
    cin >> Size;
    int arr[Size]; 

    cout << "Enter the elements: " << endl;
    for (i = 0; i < Size; i++) {
        cin >> arr[i]; 
    }


    for (i = 1; i < Size; i++) {
        j = i - 1;
        Element = arr[i]; 
       
        while (j >= 0 && arr[j] > Element) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = Element;
    }

    cout << "Sorted array: " << endl;
    for (i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
