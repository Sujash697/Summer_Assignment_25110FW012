#include<stdio.h>
int main()
{
    int n,m=0,g=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            m++;
        }
        else{
              g++;
        }
    }
    printf("Even numbers =%d\nOdd numbers =%d",m,g);
}