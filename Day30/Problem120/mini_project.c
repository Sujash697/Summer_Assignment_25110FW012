#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200
char str[MAX];
void header();
void input();
void display();
void length();
void reverse();
void copy_str();
void compare();
void upper();
void lower();
void vowels();
void word_count();
void remove_spaces();
void palindrome();
void substring();
void replace_char();
void frequency();
void pause();
int main()
{
    int choice;
    while(1){
        header();
        printf("\n1. Input String");
        printf("\n2. Display String");
        printf("\n3. Find Length");
        printf("\n4. Reverse String");
        printf("\n5. Copy String");
        printf("\n6. Compare String");
        printf("\n7. Uppercase");
        printf("\n8. Lowercase");
        printf("\n9. Count Vowels");
        printf("\n10. Word Count");
        printf("\n11. Remove Spaces");
        printf("\n12. Palindrome Check");
        printf("\n13. Substring Search");
        printf("\n14. Replace Character");
        printf("\n15. Character Frequency");
        printf("\n16. Exit");
        printf("\n\nEnter choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1: input(); break;
            case 2: display(); break;
            case 3: length(); break;
            case 4: reverse(); break;
            case 5: copy_str(); break;
            case 6: compare(); break;
            case 7: upper(); break;
            case 8: lower(); break;
            case 9: vowels(); break;
            case 10: word_count(); break;
            case 11: remove_spaces(); break;
            case 12: palindrome(); break;
            case 13: substring(); break;
            case 14: replace_char(); break;
            case 15: frequency(); break;
            case 16:
                printf("\nExiting Program...\n");
                return 0;
            default:
                printf("\nInvalid Choice!");
                pause();
        }
    }
}
void header()
{
    printf("\n====================================");
    printf("\n        STRING OPERATION SYSTEM     ");
    printf("\n====================================\n");
}
void pause()
{
    printf("\nPress Enter...");
    getchar();
}
void input()
{
    printf("\nEnter string : ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]=0;
    printf("\nString Stored!");
    pause();
}
void display()
{
    printf("\nString : %s",str);
    pause();
}
void length()
{
    printf("\nLength = %lu",strlen(str));
    pause();
}
void reverse()
{
    int i=0,j=strlen(str)-1;
    char temp;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;j--;
    }
    printf("\nReversed : %s",str);
    pause();
}
void copy_str()
{
    char cpy[MAX];
    strcpy(cpy,str);
    printf("\nCopied : %s",cpy);
    pause();
}
void compare()
{
    char s2[MAX];
    printf("\nEnter string : ");
    fgets(s2,sizeof(s2),stdin);
    s2[strcspn(s2,"\n")]=0;
    int res=strcmp(str,s2);
    if(res==0) printf("\nEqual");
    else if(res>0) printf("\nFirst Greater");
    else printf("\nSecond Greater");
    pause();
}
void upper()
{
    for(int i=0;str[i];i++)
        str[i]=toupper(str[i]);
    printf("\nUpper : %s",str);
    pause();
}
void lower()
{
    for(int i=0;str[i];i++)
        str[i]=tolower(str[i]);
    printf("\nLower : %s",str);
    pause();
}
void vowels()
{
    int c=0;
    for(int i=0;str[i];i++){
        char x=tolower(str[i]);
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
            c++;
    }
    printf("\nVowels = %d",c);
    pause();
}
void word_count()
{
    int c=1;
    for(int i=0;str[i];i++){
        if(str[i]==' ' && str[i+1]!=' ' && str[i+1]!='\0')
            c++;
    }
    printf("\nWords = %d",c);
    pause();
}
void remove_spaces()
{
    int j=0;
    for(int i=0;str[i];i++){
        if(str[i]!=' ')
            str[j++]=str[i];
    }
    str[j]='\0';
    printf("\nNo Spaces : %s",str);
    pause();
}
void palindrome()
{
    int i=0,j=strlen(str)-1,flag=1;
    while(i<j){
        if(str[i]!=str[j]){
            flag=0;
            break;
        }
        i++;j--;
    }
    if(flag) printf("\nPalindrome");
    else printf("\nNot Palindrome");
    pause();
}
void substring()
{
    char s2[MAX];
    printf("\nEnter substring : ");
    fgets(s2,sizeof(s2),stdin);
    s2[strcspn(s2,"\n")]=0;
    if(strstr(str,s2))
        printf("\nFound");
    else
        printf("\nNot Found");
    pause();
}
void replace_char()
{
    char a,b;
    printf("\nEnter char to replace : ");
    scanf(" %c",&a);
    printf("Enter new char : ");
    scanf(" %c",&b);
    for(int i=0;str[i];i++){
        if(str[i]==a)
            str[i]=b;
    }
    printf("\nUpdated : %s",str);
    pause();
}
void frequency()
{
    char c;
    int count=0;
    printf("\nEnter character : ");
    scanf(" %c",&c);
    for(int i=0;str[i];i++){
        if(str[i]==c)
            count++;
    }
    printf("\nFrequency = %d",count);
    pause();
}