#include<stdio.h>
int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n==0){
        printf("Infinite factors");
        return 0;
    }
    if(n<0){
        n=-n;
        printf("Factors are => ");
        for(int i=1;i<=n;i++){
            if(n%i==0){
                printf("±%d ",i);
            }
        }
        return 0;
    }
    if(n>0){
        printf("Factors are => ");
        for(int i=1;i<=n;i++){
            if(n%i==0){
                printf("%d ",i);
            }
        }
        return 0;
    }
    return 0;
}