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
void deletestudent();
void report();
typedef struct Student {
    int roll;
    char name[50];
    int age;
    float percentage;
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
    fgets(name,100,fp);
    name[strcspn(name,"\n")]='\0';
    fclose(fp);
    display();
    return 0;
}
void display()
{
    printf("===============================\n");
    printf("   STUDENT MANAGEMENT SYSTEM\n");
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
    return;
}
int login()
{
    int p;
    char u[50];
    for(int i=3;i>=1;i--)
    {
        printf("Enter username : ");
        scanf("%s",u);
        printf("Enter password : ");
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
    while(1){
        printf("\n=================================\n");
        printf("        STUDENT DASHBOARD\n");
        printf("=================================\n");
        printf("1.📌Add New Student\n");
        printf("2.📋View All Students\n");
        printf("3.🔍Search Student\n");
        printf("4.❌Delete Student\n");
        printf("5.📊Class Report\n");
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
                deletestudent();
                break;
            case 5:
                report();
                break;
            case 6:
                printf("\nLogging Out...\n");
                printf("Thank you for using Student Management System.\n");
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
    s st;
    printf("----------ADD STUDENT----------\n");
    fp=fopen("students.txt","a");
    if(fp==NULL){
        printf("File not found\n");
        return ;
    }
    printf("Enter Roll No    : ");
    scanf("%d",&st.roll);
    getchar();
    printf("Enter Name       : ");
    scanf("%[^\n]s",st.name);
    printf("Enter Age        : ");
    scanf("%d",&st.age);
    printf("Enter Percentage : ");
    scanf("%f",&st.percentage);
    fprintf(fp,"%d|%s|%d|%f\n",st.roll,st.name,st.age,st.percentage);
    fclose(fp);
    printf("\nStudent Added Successfully!\n");
}
void view()
{
    FILE *fp;
    s st;
    fp=fopen("students.txt","r");
    printf("\n============================\n");
    printf("        STUDENT LIST\n");
    printf("============================\n");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%f",&st.roll,st.name,&st.age,&st.percentage)==4){
        printf("\nRoll No    : %d", st.roll);
        printf("\nName       : %s", st.name);
        printf("\nAge        : %d", st.age);
        printf("\nPercentage : %g\n",st.percentage);
        printf("--------------------------");
    }
    fclose(fp);
}
void search()
{
    FILE *fp;
    int key,found=0;
    s st;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Roll No to search : ");
    scanf("%d",&key);
    loading();
    while(fscanf(fp,"%d|%[^|]|%d|%f",&st.roll,st.name,&st.age,&st.percentage)==4){
        if(st.roll==key){
            printf("\n=== STUDENT FOUND ===\n");
            printf("Roll No    : %d\n",st.roll);
            printf("Name       : %s\n",st.name);
            printf("Age        : %d\n",st.age);
            printf("Percentage : %g\n",st.percentage);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nStudent with Roll No %d NOT FOUND\n", key);
    }
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
void deletestudent()
{
    FILE *fp,*temp;
    s st;
    int key,found=0;
    fp=fopen("students.txt", "r");
    temp=fopen("temp.txt", "w");
    if(fp==NULL||temp==NULL)
    {
        printf("File error\n");
        return;
    }
    printf("Enter Roll No to delete : ");
    scanf("%d", &key);
    while(fscanf(fp,"%d|%[^|]|%d|%f",&st.roll,st.name,&st.age,&st.percentage)==4){
        if(st.roll==key)
        {
            found=1;
        }
        else
        {
            fprintf(temp,"%d|%s|%d|%f\n",st.roll,st.name,st.age,st.percentage);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.txt");
    if(rename("temp.txt","students.txt")!=0)
        printf("Error renaming file.\n");
    if(found)
        printf("\nStudent Record Deleted Successfully!\n");
    else
        printf("\nStudent Not Found!\n");
}
void report()
{
    FILE *fp;
    s st;
    int count=0,pass=0,fail=0;
    float total=0,max,min;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%f",&st.roll,st.name,&st.age,&st.percentage)==4)
    {
        if(count==0)
        {
            max=st.percentage;
            min=st.percentage;
        }
        count++;
        total+=st.percentage;
        if(st.percentage>=40)
            pass++;
        else
            fail++;
        if(st.percentage>max)
            max=st.percentage;
        if(st.percentage<min)
            min=st.percentage;
    }
    fclose(fp);
    printf("\n==============================\n");
    printf("        CLASS REPORT\n");
    printf("==============================\n");
    if(count==0)
    {
        printf("No Student Records Found!\n");
        printf("==============================\n");
        return;
    }
    printf("Total Students      : %d\n",count);
    printf("Average Percentage  : %g\n",total/count);
    printf("Highest Percentage  : %g\n",max);
    printf("Lowest Percentage   : %g\n",min);
    printf("Pass Students       : %d\n",pass);
    printf("Fail Students       : %d\n",fail);
    printf("==============================\n");
}