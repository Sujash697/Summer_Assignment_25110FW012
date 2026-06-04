#include<stdio.h>
int main()
{
    int n,a=0,b=1,c;
    printf("Enter the term : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    printf("Fibonacci series nth term = %d",a);
    return 0;
}