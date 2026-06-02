#include<stdio.h>
int main()
{
    int n,s=0,a;
    printf("Enter the number : ");
    scanf("%d",&n);
    while(n!=0){
        a=n%10;
        n/=10;
        s=(s*10)+a;
    }
    printf("Reversed number = %d",s);
    return 0;
}