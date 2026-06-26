#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pin,balance;
char name[100];
void insertCard();
void loading();
int login();
void menu();
void balanceEnquiry();
void cashDeposit();
void cashWithdraw();
void fastCash();
void miniStatement();
void transferMoney();
void changePin();
void saveAccount();
void addStatement(char text[]);
int main()
{
    FILE *fp;
    fp=fopen("account.txt","r");
    if(fp==NULL)
    {
        printf("Account file not found.");
        return 0;
    }
    fscanf(fp,"%d",&pin);
    fscanf(fp,"%d",&balance);
    fgetc(fp);
    fgets(name,100,fp);
    name[strcspn(name,"\n")]='\0';
    fclose(fp);
    insertCard();
    if(login())
        menu();
    return 0;
}
void insertCard()
{
    printf("========================================\n");
    printf("             XYZ BANK ATM\n");
    printf("========================================\n\n");
    printf("Please Insert Your ATM Card...\n");
    printf("Press ENTER to insert card...");
    getchar();
    loading();
    printf("\nCard Accepted Successfully.\n\n");
}

void loading()
{
    printf("\nReading Card");
    for(int i=0;i<5;i++)
    {
        printf(".");
        fflush(stdout);
        for(long j=0;j<150000000;j++);
    }
    printf("\n");
}

int login()
{
    int p;
    for(int i=3;i>=1;i--)
    {
        printf("Enter 4-Digit PIN : ");
        scanf("%d",&p);
        if(p==pin)
        {
            printf("\nWelcome %s\n",name);
            return 1;
        }
        else
        {
            if(i>1)
                printf("Incorrect PIN.\nAttempts Left : %d\n\n",i-1);
        }
    }
    printf("\n========================================\n");
    printf("YOUR CARD HAS BEEN BLOCKED.\n");
    printf("PLEASE CONTACT YOUR BANK.\n");
    printf("========================================\n");
    return 0;
}

void saveAccount()
{
    FILE *fp;
    fp=fopen("account.txt","w");
    fprintf(fp,"%d\n",pin);
    fprintf(fp,"%d\n",balance);
    fprintf(fp,"%s",name);
    fclose(fp);
}

void addStatement(char text[])
{
    FILE *fp;
    fp=fopen("statement.txt","a");
    fprintf(fp,"%s\n",text);
    fclose(fp);
}
void balanceEnquiry()
{
    char ch;
    printf("\n========================================\n");
    printf("          BALANCE ENQUIRY\n");
    printf("========================================\n");
    printf("Account Holder : %s\n",name);
    printf("Available Balance : Rs.%d\n",balance);
    printf("\nPrint Receipt? (Y/N) : ");
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y')
        printf("\nReceipt Printed Successfully.\n");
    addStatement("Balance Enquiry");
}

void cashDeposit()
{
    int amt;
    char s[100];
    printf("\n========================================\n");
    printf("           CASH DEPOSIT\n");
    printf("========================================\n");
    printf("Enter Amount : ");
    scanf("%d",&amt);
    if(amt<=0)
    {
        printf("Invalid Amount.\n");
        return;
    }
    if(amt%100!=0)
    {
        printf("Amount should be multiple of 100.\n");
        return;
    }
    printf("\nCounting Cash...\n");
    balance+=amt;
    saveAccount();
    sprintf(s,"Cash Deposited : Rs.%d",amt);
    addStatement(s);
    printf("Deposit Successful.\n");
    printf("Available Balance : Rs.%d\n",balance);
}

void cashWithdraw()
{
    int amt;
    char s[100];
    printf("\n========================================\n");
    printf("         CASH WITHDRAWAL\n");
    printf("========================================\n");
    printf("Enter Amount : ");
    scanf("%d",&amt);
    if(amt<=0)
    {
        printf("Invalid Amount.\n");
        return;
    }
    if(amt%100!=0)
    {
        printf("Amount should be multiple of 100.\n");
        return;
    }
    if(amt>balance)
    {
        printf("Insufficient Balance.\n");
        return;
    }
    printf("\nProcessing Transaction...\n");
    balance-=amt;
    saveAccount();
    sprintf(s,"Cash Withdrawn : Rs.%d",amt);
    addStatement(s);
    printf("Please Collect Your Cash.\n");
    printf("Available Balance : Rs.%d\n",balance);
}

void fastCash()
{
    int ch,amt;
    char s[100];
    printf("\n========================================\n");
    printf("             FAST CASH\n");
    printf("========================================\n");
    printf("1. Rs.500\n");
    printf("2. Rs.1000\n");
    printf("3. Rs.2000\n");
    printf("4. Rs.5000\n");
    printf("5. Rs.10000\n");
    printf("Enter Choice : ");
    scanf("%d",&ch);
    if(ch==1)
        amt=500;
    else if(ch==2)
        amt=1000;
    else if(ch==3)
        amt=2000;
    else if(ch==4)
        amt=5000;
    else if(ch==5)
        amt=10000;
    else
    {
        printf("Invalid Choice.\n");
        return;
    }
    if(amt>balance)
    {
        printf("Insufficient Balance.\n");
        return;
    }
    balance-=amt;
    saveAccount();
    sprintf(s,"Fast Cash : Rs.%d",amt);
    addStatement(s);
    printf("\nPlease Collect Your Cash.\n");
    printf("Available Balance : Rs.%d\n",balance);
}

void menu()
{
    int ch;
    while(1)
    {
        printf("\n========================================\n");
        printf("              MAIN MENU\n");
        printf("========================================\n");
        printf("1. Cash Withdrawal\n");
        printf("2. Cash Deposit\n");
        printf("3. Balance Enquiry\n");
        printf("4. Fast Cash\n");
        printf("5. Mini Statement\n");
        printf("6. Money Transfer\n");
        printf("7. Change PIN\n");
        printf("8. Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                cashWithdraw();
                break;
            case 2:
                cashDeposit();
                break;
            case 3:
                balanceEnquiry();
                break;
            case 4:
                fastCash();
                break;
            case 5:
                miniStatement();
                break;
            case 6:
                transferMoney();
                break;
            case 7:
                changePin();
                break;
            case 8:
                printf("\nPrinting Receipt...\n");
                printf("Thank You For Banking With XYZ BANK.\n");
                printf("Please Collect Your Card.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void miniStatement()
{
    FILE *fp;
    char ch;
    fp=fopen("statement.txt","r");
    if(fp==NULL)
    {
        printf("No Statement Available.\n");
        return;
    }
    printf("\n========================================\n");
    printf("          MINI STATEMENT\n");
    printf("========================================\n");
    while((ch=fgetc(fp))!=EOF)
        printf("%c",ch);
    fclose(fp);
}

void transferMoney()
{
    long long ac;
    int amt;
    char s[100];
    printf("\n========================================\n");
    printf("         MONEY TRANSFER\n");
    printf("========================================\n");
    printf("Enter Account Number : ");
    scanf("%lld",&ac);
    if(ac<=0)
    {
        printf("Invalid Account Number.\n");
        return;
    }
    printf("Enter Amount : ");
    scanf("%d",&amt);
    if(amt<=0)
    {
        printf("Invalid Amount.\n");
        return;
    }
    if(amt>balance)
    {
        printf("Insufficient Balance.\n");
        return;
    }
    balance-=amt;
    saveAccount();
    sprintf(s,"Money Transfer : Rs.%d",amt);
    addStatement(s);
    printf("Transfer Successful.\n");
    printf("Available Balance : Rs.%d\n",balance);
}

void changePin()
{
    int old,new1,new2;
    printf("\n========================================\n");
    printf("            CHANGE PIN\n");
    printf("========================================\n");
    printf("Enter Current PIN : ");
    scanf("%d",&old);
    if(old!=pin)
    {
        printf("Incorrect PIN.\n");
        return;
    }
    printf("Enter New PIN : ");
    scanf("%d",&new1);
    if(new1<1000||new1>9999)
    {
        printf("PIN must be 4 digits.\n");
        return;
    }
    printf("Confirm New PIN : ");
    scanf("%d",&new2);
    if(new1!=new2)
    {
        printf("PIN Does Not Match.\n");
        return;
    }
    pin=new1;
    saveAccount();
    addStatement("PIN Changed");
    printf("PIN Changed Successfully.\n");
}