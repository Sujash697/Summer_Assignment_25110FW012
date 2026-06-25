#include<stdio.h>
int main()
{
    int l1=0,l2=0,l3=0,x;
    char a[100],b[100],c[100];
    printf("Enter string a : ");
    scanf("%[^\n]s",a);
    getchar();
    printf("Enter string b : ");
    scanf("%[^\n]s",b);
    while(a[l1]!='\0'){
        l1++;
    }
    while(b[l2]!='\0'){
        l2++;
    }
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(a[i]==b[j]&&a[i]!=' '){
                c[l3]=a[i];
                l3++;
            }
        }
    }
    printf("Common characters =>\n");
    for(int i=0;i<l3;i++){
        x=0;
        for(int j=0;j<i;j++){
            if(c[i]==c[j]){
                x=1;
                break;
            }
        }
        if(x==0){
            printf("%c ",c[i]);
        }
    }
    return 0;
}