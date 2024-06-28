#include <stdio.h>
#include <limits.h>

int main(){

    int Max, Secmax, n;
    Max = INT_MIN;
    Secmax = INT_MIN;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
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

    printf("Maximum number in array is : %d", Max);
    printf("\n");
    printf("second maximum number in array is : %d", Secmax);
    return 0;
}
