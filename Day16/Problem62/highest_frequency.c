#include<stdio.h>
int main()
{
    int n,c,b=0,f;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input");
        return 0;
    }
    float a[n],x;
    for(int i=0;i<n;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&a[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        f=0;
        for(int k=0;k<i;k++){
            if(a[i]==a[k]){
                f=1;
                break;
            }
        }
        if(f==1){
            continue;
        }
        c=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                c++;
            }
        }
        if(c>b){
            x=a[i];
            b=c;
        }
    }
    printf("Maximum frequency number = %g",x);
    return 0;
}