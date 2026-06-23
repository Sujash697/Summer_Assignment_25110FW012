#include<stdio.h>
int main()
{
    int l=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while(a[l]!='\0'){
        l++;
    }
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]==a[j]){
                printf("First repeating character = %c",a[i]);
                return 0;
            }
        }
    }
    printf("No repeating character exists");
    return 0;
}