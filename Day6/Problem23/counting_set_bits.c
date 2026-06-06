#include<stdio.h>
int main()
{
    int n,r,c=0;
    printf("Enter integer = ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input");
        return 0;
    }
    while(n!=0){
        r=n%2;
        if(r==1){
            c++;
        }
        n/=2;
    }
    printf("Number of set bits = %d",c);
    return 0;
}