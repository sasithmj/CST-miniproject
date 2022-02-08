#include<stdio.h>
void createbox(){
    for(int i=0;i<=21;i++){
        gotoxy(62,1+i);
        printf("|");
    }

    for(int i=0;i<=21;i++){
        gotoxy(110,1+i);
        printf("|");
    }
    for(int i=0;i<47;i++){
        gotoxy(63+i,22);
        printf("_");
    }


}
int addrecord()
{
    struct Vehical
    {
        int id;
        char name[30];
        char bodytype[30];
        char fueltype[30];
        char transmision[30];
        int engincc;
        int seats;
        float price;
    } vehical;

    char name[30];
    char bodytype[30];
    char fueltype[30];
    char transmision[30];


    FILE *fptr;
    fptr = fopen("record.txt","a");


    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t-----------------------");
        printf("\t\t\t\t\t\t Cant open record file ");
        printf("\t\t\t\t\t\t-----------------------");

        Sleep(2000);
        system("cls");
        mainmenu();
    }
    printf("\t\t\t\t\t\t\t\t_____________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                 \e[32mVehical record\e[34m              \n\n");
    printf("\t\t\t\t\t\t\t\t_____________________________________________\n\n");

    printf("\t\t\t\t\t\t\t\tVehical id: \n\n");

    printf("\t\t\t\t\t\t\t\tVehical Name(toyota-121): \n\n");

    printf("\t\t\t\t\t\t\t\tBody type: \n\n");


    printf("\t\t\t\t\t\t\t\tFuel Type: \n\n");


    printf("\t\t\t\t\t\t\t\tTransmision: \n\n");


    printf("\t\t\t\t\t\t\t\tEngin(cc): \n\n");

    printf("\t\t\t\t\t\t\t\tNo of seats: \n\n");


    printf("\t\t\t\t\t\t\t\tPrice: \e[30m\n\n");

    createbox();

    gotoxy(92,6);
    scanf("%d",&vehical.id);
    gotoxy(92,8);
    scanf("%s",name);
    gotoxy(92,10);
    scanf("%s",bodytype);
    gotoxy(92,12);
    scanf("%s",fueltype);
    gotoxy(92,14);
    scanf("%s",transmision);
    gotoxy(92,16);
    scanf("%d",&vehical.engincc);
    gotoxy(92,18);
    scanf("%d",&vehical.seats);
    gotoxy(92,20);
    scanf("%f",&vehical.price);
    gotoxy(0,22);






    strcpy(vehical.name,name);
    strcpy(vehical.bodytype,bodytype);
    strcpy(vehical.fueltype,fueltype);
    strcpy(vehical.transmision,transmision);





    fprintf(fptr,"%d %s %s %s %s %d %d %f\n",vehical.id,vehical.name,vehical.bodytype,vehical.fueltype,vehical.transmision,vehical.engincc,vehical.seats,vehical.price);

    fclose(fptr);



    printf("\t\t\t\t\t\t\t\t\e[34m--------------------\n\n");
    printf("\t\t\t\t\t\t\t\tRecord added succeed!\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------\n\n");

    Sleep(2000);
    system("cls");

    return 0;
}

