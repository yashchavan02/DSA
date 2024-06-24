#include <stdio.h>

int main(){
    int Size , Index ;
    printf("Enter Size : ");
    scanf("%d",&Size);
    int arr[Size];

    for (int i = 0; i < Size; i++){
        scanf("%d",&arr[i]);
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
        printf("%d ",arr[i] );
    }

    return 0;
}
