#include<stdio.h>
int main()
{
    int n,s,c=0;
    printf("Enter n (numbers are from 1 to n) : ");
    scanf("%d",&n);
    if(n<2){
        printf("Invalid input");
        return 0;
    }
    s=n*(n+1)/2;
    int a[n-1];
    printf("Enter %d elements with one number missing =>\n",n-1);
    for(int i=0;i<n-1;i++){
        printf("Enter element %d = ",i+1);
        scanf("%d",&a[i]);
        if(a[i]<1||a[i]>n){
            printf("Invalid element");
            return 0;
        }
        c+=a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]==a[j]){
                printf("Don't repeat any element");
                return 0;
            }
        }
    }
    printf("Missing number = %d",s-c);
    return 0;
}