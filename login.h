#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int login()
{
    int state=0;
    char username[20];
    char psw[20];

    char or_User[20];
    char or_Psw[20];
    int authstate;

    FILE *fptr;
    fptr=fopen("auth.txt","r+");

    if(fptr == NULL)
    {
        printf("Error on opening file.try again!");
        exit(0);
    }

    fscanf(fptr,"%s %s %d",or_User,or_Psw,&authstate);

    fclose(fptr);


    if(authstate==1)
    {
        state=1;
        system("cls");//if user already logged In

    }
    else
    {
        printf("\t\t\t\t\t\t\t\tEnter your Username: ");
        gets(username);
        printf("\t\t\t\t\t\t\t\tEnter your Password: ");
        gets(psw);

    }


    if(strcmp(username,or_User)==0)
    {
        if(strcmp(psw,or_Psw)==0)
        {
            state=1;
            fptr=fopen("auth.txt","w");
            fprintf(fptr,"%s %s %d",or_User,or_Psw,1);
            fclose(fptr);
            system("cls");
        }
        else
        {
            printf("\t\t\t\t\t\t\t\t-------Password incorrect--------");
            Sleep(1000);
            system("cls");

        }
    }
    return state;



}
