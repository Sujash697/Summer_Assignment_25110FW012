#include<stdio.h>
int main()
{
    int a,s=1;
    printf("Enter the number : ");
    scanf("%d",&a);
    if(a<0){
        printf("Invalid input");
        return 0;
    }
    if(a<2){
        printf("Not a perfect number");
        return 0;
    }
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            s+=i;
        }
    }
    if(s==a){
        printf("Perfect number");
    }
    else{
        printf("Not a perfect number");
    }
    return 0;
}