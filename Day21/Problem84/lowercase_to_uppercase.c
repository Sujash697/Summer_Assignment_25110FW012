#include<stdio.h>
int main()
{
    int i=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        if(a[i]>='a'&&a[i]<='z'){
            a[i]-=32;
        }
        i++;
    }
    printf("In uppercase : %s",a);
    return 0;
}