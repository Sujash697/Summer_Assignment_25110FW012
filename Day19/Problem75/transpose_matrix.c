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
    float a[r][c];
    printf("Matrix A =>\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter a[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    printf("Transpose of matrix => A'\n");
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            printf("%g ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}