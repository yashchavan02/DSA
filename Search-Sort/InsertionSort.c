#include <stdio.h>

int main() {
    int Size, i, j, Element;

    printf("Enter the size: ");
    scanf("%d", &Size); 
    int arr[Size];

    printf("Enter the elements: \n");
    for (i = 0; i < Size; i++) {
        scanf("%d", &arr[i]);
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

    printf("Sorted array: \n");
    for (i = 0; i < Size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
