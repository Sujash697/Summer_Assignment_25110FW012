#include<stdio.h>
int main()
{
    int a,n;
    printf("Enter number of rows : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    for(int i=1;i<=n;i++){
        a=1;
        for(int j=0;j<i;j++){
            printf("%d ",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}