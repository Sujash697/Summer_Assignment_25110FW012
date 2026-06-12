#include<stdio.h>
int per(int a)
{
    int s=1;
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            s+=i;
        }
    }
    return s;
}
int main()
{
    int a;
    printf("Enter the number : ");
    scanf("%d",&a);
    if(a<0){
        printf("Invalid input");
        return 0;
    }
    if(a<6){
        printf("Not a perfect number");
        return 0;
    }
    if(per(a)==a){
        printf("Perfect number");
    }
    else{
        printf("Not a perfect number");
    }
    return 0;
}