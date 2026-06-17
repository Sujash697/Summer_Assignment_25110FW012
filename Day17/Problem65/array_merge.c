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
    float b[m],c[n+m];
    for(int i=0;i<m;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&b[i]);
        c[n+i]=b[i];
    }
    printf("\nMerged array =>");
    for(int i=0;i<n+m;i++){
        if(i<n){
            c[i]=a[i];
        }
        printf("\nElement %d = %g",i+1,c[i]);
    }
    return 0;
}