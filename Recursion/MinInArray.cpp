#include <iostream>
using namespace std;

int MinElement(int* arr, int i, int size) {
    if (i == size - 1) return arr[i];
    return min(arr[i], MinElement(arr, i + 1, size));
}

int main() {
    int arr[] = {110,130,24,56,443,29,78,63,85};
    int size = sizeof(arr)/sizeof(arr[0]);  
    cout<<MinElement(arr, 0, size);
    return 0;
}
