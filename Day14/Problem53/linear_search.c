#include<stdio.h>
int main()
{
    int n,l=0;
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
    printf("Search = ");
    scanf("%f",&s);
    for(int i=0;i<n;i++){
        if(s==a[i]){
            l=i+1;
            break;
        }
    }
    if(l==0){
        printf("Element not found");
    }
    else{
        printf("Element found at location = %d",l);
    }
    return 0;
}