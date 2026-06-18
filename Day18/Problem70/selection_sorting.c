#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n],t;
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        m=i;
        for(int j=i+1;j<n;j++){
            if(a[m]>a[j]){
                m=j;
            }
        }
        if(m!=i){
            t=a[i];
            a[i]=a[m];
            a[m]=t;
        }
    }
    printf("\nSorted array in ascending order =>");    
    for(int i=0;i<n;i++){
        printf("\nElement %d = %g",i+1,a[i]);
    }
    return 0;
}