int find_my_vehical()
{
    int id;
    char name[30];
    char bodytype[30];
    char fueltype[30];
    char transmision[30];
    int engincc;
    int seats;
    float price;

    //for filter.
    float budget;
    char manufacture[30];
    char fuel[30];
    char body[30];
    char trans[30];



    int sub;
    int place=12;



    printf("\t\t\t\t\t\t\t\t___________________________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                          Find my vehical           \n\n");
    printf("\t\t\t\t\t\t\t\t____________________________________________________________\n\n");

    for(int i=0; i<=21; i++)
    {
        gotoxy(62,1+i);
        printf("|");
    }

    for(int i=0; i<=21; i++)
    {
        gotoxy(125,1+i);
        printf("|");
    }
    for(int i=0; i<60; i++)
    {
        gotoxy(63+i,22);
        printf("_");
    }


    gotoxy(0,6);
    printf("\e[31m\t\t\t\t\t\t\t\t*Answer below questions.We can give you a best choice :)*\e[34m\n\n");

    printf("\t\t\t\t\t\t\t\tYour Budget: \n\n");

    printf("\t\t\t\t\t\t\t\tPreferred body type:(sedan/hatchback) \n\n");

    printf("\t\t\t\t\t\t\t\tfuel type:(petrol/diesel/electric) \n\n");

    printf("\t\t\t\t\t\t\t\tTransmission type:(auto/manual) \n\n\e[30m");

    gotoxy(105,8);
    scanf("%f",&budget);
    gotoxy(105,10);
    scanf("%s",body);
    gotoxy(105,12);
    scanf("%s",fuel);
    gotoxy(105,14);
    scanf("%s",trans);
    gotoxy(105,16);

    system("cls");

    printf("\t\t\t\t\t\t\t\t\e[34m___________________________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                        \e[32mFind my vehical\e[34m           \n\n");
    printf("\t\t\t\t\t\t\t\t____________________________________________________________\n\n");

    for(int i=0; i<140; i++)
    {
        gotoxy(i,6);
        printf("-");
    }
    gotoxy(1,8);
    printf("id");
    gotoxy(12,8);
    printf("Name");
    gotoxy(26,8);
    printf("Body Type");
    gotoxy(45,8);
    printf("Fuel Type");
    gotoxy(64,8);
    printf("Transmision");
    gotoxy(85,8);
    printf("EnginCC");
    gotoxy(102,8);
    printf("Seats");
    gotoxy(117,8);
    printf("Price");
    gotoxy(132,8);
    gotoxy(0,9);
    for(int i=0; i<140; i++)
    {
        gotoxy(i,10);
        printf("-");
    }


    FILE *fp;
    fp=fopen("record.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
    }

    while(fscanf(fp,"%d %s %s %s %s %d %d %f",&id,name,bodytype,fueltype,transmision,&engincc,&seats,&price)!= EOF)
    {
        if((budget >= price)&& strcmp(body,bodytype)==0 && strcmp(fueltype,fuel)==0 && strcmp(transmision,trans)==0 )
        {
            gotoxy(1,place);
            printf("\e[30m%d",id);

            gotoxy(12,place);
            printf("%s",name);

            gotoxy(26,place);
            printf("%s",bodytype);

            gotoxy(45,place);
            printf("%s",fueltype);

            gotoxy(64,place);
            printf("%s",transmision);

            gotoxy(85,place);
            printf("%d",engincc);

            gotoxy(102,place);
            printf("%d",seats);

            gotoxy(117,place);
            printf("%f",price);

            place=place+4;
        }
    }
    gotoxy(0,place+3);

    fclose(fp);

    printf("\e[34m*** 1)Back : ");
    scanf("%d",&sub);


    return sub;

}
