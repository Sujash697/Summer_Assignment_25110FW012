#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter number a : ");
    scanf("%d",&a);
    printf("Enter number b : ");
    scanf("%d",&b);
    if((a<0||b<0)||(a==0&&b==0)){
        printf("Invalid input");
        return 0;
    }
    else if(a==0||b==0){
        printf("GCD of a & b = %d",a+b);
        return 0;
    }
    if(a<b){
        d=a;
    }
    else{
        d=b;
    }
    for(int i=1;i<=d;i++){
        if(a%i==0&&b%i==0){
            c=i;
        }
    }
    printf("GCD of a & b = %d",c);
    return 0;
}