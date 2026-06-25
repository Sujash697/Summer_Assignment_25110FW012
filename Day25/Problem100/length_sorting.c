#include<stdio.h>
#include<string.h>
int main()
{
    int l=0,z,j=0,i=0,k,x;
    char a[100],b[100][100],t[100];
    printf("Enter string : ");
    scanf("%[^\n]s",a);
    l=strlen(a);
    while(i<l){
        z=0;
        if(i==0&&a[i]!=' '){
            while(a[i]!=' '&&a[i]!='\0'){
                b[j][z]=a[i];
                z++;
                i++;
            }
            b[j][z]='\0';
            j++;
        }
        else if(i!=0&&a[i]==' '&&a[i+1]!=' '){
            i++;
            while(a[i]!=' '&&a[i]!='\0'){
                b[j][z]=a[i];
                z++;
                i++;
            }
            b[j][z]='\0';
            j++;
        }
        else{
            i++;
        }
    }
    for(int i=1;i<j;i++){
        strcpy(t,b[i]);
        k=strlen(b[i]);
        x=i-1;
        while(x>=0&&strlen(b[x])>k){
            strcpy(b[x+1],b[x]);
            x--;
        }
        strcpy(b[x+1],t);
    }
    printf("Sorted words =>");
    for(int i=0;i<j;i++){
        printf(" %s",b[i]);
    }
    return 0;
}