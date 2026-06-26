#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int l,c=0,a,b;
    printf("Enter level 1/2/3 = ");
    scanf("%d",&l);
    if(l==1){
        b=50;
    }
    else if(l==2){
        b=100;
    }
    else if(l==3){
        b=1000;
    }
    else{
        printf("Invalid input");
        return 0;
    }
    srand(time(NULL));
    int n=(rand()%b)+1;
    printf("Number is generated between 1 to %d. You start guessing =>\n",b);
    do{
        printf("Enter your guess = ");
        scanf("%d",&a);
        if(a>n){
            printf("Too high\n");
        }
        else if(a<n){
            printf("Too low\n");
        }
        printf("------------------\n");
        c++;
    }
    while(a!=n);
    printf("Correct, no. of attempts = %d",c);
    return 0;
}