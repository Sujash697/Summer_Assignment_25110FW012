#include<stdio.h>
#include<math.h>
int arm(int n)
{
    int a,c=0,s=0,r;
    a=n;
    while(n!=0){
        c++;
        n/=10;
    }
    while(a!=0){
        r=a%10;
        s+=pow(r,c);
        a/=10;
    }
    return s;
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
    if(n==0){
        printf("Armstrong number");
        return 0;
    }
    if(n==arm(n)){
        printf("Armstrong number");
    }
    else{
        printf("Not an armstrong number");
    }
    return 0;
}