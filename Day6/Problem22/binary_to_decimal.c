#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char n[20];
    int i,l,x=0,a=-1;
    double y=0;
    printf("Enter the binary number : ");
    scanf("%s",n);
    l=strlen(n);
    for(i=0;i<l;i++){
        if(n[i]!='0'&&n[i]!='1'&&n[i]!='.'){
            printf("Invalid input");
            return 0;
        }
        if(n[i]!='.'){
            x=x*2+n[i]-'0';
        }
        if(n[i]=='.'){
            break;
        }
    }
    for(i=i+1;i<l;i++){
        if(n[i]!='0'&&n[i]!='1'&&n[i]=='.'){
            printf("Invalid input");
            return 0;
        }
        if(n[i]=='1'){
            y=y+pow(2,a);
        }
        a--;
    }    
    printf("Decimal number => %lg",x+y);
    return 0;
}