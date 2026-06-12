#include<stdio.h>
int pal(int n)
{
    int s=0,a;
    while(n!=0){
        a=n%10;
        n/=10;
        s=(s*10)+a;
    }
    return s;
}
int main()
{
    int n,b;
    printf("Enter the number : ");
    scanf("%d",&n);
    b=n;
    if(b>=0&&b==pal(n)){
        printf("Yes, number is palindrome.");
    }
    else{
        printf("No, number is not palindrome.");
    }
    return 0;
}