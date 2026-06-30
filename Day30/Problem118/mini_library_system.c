#include<stdio.h>
#include<string.h>
#include<unistd.h>
int pass;
char name[50],user[50];
typedef struct books{
    int id;
    char title[100];
    char author[50];
    char category[50];
    int quantity;
}b;
void display();
int login();
void dashboard();
void add();
void view();
void search();
void loading();
void issue();
void back();
void deletebook();
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
    printf("|          LIBRARY MANAGEMENT SYSTEM           |\n");
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
    while(1){
        printf("\n               MAIN DASHBOARD\n");
        printf("+----------------------------------------------+\n");
        printf("|  [1] Add New Book      [5] Return Book       |\n");
        printf("|                                              |\n");
        printf("|  [2] View All Books    [6] Delete Book       |\n");
        printf("|                                              |\n");
        printf("|  [3] Search Book       [7] Report            |\n");
        printf("|                                              |\n");
        printf("|  [4] Issue Book        [8] Exit              |\n");
        printf("+----------------------------------------------+\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
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
                issue();
                break;
            case 5:
                back();
                break;
            case 6:
                deletebook();
                break;
            case 7:
                report();
                break;
            case 8:
                printf("\nExiting System...\n");
                printf("Thank you for using Library Management System.\n");
                return;
            default:
                printf("Invalid Choice.\n");
        }
    }
}
void add()
{
FILE *fp;
fp=fopen("books.dat","ab");
b a;
if(fp==NULL){
    printf("File Error\n");
    return;
}
printf("+----------------------------------------------+\n");
printf("|                 ADD NEW BOOK                 |\n");
printf("+----------------------------------------------+\n\n");
printf("Enter Book ID   : ");
scanf("%d",&a.id);
getchar();
printf("Enter Title     : ");
scanf("%[^\n]s",a.title);
getchar();
printf("Enter Author    : ");
scanf("%[^\n]s",a.author);
getchar();
printf("Enter Category  : ");
scanf("%[^\n]s",a.category);
printf("Enter Quantity  : ");
scanf("%d",&a.quantity);
fwrite(&a,sizeof(a),1,fp);
printf("\n-----------------------------------------------\n");
printf("\n            Book Added Successfully!           \n");
printf("\n-----------------------------------------------\n");
fclose(fp);
}
void view()
{
    FILE *fp;
    b a;
    fp=fopen("books.dat","rb");
    if(fp==NULL){
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|                 ALL BOOKS!                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nID     Title                Author               Category    Qty\n");
    printf("------------------------------------------------------------------\n");
    while(fread(&a,sizeof(a),1,fp)){
    printf("%-6d %-20s %-20s %-11s %-5d\n",a.id,a.title,a.author,a.category,a.quantity);
    }
    printf("------------------------------------------------------------------\n");
    fclose(fp);
}
void search()
{
    int key,found=0;
    FILE *fp;
    b a;
    fp=fopen("books.dat","rb");
    if(fp==NULL){
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|                SEARCH BOOK!                 |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter book ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&a,sizeof(a),1,fp)){
        if(a.id==key){
            printf("\n==== BOOK FOUND ====\n");
            printf("ID        : %d\n",a.id);
            printf("Title     : %s\n",a.title);
            printf("Author    : %s\n",a.author);
            printf("Category  : %s\n",a.category);
            printf("Quantity  : %d\n",a.quantity);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nBook with ID %d NOT FOUND\n", key);
    }
    printf("-----------------------------------\n");
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
void issue()
{
    FILE *fp,*temp;
    b a;
    int found=0,key;
    fp=fopen("books.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|                 ISSUE BOOK                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Book ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&a,sizeof(a),1,fp)){
        if(a.id==key){
            found=1;
            if(a.quantity>0){
                a.quantity--;
                printf("\nBook Issued Successfully!\n");
                printf("Remaining Quantity = %d\n",a.quantity);
            }
            else{
                printf("\nBook Out Of Stock!\n");
            }
        }
       fwrite(&a,sizeof(a),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat","books.dat");
    if(found==0)
        printf("\nBook Not Found!\n");
}
void back()
{
    FILE *fp,*temp;
    b a;
    int found=0,key;
    fp=fopen("books.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|                RETURN BOOK                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Book ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.id==key)
        {
            found=1;
            a.quantity++;
            printf("\nBook Returned Successfully!\n");
            printf("Available Quantity = %d\n",a.quantity);
        }
        fwrite(&a,sizeof(a),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat","books.dat");
    if(found==0)
        printf("\nBook Not Found!\n");
}
void deletebook()
{
    FILE *fp,*temp;
    b a;
    int key,found=0;
    fp=fopen("books.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL||temp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+---------------------------------------------+\n");
    printf("|                DELETE BOOK                  |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter Book ID : ");
    scanf("%d",&key);
    printf("\nSearching");
    loading();
    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.id==key)
        {
            found=1;
            printf("\nBook Deleted Successfully!\n");
            continue;
        }
        fwrite(&a,sizeof(a),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat","books.dat");
    if(found==0)
        printf("\nBook Not Found!\n");
}
void report()
{
    FILE *fp;
    b a;
    int totalbooks=0,totalquantity=0,outofstock=0,lowstock=0;
    fp=fopen("books.dat","rb");
    if(fp==NULL)
    {
        printf("File Error\n");
        return;
    }
    printf("\n+================================================+\n");
    printf("|                 LIBRARY REPORT                 |\n");
    printf("+================================================+\n\n");
    while(fread(&a,sizeof(a),1,fp))
    {
        totalbooks++;
        totalquantity+=a.quantity;
        if(a.quantity==0)
            outofstock++;
        if(a.quantity<=2)
            lowstock++;
    }
    printf("Total Books        : %d\n",totalbooks);
    printf("Total Quantity     : %d\n",totalquantity);
    printf("Out Of Stock Books : %d\n",outofstock);
    printf("Low Stock Books    : %d\n",lowstock);
    printf("\n--------------------------------------------------\n");
    printf("                 LOW STOCK LIST\n");
    printf("--------------------------------------------------\n");
    printf("%-6s %-25s %-10s\n","ID","TITLE","QTY");
    printf("--------------------------------------------------\n");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.quantity<=2)
            printf("%-6d %-25s %-10d\n",a.id,a.title,a.quantity);
    }
    printf("--------------------------------------------------\n");
    fclose(fp);
}