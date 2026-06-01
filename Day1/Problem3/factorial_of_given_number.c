#include<stdio.h>
int main()
{
    int n,f=1;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<=n;i++){
        f*=i;
    }
    printf("Factorial of the given number is : %d",f);
    return 0;
}