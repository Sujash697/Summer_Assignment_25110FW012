#include<stdio.h>
int main()
{
    int n,c=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    if(n==0){
        printf("Number of digits = 1");
    }
    else{
        while(n!=0){
            c+=1;
            n/=10;
        }
        printf("Number of digits = %d",c);
    }
    return 0;
}