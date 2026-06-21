#include<stdio.h>
int main()
{
    int i=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        i++;
    }
    printf("Length of string = %d",i);
    return 0;
}