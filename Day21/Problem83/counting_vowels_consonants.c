#include<stdio.h>
int main()
{
    int i=0,v=0,c=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while (a[i]!='\0'){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
            v++;
        }
        else if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')){
            c++;
        }
        i++;
    }
    printf("Total vowels = %d\nTotal consonants = %d",v,c);
    return 0;
}