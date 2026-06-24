#include<stdio.h>
int main()
{
    int l=0,c=0,z=0;
    char a[100];
    printf("Enter string : ");
    scanf("%[^\n]s",a);
    while(a[l]!='\0'){
        l++;
    }
    printf("Compressed string =>\n");
    for(int i=0;i<l;i++){
        if(z>0){
            z--;
            continue;
        }
        c=0;
        for(int j=i;j<l;j++){
            if(a[i]==a[j]){
                c++;
            }
            else{
                break;
            }
        }
        printf("%c%d",a[i],c);
        z=c-1;
    }
    return 0;
}