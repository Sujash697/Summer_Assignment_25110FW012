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
void deleteemployee();
void report();
typedef struct Employee{
    int id;
    char name[50];
    int age;
    float salary;
}e;
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
    printf("  EMPLOYEE MANAGEMENT SYSTEM\n");
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
        printf("     EMPLOYEE DASHBOARD\n");
        printf("=================================\n");
        printf("1.📌Add Employee\n");
        printf("2.📋View Employees\n");
        printf("3.🔍Search Employee\n");
        printf("4.❌Delete Employee\n");
        printf("5.📊Employee Report\n");
        printf("6.🚪Logout\n");
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
                deleteemployee();
                break;
            case 5:
                report();
                break;
            case 6:
                printf("\nLogging Out...\n");
                printf("Thank you for using Employee Management System.\n");
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
    e emp;
    printf("----------ADD EMPLOYEE----------\n");
    fp=fopen("employees.txt","a");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Employee ID : ");
    scanf("%d",&emp.id);
    getchar();
    printf("Enter Name : ");
    scanf("%[^\n]s",emp.name);
    printf("Enter Age : ");
    scanf("%d",&emp.age);
    printf("Enter Salary : ");
    scanf("%f",&emp.salary);
    fprintf(fp,"%d|%s|%d|%f\n",emp.id,emp.name,emp.age,emp.salary);
    fclose(fp);
    printf("\nEmployee Added Successfully!\n");
}
void view()
{
    FILE *fp;
    e emp;
    fp=fopen("employees.txt","r");
    printf("\n============================\n");
    printf("      EMPLOYEE LIST\n");
    printf("============================\n");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%f",&emp.id,emp.name,&emp.age,&emp.salary)==4)
    {
        printf("\nEmployee ID : %d",emp.id);
        printf("\nName : %s",emp.name);
        printf("\nAge : %d",emp.age);
        printf("\nSalary : %g\n",emp.salary);
        printf("--------------------------");
    }
    fclose(fp);
}
void search()
{
    FILE *fp;
    e emp;
    int key,found=0;
    fp=fopen("employees.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Employee ID to search : ");
    scanf("%d",&key);
    loading();
    while(fscanf(fp,"%d|%[^|]|%d|%f",&emp.id,emp.name,&emp.age,&emp.salary)==4)
    {
        if(emp.id==key)
        {
            printf("\n=== EMPLOYEE FOUND ===\n");
            printf("Employee ID : %d\n",emp.id);
            printf("Name : %s\n",emp.name);
            printf("Age : %d\n",emp.age);
            printf("Salary : %g\n",emp.salary);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nEmployee with ID %d NOT FOUND\n",key);
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
void deleteemployee()
{
    FILE *fp,*temp;
    e emp;
    int key,found=0;
    fp=fopen("employees.txt","r");
    temp=fopen("temp.txt","w");
    if(fp==NULL||temp==NULL)
    {
        printf("File error\n");
        return;
    }
    printf("Enter Employee ID to delete : ");
    scanf("%d",&key);
    while(fscanf(fp,"%d|%[^|]|%d|%f",&emp.id,emp.name,&emp.age,&emp.salary)==4)
    {
        if(emp.id==key)
        {
            found=1;
        }
        else
        {
            fprintf(temp,"%d|%s|%d|%f\n",emp.id,emp.name,emp.age,emp.salary);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("employees.txt");
    if(rename("temp.txt","employees.txt")!=0)
        printf("Error renaming file.\n");
    if(found)
        printf("\nEmployee Record Deleted Successfully!\n");
    else
        printf("\nEmployee Not Found!\n");
}
void report()
{
    FILE *fp;
    e emp;
    int count=0;
    float total=0,max,min;
    fp=fopen("employees.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%f",&emp.id,emp.name,&emp.age,&emp.salary)==4)
    {
        if(count==0)
        {
            max=emp.salary;
            min=emp.salary;
        }
        count++;
        total+=emp.salary;
        if(emp.salary>max)
            max=emp.salary;
        if(emp.salary<min)
            min=emp.salary;
    }
    fclose(fp);
    printf("\n==============================\n");
    printf("     EMPLOYEE REPORT\n");
    printf("==============================\n");
    if(count==0)
    {
        printf("No Employee Records Found!\n");
        printf("==============================\n");
        return;
    }
    printf("Total Employees : %d\n",count);
    printf("Average Salary : %g\n",total/count);
    printf("Highest Salary : %g\n",max);
    printf("Lowest Salary : %g\n",min);
    printf("==============================\n");
}