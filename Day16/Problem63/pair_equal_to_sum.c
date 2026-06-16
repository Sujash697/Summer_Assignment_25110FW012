#include<stdio.h>
int main()
{
    int n,c=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n],s;
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    printf("Enter the sum = ");
    scanf("%f",&s);
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(s==a[i]+a[k]){
                printf("Pair => (%g,%g)\n",a[i],a[k]);
                c=1;
            }
        }
    }
    if(c==0){
        printf("No pair found");
    }
    return 0;
}