#include<stdio.h>
#include<string.h>
#include<unistd.h>
typedef struct contact{
    int id;
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
}c;
void display();
void dashboard();
void add();
void view();
void search();
void loading();
void deletecontact();
void report();
int main()
{
    display();
    return 0;
}
void display()
{
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|         CONTACT MANAGEMENT SYSTEM            |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n");
    printf("\nLoading");
    for(int i=0;i<5;i++)
    {
        printf(".");
        fflush(stdout);
        usleep(200000);
    }
    printf("\n");
    for(int i=0;i<20;i++)
    {
        printf("█");
        fflush(stdout);
        usleep(50000);
    }
    printf(" 100%%\n");
    dashboard();
}
void dashboard()
{
    int ch;
    while(1)
    {
        printf("\n             MAIN DASHBOARD\n");
        printf("+----------------------------------------------+\n");
        printf("|  [1] Add Contact      [5] Report             |\n");
        printf("|                                              |\n");
        printf("|  [2] View Contacts    [6] Exit               |\n");
        printf("|                                              |\n");
        printf("|  [3] Search Contact                          |\n");
        printf("|                                              |\n");
        printf("|  [4] Delete Contact                          |\n");
        printf("+----------------------------------------------+\n");
        printf("\nEnter your choice : ");
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
                deletecontact();
                break;
            case 5:
                report();
                break;
            case 6:
                printf("\nExiting System...\n");
                printf("Thank you for using Contact Management System.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void add()
{
    FILE *fp;
    c x;
    fp=fopen("contacts.dat","ab");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("+----------------------------------------------+\n");
    printf("|               ADD CONTACT                    |\n");
    printf("+----------------------------------------------+\n\n");
    printf("Enter Contact ID : ");
    scanf("%d",&x.id);
    getchar();
    printf("Enter Name       : ");
    scanf("%[^\n]s",x.name);
    getchar();
    printf("Enter Phone      : ");
    scanf("%[^\n]s",x.phone);
    getchar();
    printf("Enter Email      : ");
    scanf("%[^\n]s",x.email);
    getchar();
    printf("Enter Address    : ");
    scanf("%[^\n]s",x.address);
    fwrite(&x,sizeof(x),1,fp);
    printf("\n-----------------------------------------------\n");
    printf("\n        Contact Added Successfully!            \n");
    printf("\n-----------------------------------------------\n");
    fclose(fp);
}
void view()
{
    FILE *fp;
    c x;
    fp=fopen("contacts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+--------------------------------------------------------------------------------------+\n");
    printf("|                                ALL CONTACTS                                          |\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("\nID       Name                 Phone           Email\n");
    printf("----------------------------------------------------------------------------------------\n");
    while(fread(&x,sizeof(x),1,fp))
    {
        printf("%-8d %-20s %-15s %s\n",x.id,x.name,x.phone,x.email);
    }
    printf("----------------------------------------------------------------------------------------\n");
    fclose(fp);
}
void search()
{
    FILE *fp;
    c x;
    int key,found=0;
    fp=fopen("contacts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|             SEARCH CONTACT                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Contact ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.id==key)
        {
            printf("\n==== CONTACT FOUND ====\n");
            printf("Contact ID : %d\n",x.id);
            printf("Name       : %s\n",x.name);
            printf("Phone      : %s\n",x.phone);
            printf("Email      : %s\n",x.email);
            printf("Address    : %s\n",x.address);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nContact Not Found!\n");
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
void deletecontact()
{
    FILE *fp,*temp;
    c x;
    int key,found=0;
    fp=fopen("contacts.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|             DELETE CONTACT                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Contact ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&x,sizeof(x),1,fp))
    {
        if(x.id==key)
        {
            found=1;
            printf("\nContact Deleted Successfully!\n");
            continue;
        }
        fwrite(&x,sizeof(x),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("contacts.dat");
    rename("temp.dat","contacts.dat");
    if(found==0)
        printf("\nContact Not Found!\n");
}
void report()
{
    FILE *fp;
    c x;
    int total=0,highest=0,lowest=0;
    fp=fopen("contacts.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    while(fread(&x,sizeof(x),1,fp))
    {
        if(total==0)
        {
            highest=x.id;
            lowest=x.id;
        }
        total++;
        if(x.id>highest)
            highest=x.id;
        if(x.id<lowest)
            lowest=x.id;
    }
    if(total==0)
    {
        printf("No Contacts Found.\n");
        fclose(fp);
        return;
    }
    printf("\n+================================================+\n");
    printf("|              CONTACT REPORT                    |\n");
    printf("+================================================+\n\n");
    printf("Total Contacts   : %d\n",total);
    printf("Highest ID       : %d\n",highest);
    printf("Lowest ID        : %d\n",lowest);
    printf("\n--------------------------------------------------\n");
    fclose(fp);
}