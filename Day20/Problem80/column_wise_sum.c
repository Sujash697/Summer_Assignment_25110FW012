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
    float a[r][c],s;
    printf("Matrix A =>\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter a[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    for(int i=0;i<c;i++){
        s=0;
        for(int j=0;j<r;j++){
            s+=a[j][i];
        }
        printf("Sum of column %d = %g\n",i+1,s);
    }
    return 0;
}