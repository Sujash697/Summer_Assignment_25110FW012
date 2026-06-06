#include<stdio.h>
int main()
{
    int n,r,a=1,c=0,y;
    double m,x,b=0,e=0.1;
    printf("Enter the decimal number : ");
    scanf("%lf",&m);
    if(m<0){
        printf("Invalid input");
        return 0;
    }
    n=m;
    x=m-n;
    while(n!=0){
        r=n%2;
        b+=r*a;
        n/=2;
        a*=10;
    }
    do{
        x*=2;
        y=x;
        b+=y*e;
        e/=10;
        x-=y;
        c++;
    }
    while(c!=5);
    printf("Binary number => %.5lf",b);
    return 0;
}