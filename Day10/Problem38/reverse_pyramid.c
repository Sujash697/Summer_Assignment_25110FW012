#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of lines : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<i;k++){
            printf("  ");
        }
        for(int j=2*n-1;j>=2*i-1;j--){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}