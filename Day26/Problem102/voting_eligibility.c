#include<stdio.h>
int main()
{
    int a,b;
    while(1){
        printf("\n===============================\n");
        printf("   VOTING ELIGIBILITY SYSTEM\n");
        printf("===============================\n");
        printf("1.Check Eligibility\n");
        printf("2.Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&b);
        if(b==1){
            printf("Enter Age : ");
            scanf("%d",&a);
            if(a>=18)
                printf("Result : Eligible to Vote\n");
            else if(a>=0)
                printf("Result : Not Eligible to Vote\n");
            else
                printf("Result : Invalid Age\n");
        }
        else if(b==2){
            printf("Exiting System...\n");
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    return 0;
}