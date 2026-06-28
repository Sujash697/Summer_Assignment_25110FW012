#include<stdio.h>
#include<string.h>
#include<unistd.h>
int pass;
char name[50],user[50];
typedef struct account{
    int accno;
    char name[50];
    int age;
    char gender[10];
    char type[20];
    char phone[15];
    char address[100];
    float balance;
}a;
void display();
int login();
void dashboard();
void create();
void view();
void search();
void loading();
void deposit();
void withdraw();
void deleteaccount();
void report();
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
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|       BANK ACCOUNT MANAGEMENT SYSTEM         |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n");
    printf("\n\n              ADMIN LOGIN");
    for(int i=0;i<10;i++)
    {
        printf(" .");
        fflush(stdout);
        for(long j=0;j<150000000;j++);
    }
    printf("\n\n\n-----------------------------------------------\n");
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
            printf("\nVerifying Credentials");
            for(int i=0;i<5;i++)
            {
                printf(" .");
                fflush(stdout);
                for(long j=0;j<150000000;j++);
            }
            printf("\n\nLoading");
            for(int i=0;i<3;i++)
            {
                printf(".");
                fflush(stdout);
                for(long j=0;j<150000000;j++);
            }
            printf("\n");
            for(int i=0;i<20;i++)
            {
                printf("█");
                fflush(stdout);
                usleep(50000);
            }
            printf(" 100%%");
            printf("\n\nWelcome %s!\n",name);
            return 1;
        }
        else
        {
            if(i>1)
                printf("Incorrect Username or Password.\nAttempts Left : %d\n\n",i-1);
        }
    }
    return 0;
}
void dashboard()
{
    int ch;
    while(1)
    {
        printf("\n               MAIN DASHBOARD\n");
        printf("+----------------------------------------------+\n");
        printf("|  [1] Create Account     [5] Withdraw Money   |\n");
        printf("|                                              |\n");
        printf("|  [2] View Accounts      [6] Delete Account   |\n");
        printf("|                                              |\n");
        printf("|  [3] Search Account     [7] Report           |\n");
        printf("|                                              |\n");
        printf("|  [4] Deposit Money      [8] Exit             |\n");
        printf("+----------------------------------------------+\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            case 3:
                search();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                deleteaccount();
                break;
            case 7:
                report();
                break;
            case 8:
                printf("\nExiting System...\n");
                printf("Thank you for using Bank Account Management System.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void create()
{
    FILE *fp;
    a x;
    fp=fopen("accounts.dat","ab");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("+----------------------------------------------+\n");
    printf("|              CREATE ACCOUNT                  |\n");
    printf("+----------------------------------------------+\n\n");
    printf("Enter Account Number  : ");
    scanf("%d",&x.accno);
    getchar();
    printf("Enter Name            : ");
    scanf("%[^\n]s",x.name);
    getchar();
    printf("Enter Age             : ");
    scanf("%d",&x.age);
    getchar();
    printf("Enter Gender          : ");
    scanf("%[^\n]s",x.gender);
    getchar();
    printf("Enter Account Type    : ");
    scanf("%[^\n]s",x.type);
    getchar();
    printf("Enter Phone Number    : ");
    scanf("%[^\n]s",x.phone);
    getchar();
    printf("Enter Address         : ");
    scanf("%[^\n]s",x.address);
    printf("Enter Opening Balance : ");
    scanf("%f",&x.balance);
    fwrite(&x,sizeof(x),1,fp);
    printf("\n-----------------------------------------------\n");
    printf("\n         Account Created Successfully!         \n");
    printf("\n-----------------------------------------------\n");
    fclose(fp);
}
void view()
{
    FILE *fp;
    a x;
    fp=fopen("accounts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+----------------------------------------------------------------------------------------------+\n");
    printf("|                                  ALL ACCOUNTS                                                |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("\nAcc No   Name                 Type         Phone          Balance\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    while(fread(&x,sizeof(x),1,fp))
    {
        printf("%-8d %-20s %-12s %-14s %10g\n",x.accno,x.name,x.type,x.phone,x.balance);
    }
    printf("-----------------------------------------------------------------------------------------------\n");
    fclose(fp);
}
void search()
{
    FILE *fp;
    a x;
    int key,found=0;
    fp=fopen("accounts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|              SEARCH ACCOUNT                 |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Account Number : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.accno==key)
        {
            printf("\n==== ACCOUNT FOUND ====\n");
            printf("Account Number : %d\n",x.accno);
            printf("Name           : %s\n",x.name);
            printf("Age            : %d\n",x.age);
            printf("Gender         : %s\n",x.gender);
            printf("Account Type   : %s\n",x.type);
            printf("Phone Number   : %s\n",x.phone);
            printf("Address        : %s\n",x.address);
            printf("Balance        : %g\n",x.balance);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nAccount Not Found!\n");
    printf("----------------------------------------------\n");
    fclose(fp);
}
void loading()
{
    for(int i=0;i<5;i++)
    {
        printf(".");
        fflush(stdout);
        usleep(200000);
    }
    printf("\n");
}
void deposit()
{
    FILE *fp,*temp;
    a x;
    int key,found=0;
    float amount;
    fp=fopen("accounts.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|              DEPOSIT MONEY                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Account Number : ");
    scanf("%d",&key);
    printf("Enter Amount         : ");
    scanf("%f",&amount);
    printf("\nSearching");
    loading();
    if(amount<=0)
    {
        printf("Invalid Amount\n");
        fclose(fp);
        fclose(temp);
        remove("temp.dat");
        return;
    }
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.accno==key)
        {
            found=1;
            x.balance+=amount;
            printf("\nAmount Deposited Successfully!\n");
            printf("Updated Balance = %g\n",x.balance);
        }
        fwrite(&x,sizeof(x),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
    if(found==0)
        printf("\nAccount Not Found!\n");
}
void withdraw()
{
    FILE *fp,*temp;
    a x;
    int key,found=0;
    float amount;
    fp=fopen("accounts.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|             WITHDRAW MONEY                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Account Number : ");
    scanf("%d",&key);
    printf("Enter Amount         : ");
    scanf("%f",&amount);
    printf("\nSearching");
    loading();
    if(amount<=0)
    {
        printf("Invalid Amount\n");
        fclose(fp);
        fclose(temp);
        remove("temp.dat");
        return;
    }
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.accno==key)
        {
            found=1;
            if(x.balance>=amount)
            {
                x.balance-=amount;
                printf("\nAmount Withdrawn Successfully!\n");
                printf("Remaining Balance = %g\n",x.balance);
            }
            else
                printf("\nInsufficient Balance!\n");
        }
        fwrite(&x,sizeof(x),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
    if(found==0)
        printf("\nAccount Not Found!\n");
}
void deleteaccount()
{
    FILE *fp,*temp;
    a x;
    int key,found=0;
    fp=fopen("accounts.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|             DELETE ACCOUNT                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Account Number : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.accno==key)
        {
            found=1;
            printf("\nAccount Deleted Successfully!\n");
            continue;
        }
        fwrite(&x,sizeof(x),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
    if(found==0)
        printf("\nAccount Not Found!\n");
}
void report()
{
    FILE *fp;
    a x;
    int totalaccounts=0,savings=0,current=0;
    float totalbalance=0,highest=0,lowest=0,average;
    fp=fopen("accounts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    while(fread(&x,sizeof(x),1,fp))
    {
        if(totalaccounts==0)
        {
            highest=x.balance;
            lowest=x.balance;
        }
        totalaccounts++;
        totalbalance+=x.balance;
        if(strcmp(x.type,"Savings")==0||strcmp(x.type,"savings")==0)
            savings++;
        if(strcmp(x.type,"Current")==0||strcmp(x.type,"current")==0)
            current++;
        if(x.balance>highest)
            highest=x.balance;
        if(x.balance<lowest)
            lowest=x.balance;
    }
    average=0;
    if(totalaccounts==0)
    {
        printf("No Accounts Found.\n");
        fclose(fp);
        return;
    }
    if(totalaccounts>0)
        average=totalbalance/totalaccounts;
    printf("\n+================================================+\n");
    printf("|               BANK REPORT                      |\n");
    printf("+================================================+\n\n");
    printf("Total Accounts      : %d\n",totalaccounts);
    printf("Savings Accounts    : %d\n",savings);
    printf("Current Accounts    : %d\n",current);
    printf("Total Balance       : %g\n",totalbalance);
    printf("Highest Balance     : %g\n",highest);
    printf("Lowest Balance      : %g\n",lowest);
    printf("Average Balance     : %g\n",average);
    printf("\n--------------------------------------------------\n");
    fclose(fp);
}