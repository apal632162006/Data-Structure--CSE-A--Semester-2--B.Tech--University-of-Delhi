//Matrix Diaonal Sum:- write a c program that calculate the sum of the element on the primary diagonal of a square matrix of integer the matrix diamension and the elements of the matrix should be enter by the user ensure that your solution efficieny handle necesses of arbitary sizes entered by the user.//

#include<stdio.h>

int main() {
    int matrix;
    int arr[3][3];
    int sum = 0;

    printf("enter the dimension of the matrix A");
    for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
         }
    }
     for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
            if(i == j){
                sum = sum + arr[i][j];
            }
         }
    }
    printf("Required sum is %d",sum);
    

   

    return 0;
}

