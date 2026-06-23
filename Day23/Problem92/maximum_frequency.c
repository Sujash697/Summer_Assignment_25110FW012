#include<stdio.h>
int main()
{
    int c,i,m=0,l=0,x;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while(a[l]!='\0'){
        l++;
    }
    for(int k=0;k<l;k++){
        c=0;
        i=0;
        while(a[i]!='\0'){
            if(a[i]==a[k]){
                c++;
            }
            i++;
        }
        if(c>m){
            m=c;
        }
    }
    printf("Maximum frequency characters =>");
    for(int k=0;k<l;k++){
        c=0;
        i=0;
        while(a[i]!='\0'){
            if(a[i]==a[k]){
               c++;
            }
            i++;
        }
        if(c==m){
            x=0;
            for(int j=0;j<k;j++){
                if(a[j]==a[k]){
                    x=1;
                    break;
                }
            }
            if(x==0){
                printf(" %c",a[k]);
            }
        }   
    }
    return 0;
}