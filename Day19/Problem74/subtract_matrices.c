#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter number of rows = ");
    scanf("%d",&r);
    printf("Enter number of columns = ");
    scanf("%d",&c);
    if(r<1||c<1){
        printf("Invalid input");
        return 0;
    }
    float a[r][c],b[r][c];
    printf("Matrix A =>\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter A[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    printf("Matrix B =>\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter B[%d][%d] = ",i+1,j+1);
            scanf("%f",&b[i][j]);
        }
    }
    printf("Subtraction of matrices => A-B\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%g ",a[i][j]-b[i][j]);
        }
        printf("\n");
    }
    return 0;
}