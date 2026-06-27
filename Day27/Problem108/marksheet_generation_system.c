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
void marksheet();
typedef struct Student{
    int roll;
    char name[50];
    int class;
    int english;
    int maths;
    int science;
    int computer;
    int hindi;
    int total;
    float percentage;
    char result[5];
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
    printf("=========================================\n");
    printf("      MARKSHEET GENERATION SYSTEM\n");
    printf("=========================================\n");
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
        if(strcmp(u,user)==0&&p==pass)
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
    printf("\n=========================================\n");
    printf("YOUR ACCOUNT HAS BEEN LOCKED.\n");
    printf("PLEASE WAIT FOR 24 HOURS.\n");
    printf("=========================================\n");
    return 0;
}
void dashboard()
{
    int ch;
    while(1)
    {
        printf("\n=========================================\n");
        printf("            MAIN DASHBOARD\n");
        printf("=========================================\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Report\n");
        printf("6. Generate Marksheet\n");
        printf("7. Logout\n");
        printf("=========================================\n");
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
                marksheet();
                break;
            case 7:
                printf("\nLogging Out...\n");
                printf("Thank You For Using Marksheet Generation System.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void add()
{
    FILE *fp;
    s stu;
    printf("\n=========================================\n");
    printf("            ADD STUDENT\n");
    printf("=========================================\n");
    fp=fopen("students.txt","a");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Roll Number : ");
    scanf("%d",&stu.roll);
    getchar();
    printf("Enter Student Name : ");
    scanf("%[^\n]s",stu.name);
    printf("Enter Class : ");
    scanf("%d",&stu.class);
    printf("Enter English Marks : ");
    scanf("%d",&stu.english);
    printf("Enter Maths Marks : ");
    scanf("%d",&stu.maths);
    printf("Enter Science Marks : ");
    scanf("%d",&stu.science);
    printf("Enter Computer Marks : ");
    scanf("%d",&stu.computer);
    printf("Enter Hindi Marks : ");
    scanf("%d",&stu.hindi);
    stu.total=stu.english+stu.maths+stu.science+stu.computer+stu.hindi;
    stu.percentage=stu.total/5.0;
    if(stu.english>=33&&stu.maths>=33&&stu.science>=33&&stu.computer>=33&&stu.hindi>=33)
        strcpy(stu.result,"PASS");
    else
        strcpy(stu.result,"FAIL");
    fprintf(fp,"%d|%s|%d|%d|%d|%d|%d|%d|%d|%.2f|%s\n",stu.roll,stu.name,stu.class,stu.english,stu.maths,stu.science,stu.computer,stu.hindi,stu.total,stu.percentage,stu.result);
    fclose(fp);
    printf("\nStudent Record Added Successfully!\n");
}

void view()
{
    FILE *fp;
    s stu;
    fp=fopen("students.txt","r");
    printf("\n=========================================\n");
    printf("            STUDENT RECORDS\n");
    printf("=========================================\n");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%d|%d|%d|%d|%d|%d|%f|%s",&stu.roll,stu.name,&stu.class,&stu.english,&stu.maths,&stu.science,&stu.computer,&stu.hindi,&stu.total,&stu.percentage,stu.result)==11)
    {
        printf("Roll Number : %d\n",stu.roll);
        printf("Student Name : %s\n",stu.name);
        printf("Class : %d\n",stu.class);
        printf("English : %d\n",stu.english);
        printf("Maths : %d\n",stu.maths);
        printf("Science : %d\n",stu.science);
        printf("Computer : %d\n",stu.computer);
        printf("Hindi : %d\n",stu.hindi);
        printf("Total : %d / 500\n",stu.total);
        printf("Percentage : %.2f%%\n",stu.percentage);
        printf("Result : %s\n",stu.result);
        printf("-----------------------------------------\n");
    }
    fclose(fp);
}

void search()
{
    FILE *fp;
    s stu;
    int key,found=0;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Roll Number to Search : ");
    scanf("%d",&key);
    loading();
    while(fscanf(fp,"%d|%[^|]|%d|%d|%d|%d|%d|%d|%d|%f|%s",&stu.roll,stu.name,&stu.class,&stu.english,&stu.maths,&stu.science,&stu.computer,&stu.hindi,&stu.total,&stu.percentage,stu.result)==11)
    {
        if(stu.roll==key)
        {
            printf("\n=========================================\n");
            printf("           STUDENT FOUND\n");
            printf("=========================================\n");
            printf("Roll Number : %d\n",stu.roll);
            printf("Student Name : %s\n",stu.name);
            printf("Class : %d\n",stu.class);
            printf("English : %d\n",stu.english);
            printf("Maths : %d\n",stu.maths);
            printf("Science : %d\n",stu.science);
            printf("Computer : %d\n",stu.computer);
            printf("Hindi : %d\n",stu.hindi);
            printf("Total : %d / 500\n",stu.total);
            printf("Percentage : %.2f%%\n",stu.percentage);
            printf("Result : %s\n",stu.result);
            printf("=========================================\n");
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nStudent with Roll Number %d Not Found.\n",key);
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
    s stu;
    int key,found=0;
    fp=fopen("students.txt","r");
    temp=fopen("temp.txt","w");
    if(fp==NULL||temp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Roll Number to Delete : ");
    scanf("%d",&key);
    while(fscanf(fp,"%d|%[^|]|%d|%d|%d|%d|%d|%d|%d|%f|%s",&stu.roll,stu.name,&stu.class,&stu.english,&stu.maths,&stu.science,&stu.computer,&stu.hindi,&stu.total,&stu.percentage,stu.result)==11)
    {
        if(stu.roll==key)
            found=1;
        else
            fprintf(temp,"%d|%s|%d|%d|%d|%d|%d|%d|%d|%.2f|%s\n",stu.roll,stu.name,stu.class,stu.english,stu.maths,stu.science,stu.computer,stu.hindi,stu.total,stu.percentage,stu.result);
    }
    fclose(fp);
    fclose(temp);
    remove("students.txt");
    if(rename("temp.txt","students.txt")!=0)
        printf("Error Renaming File.\n");
    if(found)
        printf("\nStudent Record Deleted Successfully!\n");
    else
        printf("\nStudent Not Found!\n");
}

void report()
{
    FILE *fp;
    s stu;
    int count=0,passcount=0,failcount=0;
    float totalpercentage=0,max,min;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    while(fscanf(fp,"%d|%[^|]|%d|%d|%d|%d|%d|%d|%d|%f|%s",&stu.roll,stu.name,&stu.class,&stu.english,&stu.maths,&stu.science,&stu.computer,&stu.hindi,&stu.total,&stu.percentage,stu.result)==11)
    {
        if(count==0)
        {
            max=stu.percentage;
            min=stu.percentage;
        }
        count++;
        totalpercentage+=stu.percentage;
        if(strcmp(stu.result,"PASS")==0)
            passcount++;
        else
            failcount++;
        if(stu.percentage>max)
            max=stu.percentage;
        if(stu.percentage<min)
            min=stu.percentage;
    }
    fclose(fp);
    printf("\n=========================================\n");
    printf("               REPORT\n");
    printf("=========================================\n");
    if(count==0)
    {
        printf("No Student Records Found!\n");
        printf("=========================================\n");
        return;
    }
    printf("Total Students : %d\n",count);
    printf("Passed Students : %d\n",passcount);
    printf("Failed Students : %d\n",failcount);
    printf("Highest Percentage : %.2f%%\n",max);
    printf("Lowest Percentage : %.2f%%\n",min);
    printf("Average Percentage : %.2f%%\n",totalpercentage/count);
    printf("=========================================\n");
}

void marksheet()
{
    FILE *fp;
    s stu;
    int key,found=0;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter Roll Number : ");
    scanf("%d",&key);
    loading();
    while(fscanf(fp,"%d|%[^|]|%d|%d|%d|%d|%d|%d|%d|%f|%s",&stu.roll,stu.name,&stu.class,&stu.english,&stu.maths,&stu.science,&stu.computer,&stu.hindi,&stu.total,&stu.percentage,stu.result)==11)
    {
        if(stu.roll==key)
        {
            printf("\n=========================================\n");
            printf("          XYZ PUBLIC SCHOOL\n");
            printf("=========================================\n");
            printf("               MARKSHEET\n");
            printf("=========================================\n");
            printf("Roll Number  : %d\n",stu.roll);
            printf("Student Name : %s\n",stu.name);
            printf("Class        : %d\n",stu.class);
            printf("-----------------------------------------\n");
            printf("%-20s%s\n","Subject","Marks");
            printf("-----------------------------------------\n");
            printf("%-20s%d\n","English",stu.english);
            printf("%-20s%d\n","Maths",stu.maths);
            printf("%-20s%d\n","Science",stu.science);
            printf("%-20s%d\n","Computer",stu.computer);
            printf("%-20s%d\n","Hindi",stu.hindi);
            printf("-----------------------------------------\n");
            printf("Total Marks : %d / 500\n",stu.total);
            printf("Percentage  : %.2f%%\n",stu.percentage);
            printf("Result      : %s\n",stu.result);
            printf("=========================================\n");
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nStudent with Roll Number %d Not Found.\n",key);
    fclose(fp);
}