#include<stdio.h>
int fib(int n)
{
    int a=0,b=1,c;
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    printf("Series => ");
    for(int i=1;i<=n;i++){
        printf("%d ",fib(i));
    }
    return 0;
}