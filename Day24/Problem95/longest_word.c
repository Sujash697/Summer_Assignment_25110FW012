#include<stdio.h>
int main()
{
    char a[100];
    int l=0,x,y,c,m=0;
    printf("Enter string : ");
    scanf("%[^\n]s",a);
    while(a[l]!='\0'){
        l++;
    }
    for(int i=0;i<l;i++){
        x=i+1;
        y=i;
        c=0;
        if(a[i]==' '&&a[i+1]!=' '&&a[i+1]!='\0'){
            while(a[x]!=' '&&a[x]!='\0'){
                c++;
                x++;
            }
        }
        if(i==0&&a[i]!=' '){
            while(a[y]!=' '&&a[y]!='\0'){
                c++;
                y++;
            }
        }
        if(m<c){
            m=c;
        }
    }
    printf("Longest word : ");
    for(int i=0;i<l;i++){
        x=i+1;
        y=i;
        c=0;
        if(a[i]==' '&&a[i+1]!=' '&&a[i+1]!='\0'){
            while(a[x]!=' '&&a[x]!='\0'){
                c++;
                x++;
            }
        }
        if(i==0&&a[i]!=' '){
            while(a[y]!=' '&&a[y]!='\0'){
                c++;
                y++;
            }
        }
        if(m==c){
            if(i==0&&a[i]!=' '){
                for(int j=i;j<y;j++){
                    printf("%c",a[j]);
                }
            }
            else{
                for(int j=i+1;j<x;j++){
                    printf("%c",a[j]);
                }
            }
            return 0;
        }
    }
    return 0;
}