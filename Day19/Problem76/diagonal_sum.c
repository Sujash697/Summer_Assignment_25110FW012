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
    float a[o][o],p=0,s=0,x=0;
    printf("Matrix A =>\n");
    for(int i=0;i<o;i++){
        for(int j=0;j<o;j++){
            printf("Enter a[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    for(int i=0;i<o;i++){
        for(int j=0;j<o;j++){
            if(i==j){
                p+=a[i][j];
            }
            if(i+j==o-1){
                s+=a[i][j];
            }
            if(i==j&&i+j==o-1){
                x=a[i][j];
            }
        }
    }
    printf("Sum of primary diagonal elements = %g\nSum of secondary diagonal elements = %g\n",p,s);
    printf("Total diagonal sum = %g",p+s-x);
    return 0;
}