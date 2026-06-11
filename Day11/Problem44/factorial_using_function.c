#include<stdio.h>
int fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}
int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    printf("Factorial of the given number is : %d",fact(n));
    return 0;
}