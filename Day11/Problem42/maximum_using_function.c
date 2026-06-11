#include<stdio.h>
float max(float a[],int n)
{
    float m=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    return m;
}
int main()
{
    int n;
    printf("Enter no. of inputs : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n];
    for(int i=0;i<n;i++){
        printf("Number %d : ",i+1);
        scanf("%f",&a[i]);
    }
    printf("Maximum number = %g",max(a,n));
    return 0;
}