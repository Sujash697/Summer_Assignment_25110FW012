#include<stdio.h>
int main()
{
    int n,m,t=0,f;
    printf("Enter number of elements in 1st array : ");
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
    printf("\nEnter number of elements in 2nd array : ");
    scanf("%d",&m);
    if(m<1){
        printf("Invalid input");
        return 0;
    }
    float b[m],d[n];
    for(int i=0;i<m;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            f=0;
            if(a[i]==b[j]){
                for(int k=0;k<t;k++){
                    if(d[k]==a[i]){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    d[t]=a[i];
                    t++;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
    printf("\nIntersection array =>");
    for(int i=0;i<t;i++){
        printf("\nElement %d = %g",i+1,d[i]);
    }
        return 0;
}