int logout()
{
    int state=0;

    FILE *fp,*fcp;

    char name[20];
    char psw[20];
    int authState;
    fp=fopen("auth.txt","r");
    fcp=fopen("copy.txt","w");


    if(fp==NULL)
    {
        printf("cant open file");
        exit(0);
    }

    while(fscanf(fp,"%s %s %d",name,psw,&authState)!= EOF)
    {
        fprintf(fcp,"%s %s %d",name,psw,state);
    }




    fclose(fp);
    fclose(fcp);
    remove("auth.txt");
    rename("copy.txt", "auth.txt");
    return 0;
}
