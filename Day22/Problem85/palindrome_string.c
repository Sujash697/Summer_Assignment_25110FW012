#include<stdio.h>
int main()
{
    int i=0,j=0,t=1;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        i++;
    }
    while(j<i/2){
        if(a[j]!=a[i-j-1]){
            t=0;
            break;
        }
        j++;
    }
    if(t==1){
        printf("String is palindrome");
    }
    else{
        printf("String is not palindrome");
    }
    return 0;
}