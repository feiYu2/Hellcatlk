#include "stum.h"

int insert()
{
    int i;
    int f;

    if(!strlen(FILENAME))
    {
        puts("\nPls first create/open a table");
        return 0;
    }

    puts("\nPls enter students' name , stu_num , mark");
    gets(TEMP[FLEN].name);

    do
    {
        gets(TEMP[FLEN].stu_num);
        for(f=0,i=0;i<FLEN;i++)
            if(!FLAG[i])
                if(!strcmp(TEMP[FLEN].stu_num,TEMP[i].stu_num))
                {
                    f=1;
                    break;
                }
        if(f)
            puts("\nPls enter a nonredundant stu_num: ");
    }while(f);

    for(i=0;i<SIZE3;i++)
    {
        scanf("%f",&TEMP[FLEN].mark[i]);
        getchar();
    }
    FLEN++;

    puts("\nInsert success");
    SAVEFLAG=0;//增、删、改操作之后保存标志重置
}
