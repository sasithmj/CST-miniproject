#include<stdio.h>

int mainmenu()
{

    welcome();
    createbox();
    int selected;
    gotoxy(0,6);
    printf("\t\t\t\t\t\t\t\t\t01.Add new record\n");

    printf("\t\t\t\t\t\t\t\t\t02.Edit record\n");

    printf("\t\t\t\t\t\t\t\t\t03.Display All\n");

    printf("\t\t\t\t\t\t\t\t\t04.Search\n");

    printf("\t\t\t\t\t\t\t\t\t05.Delete\n");

    printf("\t\t\t\t\t\t\t\t\t06.Find my vehicle\n");

    printf("\t\t\t\t\t\t\t\t\t07.Logout\n");

    printf("\t\t\t\t\t\t\t\t\t08.Exit\n\n");

    printf("\e[036m\t\t\t\t\t\t\t\tSelect from above:\e[034m ");
    scanf("%d",&selected);
    gotoxy(0,0);



    return selected;



}

