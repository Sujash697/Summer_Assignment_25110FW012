#include<stdio.h>
int main()
{
    int i=0,c=0;
    char a[100],b;
    printf("Enter string : ");
    scanf("%[^\n]",a);
    getchar();
    printf("Enter character to search = ");
    scanf("%c",&b);
    while(a[i]!='\0'){
        if(a[i]==b){
            c++;
        }
        i++;
    }
    printf("Frequency of character = %d",c);
    return 0;
}