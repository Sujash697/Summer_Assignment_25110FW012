#include<stdio.h>
int main()
{
    int n;
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
        t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("Element %d = %g\n",i+1,a[i]);
    }
}