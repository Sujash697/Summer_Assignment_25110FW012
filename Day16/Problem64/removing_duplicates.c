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
    float a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(a[i]==a[k]){
                for(int j=k;j<n-1;j++){
                    a[j]=a[j+1];
                }
                n--;
                k--;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\nElement %d = %g",i+1,a[i]);
    }
}