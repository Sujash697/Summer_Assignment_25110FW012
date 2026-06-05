#include<stdio.h>
int prime(int n){
    int c=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            c=1;
            break;
        }
    }
    if(c==1){
        return 0;
    }
    else{
        return n;
    }
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    if(n==1){
        printf("No prime factor");
        return 0;
    }
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    for(int i=n;i>1;i--){
        if(n%i==0){
            if(prime(i)!=0){
                printf("Largest prime factor = %d",i);
                break;
            }
        }
    }
    return 0;
}