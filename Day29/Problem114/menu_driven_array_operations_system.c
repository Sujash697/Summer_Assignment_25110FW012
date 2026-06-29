#include <stdio.h>
#define MAX 100
int arr[MAX];
int n=0;
void header();
void insert();
void delete_element();
void search();
void update();
void display();
void reverse();
void sort_asc();
void sort_desc();
void max_min();
void sum_avg();
void frequency();
void pause();
int main()
{
    int choice;
    while (1){
        header();
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Search Element");
        printf("\n4. Update Element");
        printf("\n5. Display Array");
        printf("\n6. Reverse Array");
        printf("\n7. Sort Ascending");
        printf("\n8. Sort Descending");
        printf("\n9. Max & Min");
        printf("\n10. Sum & Average");
        printf("\n11. Frequency of Element");
        printf("\n12. Exit");
        printf("\n\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(); break;
            case 2: delete_element(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: display(); break;
            case 6: reverse(); break;
            case 7: sort_asc(); break;
            case 8: sort_desc(); break;
            case 9: max_min(); break;
            case 10: sum_avg(); break;
            case 11: frequency(); break;
            case 12:
                printf("\nExiting Program...\n");
                return 0;
            default:
                printf("\nInvalid Choice!");
                pause();
        }
    }
}
void header()
{
    printf("\n====================================");
    printf("\n        ARRAY MANAGEMENT SYSTEM     ");
    printf("\n====================================\n");
}
void pause()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
void insert()
{
    int val,pos;
    if(n>=MAX){
        printf("\nArray Full!");
        pause();
        return;
    }
    printf("\nEnter value : ");
    scanf("%d",&val);
    printf("Enter position (0 to %d) : ",n);
    scanf("%d",&pos);
    if(pos<0||pos>n){
        printf("\nInvalid Position!");
        pause();
        return;
    }
    for(int i=n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    n++;
    printf("\nInserted Successfully!");
    pause();
}
void delete_element()
{
    int choice,pos,val,found=0;
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    printf("\n1. Delete by Position");
    printf("\n2. Delete by Value");
    printf("\nEnter choice : ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter position : ");
        scanf("%d",&pos);
        if(pos<0||pos>=n){
            printf("\nInvalid Position!");
            pause();
            return;
        }
        for(int i=pos;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;
        printf("\nDeleted Successfully!");
    }
    else if(choice==2){
        printf("Enter value : ");
        scanf("%d",&val);
        for(int i=0;i<n;i++){
            if(arr[i]==val){
                for(int j=i;j<n-1;j++){
                    arr[j]=arr[j+1];
                }
                n--;
                found=1;
                break;
            }
        }
        if(found)
            printf("\nDeleted Successfully!");
        else
            printf("\nValue Not Found!");
    }
    else{
        printf("\nInvalid Choice!");
    }
    pause();
}
void search()
{
    int val,found=0;
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    printf("\nEnter value : ");
    scanf("%d",&val);
    printf("\nPositions: ");
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            printf("%d ",i);
            found=1;
        }
    }
    if(!found)
        printf("Not Found");
    pause();
}
void update()
{
    int pos,val;
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    printf("\nEnter position : ");
    scanf("%d",&pos);
    if(pos<0||pos>=n){
        printf("\nInvalid Position!");
        pause();
        return;
    }
    printf("Enter new value: ");
    scanf("%d",&val);
    arr[pos]=val;
    printf("\nUpdated Successfully!");
    pause();
}
void display()
{
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    printf("\nArray Elements:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    pause();
}
void reverse()
{
    int i=0,j=n-1,temp;
    while(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    printf("\nArray Reversed!");
    pause();
}
void sort_asc()
{
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nSorted Ascending!");
    pause();
}
void sort_desc()
{
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nSorted Descending!");
    pause();
}
void max_min()
{
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    int max=arr[0],min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("\nMax = %d",max);
    printf("\nMin = %d",min);
    pause();
}
void sum_avg()
{
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("\nSum = %d",sum);
    printf("\nAverage = %.2f",(float)sum/n);
    pause();
}
void frequency()
{
    int val,count=0;
    if(n==0){
        printf("\nArray Empty!");
        pause();
        return;
    }
    printf("\nEnter value: ");
    scanf("%d",&val);
    for(int i=0;i<n;i++){
        if(arr[i]==val)
            count++;
    }
    printf("\nFrequency = %d",count);
    pause();
}