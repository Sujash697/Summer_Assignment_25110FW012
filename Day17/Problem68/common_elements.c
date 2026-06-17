#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter number of elements in 1st array : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    printf("\nEnter number of elements in 2nd array : ");
    scanf("%d",&m);
    if(m<1){
        printf("Invalid input");
        return 0;
    }
    float b[m];
    int d[m];
    for(int i=0;i<m;i++){
        d[i]=0;
    }
    for(int i=0;i<m;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&b[i]);
    }
    printf("Common elements => ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]&&d[j]==0){
                printf("%g ",a[i]);
                d[j]=1;
                break;
            }
        }
    }
    return 0;
}