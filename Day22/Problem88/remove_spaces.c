#include<stdio.h>
int main()
{
    int i=0,j=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while(a[i]!='\0'){
        if(a[i]!=' '){
            a[j]=a[i];
            j++;
        }
        i++;
    }
    a[j]='\0';
    printf("String with no space = %s",a);
    return 0;
}