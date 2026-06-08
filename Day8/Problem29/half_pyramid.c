#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}