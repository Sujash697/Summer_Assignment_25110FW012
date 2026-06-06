#include<stdio.h>
int main()
{
    int a,b,i=1;
    double v=1;
    printf("Enter base : ");
    scanf("%d",&a);
    printf("Enter power : ");
    scanf("%d",&b);
    if(a==0&&b<0){
        printf("Answer = Undefined");
        return 0;
    }
    if(b>0){
        while(i<=b){
            v*=a;
            i++;
        }
    }
    else{
        b=-b;
        while(i<=b){
            v/=a;
            i++;
        }
    }
    printf("Answer = %lg",v);
    return 0;
}