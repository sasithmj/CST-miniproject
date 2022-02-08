
int search_data()
{
    int search_type;
    int s_id;
    char s_name[30];

    printf("\t\t\t\t\t\t\t\t______________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                 \e[32mSearch Records\e[34m             \n\n");
    printf("\t\t\t\t\t\t\t\t______________________________________________\n\n");

    createbox();
    gotoxy(0,6);
    printf("\t\t\t\t\t\t\t\tsearch by: \t");
    printf("1)ID \n");
    printf("\t\t\t\t\t\t\t\t\t\t2)Name ");
    scanf("%d",&search_type);

    if(search_type==1)
    {
        printf("\n\t\t\t\t\t\t\t\t ID to search: ");
        scanf("%d",&s_id);
        system("cls");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\tEnter Name to search: ");
        scanf("%s",s_name);
        system("cls");

    }

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
    printf("\t\t\t\t\t\t\t\t                  \e[32mResults\e[34m               \n\n");
    printf("\t\t\t\t\t\t\t\t________________________________________\n\n");

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
    gotoxy(0,10);

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
        if(search_type==1)
        {
            if(s_id==id)
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
                for(int i=0; i<140; i++)
                {
                    gotoxy(i,place-2);
                    printf("_");
                }
                break;
            }
        }
        else
        {
            if(strcmp(s_name,name)==0)
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

                place=place+2;
                break;
            }



        }
    }
    gotoxy(0,place+3);

    fclose(fp);

    printf("\e[34m*** 1)Edit record  2)Delete Record  3)Back : ");
    scanf("%d",&sub);

    return sub;
}

