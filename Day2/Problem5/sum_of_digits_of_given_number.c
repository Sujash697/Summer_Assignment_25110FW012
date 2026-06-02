#include<stdio.h>
int main()
{
    int a,s=0,n;
    printf("Enter number : ");
    scanf("%d",&a);
    if(a<0){
        a=-a;
    }
    while(a!=0){
        n=a%10;
        a/=10;
        s+=n;
    }
    printf("Sum of digits of number : %d",s);
    return 0;
}