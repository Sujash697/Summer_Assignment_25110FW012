#include<stdio.h>
#include<string.h>
#include<unistd.h>
int pass;
char name[50],user[50];
typedef struct ticket{
    int ticketno;
    char name[50];
    int age;
    char gender[10];
    char source[30];
    char destination[30];
    char date[20];
    int seats;
    float fare;
}t;
void display();
int login();
void dashboard();
void book();
void view();
void search();
void loading();
void cancel();
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
    printf("|          TICKET BOOKING SYSTEM               |\n");
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
        printf("|  [1] Book Ticket       [5] Report            |\n");
        printf("|                                              |\n");
        printf("|  [2] View Tickets      [6] Exit              |\n");
        printf("|                                              |\n");
        printf("|  [3] Search Ticket                           |\n");
        printf("|                                              |\n");
        printf("|  [4] Cancel Ticket                           |\n");
        printf("+----------------------------------------------+\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                book();
                break;
            case 2:
                view();
                break;
            case 3:
                search();
                break;
            case 4:
                cancel();
                break;
            case 5:
                report();
                break;
            case 6:
                printf("\nExiting System...\n");
                printf("Thank you for using Ticket Booking System.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void book()
{
    FILE *fp;
    t x;
    fp=fopen("tickets.dat","ab");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("+----------------------------------------------+\n");
    printf("|               BOOK TICKET                    |\n");
    printf("+----------------------------------------------+\n\n");
    printf("Enter Ticket Number : ");
    scanf("%d",&x.ticketno);
    getchar();
    printf("Enter Name          : ");
    scanf("%[^\n]s",x.name);
    getchar();
    printf("Enter Age           : ");
    scanf("%d",&x.age);
    getchar();
    printf("Enter Gender        : ");
    scanf("%[^\n]s",x.gender);
    getchar();
    printf("Enter Source        : ");
    scanf("%[^\n]s",x.source);
    getchar();
    printf("Enter Destination   : ");
    scanf("%[^\n]s",x.destination);
    getchar();
    printf("Enter Journey Date  : ");
    scanf("%[^\n]s",x.date);
    getchar();
    printf("Enter Seats         : ");
    scanf("%d",&x.seats);
    printf("Enter Fare          : ");
    scanf("%f",&x.fare);
    fwrite(&x,sizeof(x),1,fp);
    printf("\n-----------------------------------------------\n");
    printf("\n         Ticket Booked Successfully!           \n");
    printf("\n-----------------------------------------------\n");
    fclose(fp);
}
void view()
{
    FILE *fp;
    t x;
    fp=fopen("tickets.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+--------------------------------------------------------------------------------------------------+\n");
    printf("|                                      ALL TICKETS                                                 |\n");
    printf("+--------------------------------------------------------------------------------------------------+\n");
    printf("\nTicket   Name                 Source         Destination    Seats      Fare\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    while(fread(&x,sizeof(x),1,fp))
    {
        printf("%-8d %-20s %-14s %-14s %-10d %8g\n",x.ticketno,x.name,x.source,x.destination,x.seats,x.fare);
    }
    printf("---------------------------------------------------------------------------------------------------\n");
    fclose(fp);
}
void search()
{
    FILE *fp;
    t x;
    int key,found=0;
    fp=fopen("tickets.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|              SEARCH TICKET                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Ticket Number : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.ticketno==key)
        {
            printf("\n==== TICKET FOUND ====\n");
            printf("Ticket Number : %d\n",x.ticketno);
            printf("Name          : %s\n",x.name);
            printf("Age           : %d\n",x.age);
            printf("Gender        : %s\n",x.gender);
            printf("Source        : %s\n",x.source);
            printf("Destination   : %s\n",x.destination);
            printf("Journey Date  : %s\n",x.date);
            printf("Seats         : %d\n",x.seats);
            printf("Fare          : %g\n",x.fare);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nTicket Not Found!\n");
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
void cancel()
{
    FILE *fp,*temp;
    t x;
    int key,found=0;
    fp=fopen("tickets.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|              CANCEL TICKET                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Ticket Number : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.ticketno==key)
        {
            found=1;
            printf("\nTicket Cancelled Successfully!\n");
            continue;
        }
        fwrite(&x,sizeof(x),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("tickets.dat");
    rename("temp.dat","tickets.dat");
    if(found==0)
        printf("\nTicket Not Found!\n");
}
void report()
{
    FILE *fp;
    t x;
    int totaltickets=0,totalseats=0;
    float totalfare=0,highest=0,lowest=0,average;
    fp=fopen("tickets.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    while(fread(&x,sizeof(x),1,fp))
    {
        if(totaltickets==0)
        {
            highest=x.fare;
            lowest=x.fare;
        }
        totaltickets++;
        totalseats+=x.seats;
        totalfare+=x.fare;
        if(x.fare>highest)
            highest=x.fare;
        if(x.fare<lowest)
            lowest=x.fare;
    }
    average=0;
    if(totaltickets==0)
    {
        printf("No Tickets Found.\n");
        fclose(fp);
        return;
    }
    if(totaltickets>0)
        average=totalfare/totaltickets;
    printf("\n+================================================+\n");
    printf("|              TICKET REPORT                     |\n");
    printf("+================================================+\n\n");
    printf("Total Tickets     : %d\n",totaltickets);
    printf("Total Seats       : %d\n",totalseats);
    printf("Total Revenue     : %g\n",totalfare);
    printf("Highest Fare      : %g\n",highest);
    printf("Lowest Fare       : %g\n",lowest);
    printf("Average Fare      : %g\n",average);
    printf("\n--------------------------------------------------\n");
    fclose(fp);
}