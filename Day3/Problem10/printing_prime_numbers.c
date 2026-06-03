#include<stdio.h>
int main()
{
    int n,c;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Prime numbers : ");
    for(int i=2;i<=n;i++){
        c=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                c=1;
                break;
            }
        }
        if(c==0){
        printf("%d  ",i);
        }
    }
    return 0;
}