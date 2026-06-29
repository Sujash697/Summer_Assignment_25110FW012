#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "inventory.dat"
typedef struct product{
    int id;
    char name[50];
    int quantity;
    float price;
}product;
void header();
void add();
void view();
void search();
void update();
void delete();
void billing();
void pause();
int main()
{
    int choice;
    while(1){
        header();
        printf("\n1. Add Product");
        printf("\n2. View Products");
        printf("\n3. Search Product");
        printf("\n4. Update Product");
        printf("\n5. Delete Product");
        printf("\n6. Billing");
        printf("\n7. Exit");
        printf("\n\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add(); break;
            case 2: view(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: delete(); break;
            case 6: billing(); break;
            case 7:
                printf("\nExiting Program...");
                exit(0);
            default:
                printf("\nInvalid Choice!");
                pause();
        }
    }
}
void header()
{
    printf("\n====================================");
    printf("\n        INVENTORY SYSTEM");
    printf("\n====================================\n");
}
void pause()
{
    printf("\nPress Enter...");
    getchar();
    getchar();
}
void add()
{
    FILE *fp=fopen(FILE_NAME,"ab");
    product p;
    printf("\nADD PRODUCT");
    printf("\nEnter id : ");
    scanf("%d",&p.id);
    printf("Enter name : ");
    scanf("%s",p.name);
    printf("Enter quantity : ");
    scanf("%d",&p.quantity);
    printf("Enter price : ");
    scanf("%f",&p.price);
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    printf("\nProduct Added!");
    pause();
}
void view()
{
    FILE *fp=fopen(FILE_NAME,"rb");
    product p;
    printf("\nPRODUCT LIST");
    printf("\nID\tNAME\tQTY\tPRICE");
    while(fread(&p,sizeof(p),1,fp)){
        printf("\n%d\t%s\t%d\t%.2f",p.id,p.name,p.quantity,p.price);
    }
    fclose(fp);
    pause();
}
void search()
{
    FILE *fp=fopen(FILE_NAME,"rb");
    product p;
    int id,found=0;
    printf("\nSEARCH PRODUCT");
    printf("\nEnter id : ");
    scanf("%d",&id);
    while(fread(&p,sizeof(p),1,fp)){
        if(p.id==id){
            printf("\nFOUND");
            printf("\nID : %d",p.id);
            printf("\nName : %s",p.name);
            printf("\nQty : %d",p.quantity);
            printf("\nPrice : %.2f",p.price);
            found=1;
            break;
        }
    }
    if(!found)
        printf("\nNot Found");
    fclose(fp);
    pause();
}
void update()
{
    FILE *fp=fopen(FILE_NAME,"rb+");
    product p;
    int id,found=0;
    printf("\nUPDATE PRODUCT");
    printf("\nEnter id : ");
    scanf("%d",&id);
    while(fread(&p,sizeof(p),1,fp)){
        if(p.id==id){
            printf("Enter new name : ");
            scanf("%s",p.name);
            printf("Enter new qty : ");
            scanf("%d",&p.quantity);
            printf("Enter new price : ");
            scanf("%f",&p.price);
            fseek(fp,-sizeof(p),SEEK_CUR);
            fwrite(&p,sizeof(p),1,fp);
            found=1;
            printf("\nUpdated!");
            break;
        }
    }
    if(!found)
        printf("\nNot Found");
    fclose(fp);
    pause();
}
void delete()
{
    FILE *fp=fopen(FILE_NAME,"rb");
    FILE *temp=fopen("temp.dat","wb");
    product p;
    int id,found=0;
    printf("\nDELETE PRODUCT");
    printf("\nEnter id : ");
    scanf("%d",&id);
    while(fread(&p,sizeof(p),1,fp)){
        if(p.id!=id){
            fwrite(&p,sizeof(p),1,temp);
        }else{
            found=1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat",FILE_NAME);
    if(found)
        printf("\nDeleted!");
    else
        printf("\nNot Found");
    pause();
}
void billing()
{
    FILE *fp=fopen(FILE_NAME,"rb+");
    product p;
    int id,qty,found=0;
    float total=0;
    printf("\nBILLING");
    printf("\nEnter id : ");
    scanf("%d",&id);
    while(fread(&p,sizeof(p),1,fp)){
        if(p.id==id){
            printf("Enter qty : ");
            scanf("%d",&qty);
            if(qty<=p.quantity){
                total=qty*p.price;
                p.quantity-=qty;
                fseek(fp,-sizeof(p),SEEK_CUR);
                fwrite(&p,sizeof(p),1,fp);
                printf("\nTotal = %.2f",total);
            }
            else{
                printf("\nNot enough stock");
            }
            found=1;
            break;
        }
    }
    if(!found)
        printf("\nNot Found");
    fclose(fp);
    pause();
}