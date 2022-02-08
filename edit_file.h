#include<stdlib.h>
int edit_data()
{

    printf("\t\t\t\t\t\t\t\t_______________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                    \e[32mEdit Data\e[34m      \n\n");
    printf("\t\t\t\t\t\t\t\t_______________________________________________\n\n");

    FILE *fp,*fcp;
    int del_line;
    int del_state=0;

    int id;
    char name[30];
    char bodytype[30];
    char fueltype[30];
    char transmision[30];
    int engincc;
    int seats;
    float price;
    createbox();
    gotoxy(0,6);
    printf("\t\t\t\t\t\t\t\tEnter ID to Edit:\n\n");
    gotoxy(90,6);
    scanf("%d",&del_line);//get the line which we want to edit.

    fp=fopen("record.txt","r");
    fcp=fopen("copy.txt","a");

    if(fp==NULL) //check if he file is open.
    {
        printf("Cant open file:");
        exit(1);
    }

    while(fscanf(fp,"%d %s %s %s %s %d %d %f",&id,name,bodytype,fueltype,transmision,&engincc,&seats,&price)!= EOF)
    {
        if(del_line == id)
        {
            gotoxy(0,7);
            printf("\t\t\t\t\t\t\t\tVehical Name(toyota-121): \n\n");
            printf("\t\t\t\t\t\t\t\tBody type: \n\n");
            printf("\t\t\t\t\t\t\t\tFuel Type: \n\n");
            printf("\t\t\t\t\t\t\t\tTransmision: \n\n");
            printf("\t\t\t\t\t\t\t\tEngin(cc): \n\n");
            printf("\t\t\t\t\t\t\t\tNo of seats: \n\n");
            printf("\t\t\t\t\t\t\t\tPrice: \n\n");

            gotoxy(92,7);
            scanf("%s",name);
            gotoxy(92,9);


            scanf("%s",bodytype);
            gotoxy(92,11);

            scanf("%s",fueltype);
            gotoxy(92,13);

            scanf("%s",transmision);
            gotoxy(92,15);

            scanf("%d",&engincc);
            gotoxy(92,17);

            scanf("%d",&seats);
            gotoxy(92,19);

            scanf("%f",&price);
            fprintf(fcp,"%d %s %s %s %s %d %d %f\n",id,name,bodytype,fueltype,transmision,engincc,seats,price);

        }
        else
        {
            fprintf(fcp,"%d %s %s %s %s %d %d %f\n",id,name,bodytype,fueltype,transmision,engincc,seats,price);
            del_state=1;
        }

    }
    gotoxy(0,25);

    if(del_state == 0)
    {
        printf("\t\t\t\t\t\t\t\t-----------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t                RECORD UPDATED                \n\n");
        printf("\t\t\t\t\t\t\t\t-----------------------------------------------\n\n");

        Sleep(1000);

    }
    else
    {
        printf("\t\t\t\t\t\t\t\t-----------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t                NO RECORD FOUND                \n\n");
        printf("\t\t\t\t\t\t\t\t-----------------------------------------------\n\n");
        Sleep(1000);
    }

    fclose(fp);
    fclose(fcp);

    remove("record.txt");
    rename("copy.txt", "record.txt");

    return 1;

}
