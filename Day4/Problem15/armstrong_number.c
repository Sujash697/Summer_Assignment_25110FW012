#include<stdio.h>
#include<math.h>
int main()
{
    int n,c=0,a,b,s=0,r;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    if(n==0){
        printf("Armstrong number");
        return 0;
    }
    a=n;
    while(n!=0){
        c++;
        n/=10;
    }
    b=a;
    while(a!=0){
        r=a%10;
        s+=pow(r,c);
        a/=10;
    }
    if(b==s){
        printf("Armstrong number");
    }
    else{
        printf("Not an armstrong number");
    }
    return 0;
}