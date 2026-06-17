#include<stdio.h>
int main()
{
    int n,m,o;
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
    o=m+n;
    float b[m],c[o];
    for(int i=0;i<m;i++){
        printf("Enter element %d = ",i+1);
        scanf("%f",&b[i]);
        c[n+i]=b[i];
    }
    for(int i=0;i<n;i++){
        c[i] = a[i];
    }
    printf("\nUnion array =>");
    for(int i=0;i<o-1;i++){
        for(int k=i+1;k<o;k++){
            if(c[i]==c[k]){
                for(int j=k;j<o-1;j++){
                    c[j]=c[j+1];
                }
                o--;
                k--;
            }
        }
    }
    for(int i=0;i<o;i++){
        printf("\nElement %d = %g",i+1,c[i]);
    }
    return 0;
}