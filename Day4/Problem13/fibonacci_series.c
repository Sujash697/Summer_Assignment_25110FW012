#include<stdio.h>
int main()
{
    int n,a=0,b=1,c;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    printf("Series => ");
    for(int i=1;i<=n;i++){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
    return 0;
}