#include<stdlib.h>
int delete_data()
{
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

    printf("\t\t\t\t\t\t\t\t______________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t                 \e[32mDelete Records\e[34m             \n\n");
    printf("\t\t\t\t\t\t\t\t______________________________________________\n\n");

    printf("\t\t\t\t\t\t\t\tEnter ID to delete:");
    scanf("%d",&del_line); //get the line which we want to delete.

    fp=fopen("record.txt","r");
    fcp=fopen("copy.txt","a");

    if(fp==NULL) //check if he file is open.
    {
        printf("Cant open file:");
        exit(1);
    }

    while(fscanf(fp,"%d %s %s %s %s %d %d %f",&id,name,bodytype,fueltype,transmision,&engincc,&seats,&price)!= EOF)
    {
        if(del_line != id)
        {
            fprintf(fcp,"%d %s %s %s %s %d %d %f\n",id,name,bodytype,fueltype,transmision,engincc,seats,price);
            del_state=1;
        }

    }

    if(del_state == 0)
    {
        printf("\t\t-----------------------------------------------\n\n");
        printf("\t\t                NO RECORD FOUND                \n\n");
        printf("\t\t-----------------------------------------------\n\n");

        Sleep(1000);

    }

    fclose(fp);
    fclose(fcp);

    remove("record.txt");
    rename("copy.txt", "record.txt");

    return 1;





}
