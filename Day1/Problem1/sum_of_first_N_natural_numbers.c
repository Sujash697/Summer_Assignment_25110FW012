#include<stdio.h>
int main()
{
    int n,s=0;
    printf("Enter the number N : ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<=n;i++){
        s+=i;
    }
    printf("Sum of N natural numbers are : %d",s);
    return 0;
}