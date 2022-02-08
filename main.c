#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winbase.h>
#include <dos.h>
#include <conio.h>
#include "welcome.h"
#include "login.h"
#include "mainmenu.h"
#include "addrecord.h"
#include "readall.h"
#include "search.h"
#include "delete_data.h"
#include "edit_file.h"
#include "my_vehical.h"
#include "logout.h"



int main()
{
    int state;
    int menustate;
    int readsub;
    system("color F1");
    char name[10];
auth:
    welcome();
    state=login();
    system("cls");//remove this after add auth

    if(state==1)
    {
menu:
        menustate=mainmenu();

        switch(menustate)
        {
        case 01:
            system("cls");
            addrecord();
            goto menu;
            break;
        case 02:
            system("cls");
            edit_data();
            system("cls");
            goto menu;
            break;
        case 03:
            system("cls");
            readsub=readallrecord();
            if(readsub==3)
            {
                system("cls");
                goto menu;
            }
            else if(readsub==2)
            {
                system("cls");
                delete_data();
                system("cls");
                goto menu;
            }
            else if(readsub==1)
            {
                system("cls");
                edit_data();
                system("cls");
                goto menu;
            }
            break;
        case 04:
            system("cls");
            readsub=search_data();
            if(readsub==3)
            {
                system("cls");
                goto menu;
            }
            else if(readsub==2)
            {
                system("cls");
                delete_data();
                system("cls");
                goto menu;
            }
            else if(readsub==1)
            {
                system("cls");
                edit_data();
                system("cls");
                goto menu;
            }
            break;
        case 05:
            system("cls");
            delete_data();
            system("cls");
            goto menu;
            break;

        case 06:
            system("cls");
            readsub=find_my_vehical();
            if(readsub==1)
            {
                system("cls");
                goto menu;
            }
            system("cls");
        case 7:
            state=logout();
            if(state==0){
                system("cls");
                goto auth;
            }
            break;


        case 8:
            exit(0);
            break;
        }

    }
    else
    {
        goto auth;
    }

    return 0;
}


