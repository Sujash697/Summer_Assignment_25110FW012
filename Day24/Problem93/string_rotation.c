#include<stdio.h>
int main()
{
    int l1=0,l2=0,r=0,c;
    char a[100],b[100],t;
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
    if(l1!=l2){
        printf("Rotation not found");
        return 0;
    }
    while(r!=l1){
        c=0;
        for(int i=0;i<l1;i++){
            if(a[i]!=b[i]){
                break;
            }
            else{
                c++;
            }
        }
        if(c==l1){
            printf("Rotation found");
            return 0;
        }
        for(int i=l1-1;i>0;i--){
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
        r++;
    }
    printf("Rotation not found");
    return 0;
}