#include <iostream>

using namespace std;

void Merge(int arr[], int Left, int Mid, int Right) {
    int i = Left, j = Mid + 1, k = 0;
    int brr[Right - Left + 1];

    while (i <= Mid && j <= Right) {
        if (arr[i] <= arr[j]) {
            brr[k] = arr[i];
            i++;
        } else {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= Mid) {
        brr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= Right) {
        brr[k] = arr[j];
        j++;
        k++;
    }

    for (i = Left, k = 0; i <= Right; i++, k++) {
        arr[i] = brr[k];
    }
}

void MergeSort(int arr[], int Left, int Right) {
    if (Left < Right) {
        int Mid = (Left + Right) / 2;
        MergeSort(arr, Left, Mid);
        MergeSort(arr, Mid + 1, Right);
        Merge(arr, Left, Mid, Right);
    }
}

void PrintArray(int arr[], int Size) {
    for (int i = 0; i < Size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {3, 1, 0, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);
    PrintArray(arr, n);
    return 0;
}
