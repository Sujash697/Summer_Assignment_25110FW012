#include<stdio.h>
int main()
{
    int l1=0,l2=0,c1,c2,i;
    char a[100],b[100];
    printf("Enter string a : ");
    scanf("%[^\n]",a);
    getchar();
    printf("Enter string b : ");
    scanf("%[^\n]",b);
    while(a[l1]!='\0'){
        l1++;
    }
    while(b[l2]!='\0'){
        l2++;
    }
    if(l1!=l2){
        printf("Strings are not anagrams");
        return 0;
    }
    for(int k=0;k<l1;k++){
        c1=0;
        i=0;
        while(a[i]!='\0'){
            if(a[i]==a[k]){
                c1++;
            }
            i++;
        }
        c2=0;
        for(int j=0;j<l2;j++){
            if(a[k]==b[j]){
                i=0;
                while(b[i]!='\0'){
                    if(b[i]==b[j]){
                        c2++;
                    }
                    i++;
                }
                break;
            }
        }
        if(c1!=c2){
            printf("Strings are not anagrams");
            return 0;
        }
    }
    printf("Strings are anagrams");
    return 0;
}