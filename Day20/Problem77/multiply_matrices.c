#include<stdio.h>
int main()
{
    int r1,c1,r2,c2;
    printf("Enter no. of rows in matrix A : ");
    scanf("%d",&r1);
    printf("Enter no. of columns in matrix A : ");
    scanf("%d",&c1);
    printf("Enter no. of rows in matrix B : ");
    scanf("%d",&r2);
    printf("Enter no. of columns in matrix B : ");
    scanf("%d",&c2);
    if(r1<1||r2<1||c1<1||c2<1){
        printf("Invalid input");
    }
    else if(c1!=r2){
        printf("Multiplication not possible");
    }
    else{
        float A[r1][c1],B[r2][c2],C[r1][c2];
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                printf("Enter A[%d][%d] : ",i+1,j+1);
                scanf("%f",&A[i][j]);
            }
        }
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                printf("Enter B[%d][%d] : ",i+1,j+1);
                scanf("%f",&B[i][j]);
            }
        }
        printf("Multiplication of matrix A and matrix B =>\n");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                C[i][j]=0;
                for(int k=0;k<c1;k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
                printf("%g  ",C[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}