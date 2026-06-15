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
    float a[n],b[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        b[i]=a[n-i-1];
        printf("Element %d = %g\n",i+1,b[i]);
    }
}