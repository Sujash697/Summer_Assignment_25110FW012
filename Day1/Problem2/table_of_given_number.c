#include<stdio.h>
int main()
{
    float n;
    printf("Enter the number : ");
    scanf("%f",&n);
    for(int i=1;i<=10;i++){
        printf("%g * %d = %g\n",n,i,n*i);
    }
    return 0;
}