#include<stdio.h>
#include<math.h>
#include<unistd.h>
#define PI 3.14159
float memory=0;
void loading();
void dashboard();
void basic();
void scientific();
void advanced();
int main()
{
    printf("==============================\n");
    printf("     SCIENTIFIC CALCULATOR    \n");
    printf("==============================\n");
    printf("Loading system");
    loading();
    printf("==============================\n");
    dashboard();
    return 0;
}
void loading()
{
    for(int i=0;i<5;i++)
    {
        printf(" .");
        fflush(stdout);
        usleep(200000);
    }
    printf("\n");
}
void dashboard()
{
    int ch,x;
    while(1){
        printf("\n===========================");
        printf("\n       MAIN DASHBOARD\n");
        printf("===========================");
        printf("\n\n1. Basic Calculator");
        printf("\n2. Scientific Calculator");
        printf("\n3. Advanced Tools");
        printf("\n0. Exit");
        printf("\n\n===========================");
        printf("\nSelect Mode : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                basic();
                break;
            case 2:
                scientific();
                break;
            case 3:
                advanced();
                break;
            case 0:
                printf("Are you sure you want to exit?\n");
                printf("1. Yes");
                printf("\n2. No");
                printf("\nSelect : ");
                scanf("%d",&x);
                switch(x){
                    case 1:
                        printf("===========================");
                        printf("\nThank You\n");
                        printf("===============================");
                        printf("\nCalculator Closed Successfully\n");
                        printf("===============================");
                        return;
                    case 2:
                        break;
                    default:
                        printf("Invalid Input\n");
                }
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}
void basic()
{
    float a,b,r;
    int c,d,x;
    char op;
    while(1){
        printf("\n===============================\n");
        printf("       BASIC CALCULATOR        \n");
        printf("===============================\n");
        printf("a = ");
        scanf("%f",&a);
        printf("b = ");
        scanf("%f",&b);
        printf("Operations :\n");
        printf("+   Addition\n");
        printf("-   Subtraction\n");
        printf("*   Multiplication\n");
        printf("/   Division\n");
        printf("%%   Modulus\n");
        getchar();
        printf("Operator : ");
        scanf("%c",&op);
        switch(op){
            case '+':
                r=a+b;
                break;
            case '-':
                r=a-b;
                break;
            case '*':
                r=a*b;
                break;
            case '/':
                if(b==0){
                    printf("Error: Division by zero\n");
                    continue;
                }else{
                    r=a/b;
                }
                break;
            case '%':
                if(b==0){
                    printf("Error: Modulus by zero\n");
                    continue;
                }else{
                    printf("Note: Using integer values\n");
                    c=a;
                    d=b;
                    r=c%d;
                }
                break;
            default:
                printf("Invalid Input\n");
                continue;
        }
        printf("\n|Result : %g|\n",r);
        printf("-------------------------\n");
        printf("1. Calculate again\n");
        printf("2. Back\n");
        printf("Enter : ");
        scanf("%d",&x);
        if(x==2){
            return;
        }
    }
}
void scientific()
{
    float a,b,r;
    int x,ch;
    while(1){
        printf("\n===============================\n");
        printf("     SCIENTIFIC CALCULATOR     \n");
        printf("===============================\n");
        printf("1. sin\n");
        printf("2. cos\n");
        printf("3. tan\n");
        printf("4. log10\n");
        printf("5. ln\n");
        printf("6. sqrt\n");
        printf("7. cbrt\n");
        printf("8. pow\n");
        printf("9. Back\n");
        printf("Select : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Angle in degree : ");
                scanf("%f",&a);
                r=sin(a*PI/180);
                printf("Result : %g\n",r);
                break;
            case 2:
                printf("Angle in degree : ");
                scanf("%f",&a);
                r=cos(a*PI/180);
                printf("Result : %g\n",r);
                break;
            case 3:
                printf("Angle in degree: ");
                scanf("%f",&a);
                r=tan(a*PI/180);
                if((int)a%90==0&&((int)a/90)%2!=0)
                    printf("Warning : tan undefined\n");
                else
                        printf("Result : %g\n",r);
                break;
            case 4:
                printf("Num : ");
                scanf("%f",&a);
                if(a<=0){
                    printf("Error: invalid input\n");
                }else{
                    r=log10(a);
                    printf("Result : %g\n",r);
                }
                break;
            case 5:
                printf("Num : ");
                scanf("%f",&a);
                if(a<=0){
                    printf("Error: invalid input\n");
                }else{
                    r=log(a);
                    printf("Result : %g\n",r);
                }
                break;
            case 6:
                printf("Num : ");
                scanf("%f",&a);
                if(a<0){
                    printf("Error: negative not allowed\n");
                }else{
                    r=sqrt(a);
                    printf("Result : %g\n",r);
                }
                break;
            case 7:
                printf("Num : ");
                scanf("%f",&a);
                r=cbrt(a);
                printf("Result : %g\n",r);
                break;
            case 8:
                printf("Base : ");
                scanf("%f",&a);
                printf("Power : ");
                scanf("%f",&b);
                r=pow(a,b);
                printf("Result : %g\n",r);
                break;
            case 9:
                return;
            default:
                printf("Invalid Input\n");
        }
        printf("\n-------------------------------\n");
    }
}
void advanced()
{
    int ch;
    while(1)
    {
        printf("\n====================================\n");
        printf("         ADVANCED TOOLS\n");
        printf("====================================\n");
        printf("1. Factorial (n!)\n");
        printf("2. Percentage Calculator\n");
        printf("3. Absolute Value\n");
        printf("4. Memory Operations\n");
        printf("5. Back\n");
        printf("====================================\n");
        printf("Select Option : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        {
            int n;
            long long fact=1;
            printf("Enter n : ");
            scanf("%d",&n);
            if(n<0)
            {
                printf("Invalid Input\n");
            }
            else
            {
                for(int i=1;i<=n;i++)
                    fact*=i;
                printf("Factorial = %lld\n",fact);
            }
            break;
        }
        case 2:
        {
            float part, total;
            printf("Enter part : ");
            scanf("%f",&part);
            printf("Enter total : ");
            scanf("%f",&total);
            if(total==0)
            {
                printf("Error : Division by zero\n");
            }
            else
            {
                printf("Percentage = %g%%\n",(part/total)*100);
            }
            break;
        }
        case 3:
        {
            float a,r;
            printf("Enter number : ");
            scanf("%f",&a);
            if(a<0)
                r=-a;
            else
                r=a;
            printf("Absolute Value = %g\n", r);
            break;
        }
        case 4:
        {
            int m;
            float a;
            printf("\n--- MEMORY OPERATIONS ---\n");
            printf("1. M+ (Add)\n");
            printf("2. MR (Recall)\n");
            printf("3. MC (Clear)\n");
            printf("Select : ");
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    printf("Enter value : ");
                    scanf("%f",&a);
                    memory+=a;
                    printf("Added to memory\n");
                    break;
                case 2:
                    printf("Memory = %g\n",memory);
                    break;
                case 3:
                    memory=0;
                    printf("Memory Cleared\n");
                    break;
                default:
                    printf("Invalid Input\n");
            }
            break;
        }
        case 5:
            return;
        default:
            printf("Invalid Input\n");
        }
    }
}