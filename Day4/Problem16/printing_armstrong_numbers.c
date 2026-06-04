#include<stdio.h>
#include<math.h>
int main()
{
    int n,c,a,d,b,s,r;
    printf("Enter number : ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input");
        return 0;
    }
    printf("Armstrong numbers => ");
    for(int i=0;i<n;i++){
        s=0;
        c=0;
        d=i;
        a=d;
        while(d!=0){
            c++;
            d/=10;
        }
        b=a;
        while(a!=0){
            r=a%10;
            s+=pow(r,c);
            a/=10;
        }
        if(b==s){
            printf("%d ",b);
        }
    }
    return 0;
}