#include<stdio.h>
int fib(int n)
{
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
    }
    else{
        printf("Fibonacci series : ");
        for(int i=1;i<=n;i++){
            printf("%d ",fib(i));
        }
    }
    return 0;
}