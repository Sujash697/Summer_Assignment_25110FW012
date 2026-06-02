#include<stdio.h>
int main()
{
    int d,a,p=1;
    printf("Enter the number : ");
    scanf("%d",&a);
    if(a<0){
        a=-a;
    }
    if(a==0){
        printf("Product of digits of number = 0");
        return 0;
    }
    while(a!=0){
        d=a%10;
        a/=10;
        p*=d;
    }
    printf("Product of digits of number = %d",p);
    return 0;
}