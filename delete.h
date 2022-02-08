/*Write a program to delete a specific line from a text file.*/
#include<stdio.h>
#include<stdlib.h>

int deleteRecord()
{
    FILE *fp,*fcp;
    char line;
    int del_line;
    int line_count=0;

    printf("Enter Line delete:");
    scanf("%d",&del_line); //get the line which we want to delete.

    fp=fopen("record.txt","r");
    fcp=fopen("copy.txt","a");

    if(fp==NULL) //check if he file is open.
    {
        printf("Cant open file:");
        exit(1);
    }

    while(fscanf(fp,"%c",&line)!= EOF)
    {
        /*if(line_count != del_line-1)
        {
            fprintf(fcp,"%c",line);
        }*/
        printf("%c",line);
        if(line == '\n')
        {
            line_count+=1;
        }
    }

    fclose(fp);
    fclose(fcp);

    remove("record.txt");
    rename("copy.txt", "record.txt");

    return 0;

}


