#include<stdio.h>
int main()
{
    int n,j;
    printf("Enter number of elements : ");
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
    for(int i=1;i<n;i++){
        k=a[i];
        j=i-1;
        while(j>=0&&a[j]<k){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
    printf("\nSorted array in descending order =>");
    for(int i=0;i<n;i++){
        printf("\nElement %d = %g",i+1,a[i]);
    }
    return 0;
}