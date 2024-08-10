#include<iostream>
using namespace std;

int checkMatrixIsEqualFromAllSide(){
    int row = 5 , count = 0 , column = 4 , Addsum = 0 , AddsumNum;

    int a[row][column] = {{4, 3, 8, 4},{9, 5, 1, 9},{2, 7, 6, 2},{4, 3, 8, 1},{1, 6, 7, 0} };
    int temp[8];
    for (int i = 1; i < row - 1;i++){
        for (int j = 1; j < column - 1; j++){
            temp[8] = {0};
            AddsumNum = 0;
            temp[0] = a[i-1][j-1] + a[i][j-1] + a[i+1][j-1];
            temp[1] = a[i-1][j] + a[i][j] + a[i+1][j];
            temp[2] = a[i-1][j+1] + a[i][j+1] + a[i+1][j+1];
            temp[3] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1];
            temp[4] = a[i][j-1] + a[i][j] + a[i][j+1];
            temp[5] = a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
            temp[6] = a[i-1][j-1] + a[i][j] + a[i+1][j+1];
            temp[7] = a[i-1][j+1] + a[i][j] + a[i+1][j-1];

            bool allEqual = true;
            for (int k = 1; k < 8; k++) {
                if (temp[k] != temp[0]) {
                    allEqual = false;
                    break;
                }
            }
            if(allEqual){
                count++;
            }
        }
    }
  return count;  
}

int main() {


/* 

    4 3 8 4
    9 5 1 9
    2 7 6 2
    4 3 8 1
    1 6 7 0   


   Check For 3X3 Matrix Is Their Sum Is EqualLike This :

           \ | /    
          -[i|j]-
           / | \ 

*/

    cout<<checkMatrixIsEqualFromAllSide();
    return 0;
}
