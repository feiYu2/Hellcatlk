#include "stum.h"

int updata()
{
    char stu_num[SIZE2];
    int i,j;

    if(!strlen(FILENAME))
    {
        puts("\nPls first create/open a table");
        return 0;
    }

    printf("\nPls enter the stu_num you want to updata: ");
    gets(stu_num);

    for(i=0;i<FLEN;i++)
        if(!strcmp(stu_num,TEMP[i].stu_num))
        {
            printf("Pls enter the name of this student: ");
            gets(TEMP[i].name);

            puts("Pls enter the mark of this student: ");
            for(j=0;j<SIZE3;j++)
            {
                scanf("%f",&TEMP[i].mark[j]);
                getchar();
            }
            break;

        }

    if(i>=FLEN)
        puts("\nCan't find this student");
    puts("\nUpdata success");
    SAVEFLAG=0;//增、删、改操作之后保存标志重置
}
