#include<stdio.h>
long fac(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*fac(n-1);
}
int main()
{
    int n;
    printf("Enter integer : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    if(n>20){
        printf("Too large");
        return 0;
    }
    printf("Factorial = %ld",fac(n));
    return 0;
}