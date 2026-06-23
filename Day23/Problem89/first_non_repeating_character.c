#include<stdio.h>
int main()
{
    int l=0,c;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]",a);
    while(a[l]!='\0'){
        l++;
    }
    for(int i=0;i<l;i++){
        c=0;
        for(int j=0;j<l;j++){
            if(a[i]==a[j]&&i!=j){
                c=1;
                break;
            }
        }
        if(c==0){
            printf("First non-repeating character = %c",a[i]);
            return 0;
        }
    }
    printf("No non-repeating character exists");
    return 0;
}