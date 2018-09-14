#include "stum.h"

int opentable()
{
    FILE* fp;
    int f;
    char f_s;

    if(!SAVEFLAG)
    {
        printf("\nyou haven't save , do you want to open a new table (Y/N):");
        do
        {
            scanf("%c",&f_s);
            if(f_s!='y'&&f_s!='Y'&&f_s!='n'&&f_s!='N')
                puts("\nPls enter right chose (Y/N): ");
            fflush(stdin);
        }
        while(f_s!='y'&&f_s!='Y'&&f_s!='n'&&f_s!='N');
    }
    if(f_s=='n'||f_s=='N') return 0;

    FLEN=0;//每次打开、创建新文件将文件长度重置
    SAVEFLAG=1;//每次打开、创建新文件将存储标志重置
    memset(TEMP,0,sizeof(stu));//每次打开清空缓存
    memset(FLAG,0,sizeof(int));//每次打开、创建新文件将删除标志重置
    strcpy(PATH,"table//");//每次打开、创建新文件将路径重置

    puts("\nDo you want create(0)/open(1) a table");
    printf("Pls input your chose: ");
    do
    {
        scanf("%d",&f);
        if(f!=0&&f!=1)
            printf("\nPls enter right chose (0/1): ");
        fflush(stdin);
    }while(f!=0&&f!=1);

    printf("\nPls enter filename: ");
    gets(FILENAME);
    strcat(PATH,FILENAME);

    if(f)
    {
        if((fp=fopen(PATH,"rb"))==NULL)
        {
            puts("\nCan't find file");
            memset(FILENAME,0,sizeof(char));
            return 0;
        }
        else puts("\nOpen file success");
        fseek(fp,0l,2);
        FLEN=ftell(fp)/sizeof(stu);
        rewind(fp);
        fread(TEMP,sizeof(stu),FLEN,fp);
        fclose(fp);
    }
    else    save();
}
