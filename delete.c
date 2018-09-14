#include "stum.h"

int delete()
{
    char stu_num[SIZE2];
    int i;

    if(!strlen(FILENAME))
    {
        puts("\nPls first create/open a table");
        return 0;
    }

    printf("\nPls enter the stu_num you want to delete: ");
    gets(stu_num);

    for(i=0;i<FLEN;i++)
        if(!strcmp(stu_num,TEMP[i].stu_num))
        {
            FLAG[i]=1;//删除标志位置一
            break;
        }

    if(i>=FLEN)
        puts("\nCan't find this student");
    puts("\nDelete success");
    SAVEFLAG=0;//增、删、改操作之后保存标志重置
}
