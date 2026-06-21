#include<stdio.h>
int main()
{
    int i=0,j=0;
    char a[100],t;
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        i++;
    }
    while(j<i/2){
        t=a[j];
        a[j]=a[i-j-1];
        a[i-j-1]=t;
        j++;
    }
    printf("%s",a);
    return 0;
}