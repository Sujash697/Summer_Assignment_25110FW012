#include<stdio.h>
int main()
{
    int l=0,x;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]s",a);
    while(a[l]!='\0'){
        l++;
    }
    printf("After removing duplicate characters : ");
    for(int i=0;i<l;i++){
        x=0;
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                x=1;
                break;
            }
        }
        if(x==0){
            printf("%c",a[i]);
        }
    }
    return 0;
}