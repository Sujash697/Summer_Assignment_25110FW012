#include<stdio.h>
int main()
{
    int a,c=0,w=0,s=0;
    printf("==============================\n");
    printf("      QUIZ APPLICATION\n");
    printf("==============================\n");
    printf("Choose the correct option : \n");
    printf("\nQ1. Capital of India?\n");
    printf("1.Delhi\n2.Mumbai\n3.Chennai\n4.Kolkata\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==1){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ2. Red Planet?\n");
    printf("1.Earth\n2.Mars\n3.Jupiter\n4.Venus\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==2){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ3. Days in a week?\n");
    printf("1.5\n2.6\n3.7\n4.8\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==3){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ4. Largest ocean?\n");
    printf("1.Arctic\n2.Indian\n3.Atlantic\n4.Pacific\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==4){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ5. Father of Computer?\n");
    printf("1.Charles Babbage\n2.Newton\n3.Einstein\n4.Tesla\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==1){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ6. Which language is mainly used for Android development?\n");
    printf("1.C\n2.Java\n3.HTML\n4.SQL\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==2){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ7. 12 x 12 = ?\n");
    printf("1.124\n2.142\n3.144\n4.154\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==3){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ8. National animal of India?\n");
    printf("1.Lion\n2.Elephant\n3.Tiger\n4.Leopard\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==3){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ9. Continents in the world?\n");
    printf("1.5\n2.6\n3.7\n4.8\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==3){
        c++;
    }
    else{
        w++;
    }
    printf("\nQ10. Which keyword exits a loop in C?\n");
    printf("1.continue\n2.break\n3.return\n4.goto\n5.Skip\n");
    printf("Answer = ");
    scanf("%d",&a);
    if(a==5){
        s++;
    }
    else if(a==2){
        c++;
    }
    else{
        w++;
    }
    printf("\n==============================\n");
    printf("          RESULT\n");
    printf("==============================\n");
    printf("Correct = %d\nWrong = %d\nSkipped = %d\nScore = %d/10\n",c,w,s,c);
    if(c==10){
        printf("Outstanding");
    }
    else if(c>=8){
        printf("Excellent");
    }
    else if(c>=6){
        printf("Good");
    }
    else if(c>=4){
        printf("Average");
    }
    else{
        printf("Better Luck Next Time");
    }
    return 0;
}