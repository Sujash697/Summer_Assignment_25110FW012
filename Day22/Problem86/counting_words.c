#include<stdio.h>
int main()
{
    int i=0,c=1;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        if(i>0&&a[i]==' '&&a[i-1]!=' '){
            c++;
        }
        i++;
    }
    printf("No. of words = %d",c);
    return 0;
}