#include<stdio.h>
int prime(int n)
{
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    if(n<2){
        printf("Not a prime number");
        return 0;
    }
    if(prime(n)==1){
        printf("Prime number");
    }
    else{
        printf("Not a prime number");
    }
    return 0;
}