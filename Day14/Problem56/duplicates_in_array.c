#include<stdio.h>
int main()
{
    int n,f;
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
    printf("Duplicate elements = ");
    for(int i=0;i<n;i++){
        f=0;
        for(int k=0;k<i;k++){
            if(a[i]==a[k]){
                f=1;
            }
        }
        if(f==1){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                printf("%g ",a[i]);
                break;
            }
        }
    }
    return 0;
}