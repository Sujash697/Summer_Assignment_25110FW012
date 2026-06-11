#include<stdio.h>
float sum(float a,float b){
    return a+b;
}
int main()
{
    float a,b;
    printf("Enter number a : ");
    scanf("%f",&a);
    printf("Enter number b : ");
    scanf("%f",&b);
    printf("Sum of a and b = %g",sum(a,b));
    return 0;
}