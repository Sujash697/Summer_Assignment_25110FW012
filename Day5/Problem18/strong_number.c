#include<stdio.h>
int fac(int n)
{
    if(n==1||n==0){
        return 1;
    }
    else{
        return n*fac(n-1);
    }
}
int main()
{
    int n,r,s=0,a;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    if(n==0){
        printf("Not a strong number");
        return 0;
    }
    a=n;
    while(n!=0){
        r=n%10;
        s+=fac(r);
        n/=10;
    }
    if(a==s){
        printf("Strong number");
    }
    else{
        printf("Not a strong number");
    }
    return 0;
}