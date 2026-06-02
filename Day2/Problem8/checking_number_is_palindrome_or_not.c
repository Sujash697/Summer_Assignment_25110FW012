#include<stdio.h>
int main()
{
    int n,s=0,a,b;
    printf("Enter the number : ");
    scanf("%d",&n);
    b=n;
    while(n!=0){
        a=n%10;
        n/=10;
        s=(s*10)+a;
    }
    if(b==s&&b>=0){
        printf("Yes, number is palindrome.");
    }
    else{
        printf("No, number is not palindrome.");
    }
    return 0;
}