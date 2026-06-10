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
        for(int k=n;k>i;k--){
            printf("  ");
        }
        for(int j=1;j<2*i;j++){
            if(j<=i){
                printf("%c ",j+64);
            }
            else{
                printf("%c ",2*i-j+64);
            }
        }
        printf("\n");
    }
    return 0;
}