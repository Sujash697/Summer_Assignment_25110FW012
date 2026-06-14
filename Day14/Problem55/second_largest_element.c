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
    if(n==1){
        printf("No second largest element present");
        return 0;
    }
    float a[n],m,g,s;
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
        if(i==0){
            m=a[0];
            g=a[0];
        }
        if(m<a[i]){
            m=a[i];
        }
        if(g>a[i]){
            g=a[i];
        }
    }
    s=g;
    for(int i=0;i<n;i++){
        if(s<a[i]&&a[i]!=m){
            s=a[i];
        }
    }
    if(s==m){
        printf("No second largest element present");
        return 0;
    }
    printf("Second largest element = %g",s);
}