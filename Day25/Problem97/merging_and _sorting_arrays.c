#include<stdio.h>
int main()
{
    int n,m,j;
    printf("Enter number of elements in 1st array : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n],k;
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
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    for(int i=1;i<n+m;i++){
        k=c[i];
        j=i-1;
        while(j>=0&&c[j]>k){
            c[j+1]=c[j];
            j--;
        }
        c[j+1]=k;
    }
    printf("\nMerged and sorted array =>");
    for(int i=0;i<n+m;i++){
        printf("\nElement %d = %g",i+1,c[i]);
    }
    return 0;
}