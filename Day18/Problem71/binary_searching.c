#include<stdio.h>
int main()
{
    int n,end,beg,mid,o;
    float x;
    printf("For ascending order enter 1 and for descending order enter 0 => ");
    scanf("%d",&o);
    if(o!=0&&o!=1){
        printf("Invalid");
    }
    else{
        printf("Enter number of elements : ");
        scanf("%d",&n);
        if(n<1){
            printf("Invalid input");
            return 0;
        }
        float a[n];
        printf("Enter elements in order =>\n");
        for(int i=0;i<n;i++){
            printf("Enter element %d = ",i+1);
            scanf("%f",&a[i]);
        }
        printf("Enter element to search : ");
        scanf("%f",&x);
        beg=0;
        end=n-1;
        mid=(beg+end)/2;
        if(o==1){
            while(beg<=end&&x!=a[mid]){
                if(x<a[mid]){
                    end=mid-1;
                }
                else{
                    beg=mid+1;
                }
                mid=(beg+end)/2;
            }
            if(x==a[mid]){
                printf("Location of the element is %d",mid+1);
            }
            else{
                printf("Element not found");
            }
        }
        else if(o==0){
            while(beg<=end&&x!=a[mid]){
                if(x>a[mid]){
                    end=mid-1;
                }
                else{
                    beg=mid+1;
                }
                mid=(beg+end)/2;
            }
            if(x==a[mid]){
                printf("Location of the element is %d",mid+1);
            }
            else{
                printf("Element not found");
            }
        }
    }
    return 0;
}