COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int readallrecord()
{
    int id;
    char name[30];
    char bodytype[30];
    char fueltype[30];
    char transmision[30];
    int engincc;
    int seats;
    float price;

    int sub;
    int place=12;



    printf("\t\t\t\t\t\t\t\t________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t              \e[032mAll Records\e[34m  \n\n");
    printf("\t\t\t\t\t\t\t\t________________________________________\n\n");
    for(int i=0; i<140; i++)
    {
        gotoxy(i,6);
        printf("-");
    }
    gotoxy(3,8);
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
        gotoxy(3,place);
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
        printf("%.2f",price);

        place=place+4;
        for(int i=0; i<140; i++)
        {
            gotoxy(i,place-2);
            printf("_");
        }
    }
    gotoxy(0,place+3);

    fclose(fp);

    printf("\e[34m*** 1)Edit record  2)Delete Record  3)Back : ");
    scanf("%d",&sub);


    return sub;
}



