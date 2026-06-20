#include<stdio.h>
int main()
{
    int o;
    printf("Enter order of matrix = ");
    scanf("%d",&o);
    if(o<1){
        printf("Invalid input");
        return 0;
    }
    float a[o][o];
    printf("Matrix A =>\n");
    for(int i=0;i<o;i++){
        for(int j=0;j<o;j++){
            printf("Enter a[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    for(int i=0;i<o;i++){
        for(int j=i+1;j<o;j++){
            if(a[i][j]!=a[j][i]){
                printf("Matrix is not symmetric");
                return 0;
            }
        }
    }
    printf("Matrix is symmetric");
    return 0;
}