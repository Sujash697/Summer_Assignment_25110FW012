#include<stdio.h>
#include<string.h>
int main()
{
    int r;
    printf("Enter number of names = ");
    scanf("%d",&r);
    char a[r][100],t[100];
    for(int i=0;i<r;i++){
        getchar();
        printf("Name %d = ",i+1);
        scanf("%[^\n]s",a[i]);
    }
    for(int j=0;j<r-1;j++){
        for(int i=0;i<r-j-1;i++){
            if(strcmp(a[i],a[i+1])>0){
                strcpy(t,a[i]);
                strcpy(a[i],a[i+1]);
                strcpy(a[i+1],t);
            }
        }
    }
    printf("\nAlphabetically sorted names =>");
    for(int i=0;i<r;i++){
        printf("\n%s",a[i]);
    }
    return 0;
}