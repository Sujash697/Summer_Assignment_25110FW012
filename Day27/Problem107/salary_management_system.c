#include<stdio.h>
#include<unistd.h>
#include<string.h>
int pass;
char name[50],user[50];
void display();
int login();
void dashboard();
void add();
void view();
void search();
void loading();
void deletesalary();
void report();
typedef struct Salary{
    int id;
    char name[50];
    float basic;
    float bonus;
    float total;
}s;
int main()
{
    FILE *fp;
    fp=fopen("login.txt","r");
    if(fp==NULL)
    {
        printf("Login file not found.");
        return 0;
    }
    fscanf(fp,"%s",user);
    fscanf(fp,"%d",&pass);
    fgetc(fp);
    fgets(name,50,fp);
    name[strcspn(name,"\n")]='\0';
    fclose(fp);
    display();
    return 0;
}
void display()
{
    printf("===============================\n");
    printf("   SALARY MANAGEMENT SYSTEM\n");
    printf("===============================\n");
    printf("Login to continue\n");
    for(int i=0;i<9;i++)
    {
        printf("- ");
        fflush(stdout);
        for(long j=0;j<150000000;j++);
    }
    printf("\n");
    if(login())
        dashboard();
}
int login()
{
    int p;
    char u[50];
    for(int i=3;i>=1;i--)
    {
        printf("Enter Username : ");
        scanf("%s",u);
        printf("Enter Password : ");
        scanf("%d",&p);
        if(p==pass&&strcmp(u,user)==0)
        {
            printf("\nWelcome %s!\n",name);
            return 1;
        }
        else
        {
            if(i>1)
                printf("Incorrect Username or Password.\nAttempts Left : %d\n\n",i-1);
        }
    }
    printf("\n========================================\n");
    printf("YOUR ACCOUNT HAS BEEN LOCKED.\n");
    printf("PLEASE WAIT FOR 24 HOURS.\n");
    printf("========================================\n");
    return 0;
}
void dashboard()
{
    int ch;
    while(1)
    {
        printf("\n=================================\n");
        printf("      SALARY DASHBOARD\n");
        printf("=================================\n");
        printf("1.Add Salary Record\n");
        printf("2.View Salary Records\n");
        printf("3.Search Salary Record\n");
        printf("4.Delete Salary Record\n");
        printf("5.Salary Report\n");
        printf("6.Logout\n");
        printf("=================================\n");
        printf("Enter Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                add();
                break;
            case 2:
                view();
                break;
            case 3:
                search();
                break;
            case 4:
                deletesalary();
                break;
            case 5:
                report();
                break;
            case 6:
                printf("\nLogging Out...\n");
                printf("Thank you for using Salary Management System.\n");
                printf("Have a nice day!\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void add()
{
    FILE *fp;
    s sal;
    printf("---------ADD SALARY RECORD---------\n");
    fp=fopen("salary.txt","a");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Employee ID : ");
    scanf("%d",&sal.id);
    getchar();
    printf("Enter Name : ");
    scanf("%[^\n]s",sal.name);
    printf("Enter Basic Salary : ");
    scanf("%f",&sal.basic);
    printf("Enter Bonus : ");
    scanf("%f",&sal.bonus);
    sal.total=sal.basic+sal.bonus;
    fprintf(fp,"%d|%s|%f|%f|%f\n",sal.id,sal.name,sal.basic,sal.bonus,sal.total);
    fclose(fp);
    printf("\nSalary Record Added Successfully!\n");
}
void view()
{
    FILE *fp;
    s sal;
    fp=fopen("salary.txt","r");
    printf("\n============================\n");
    printf("     SALARY RECORDS\n");
    printf("============================\n");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%f|%f|%f",&sal.id,sal.name,&sal.basic,&sal.bonus,&sal.total)==5)
    {
        printf("\nEmployee ID : %d",sal.id);
        printf("\nName : %s",sal.name);
        printf("\nBasic Salary : %g",sal.basic);
        printf("\nBonus : %g",sal.bonus);
        printf("\nTotal Salary : %g\n",sal.total);
        printf("--------------------------");
    }
    fclose(fp);
}
void search()
{
    FILE *fp;
    s sal;
    int key,found=0;
    fp=fopen("salary.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Employee ID to search : ");
    scanf("%d",&key);
    loading();
    while(fscanf(fp,"%d|%[^|]|%f|%f|%f",&sal.id,sal.name,&sal.basic,&sal.bonus,&sal.total)==5)
    {
        if(sal.id==key)
        {
            printf("\n=== SALARY RECORD FOUND ===\n");
            printf("Employee ID : %d\n",sal.id);
            printf("Name : %s\n",sal.name);
            printf("Basic Salary : %g\n",sal.basic);
            printf("Bonus : %g\n",sal.bonus);
            printf("Total Salary : %g\n",sal.total);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nSalary Record Not Found!\n");
    fclose(fp);
}
void loading()
{
    printf("\nSearching");
    for(int i=0;i<5;i++)
    {
        printf(".");
        fflush(stdout);
        usleep(200000);
    }
    printf("\n");
}
void deletesalary()
{
    FILE *fp,*temp;
    s sal;
    int key,found=0;
    fp=fopen("salary.txt","r");
    temp=fopen("temp.txt","w");
    if(fp==NULL||temp==NULL)
    {
        printf("File error\n");
        return;
    }
    printf("Enter Employee ID to delete : ");
    scanf("%d",&key);
    while(fscanf(fp,"%d|%[^|]|%f|%f|%f",&sal.id,sal.name,&sal.basic,&sal.bonus,&sal.total)==5)
    {
        if(sal.id==key)
        {
            found=1;
        }
        else
        {
            fprintf(temp,"%d|%s|%f|%f|%f\n",sal.id,sal.name,sal.basic,sal.bonus,sal.total);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("salary.txt");
    if(rename("temp.txt","salary.txt")!=0)
        printf("Error renaming file.\n");
    if(found)
        printf("\nSalary Record Deleted Successfully!\n");
    else
        printf("\nSalary Record Not Found!\n");
}
void report()
{
    FILE *fp;
    s sal;
    int count=0;
    float total=0,max,min;
    fp=fopen("salary.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%f|%f|%f",&sal.id,sal.name,&sal.basic,&sal.bonus,&sal.total)==5)
    {
        if(count==0)
        {
            max=sal.total;
            min=sal.total;
        }
        count++;
        total+=sal.total;
        if(sal.total>max)
            max=sal.total;
        if(sal.total<min)
            min=sal.total;
    }
    fclose(fp);
    printf("\n==============================\n");
    printf("      SALARY REPORT\n");
    printf("==============================\n");
    if(count==0)
    {
        printf("No Salary Records Found!\n");
        printf("==============================\n");
        return;
    }
    printf("Total Employees : %d\n",count);
    printf("Total Salary Paid : %g\n",total);
    printf("Average Salary : %g\n",total/count);
    printf("Highest Salary : %g\n",max);
    printf("Lowest Salary : %g\n",min);
    printf("==============================\n");
}