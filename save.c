#include "stum.h"

int save()
{
    int i;
    FILE* fp;

    if(!strlen(FILENAME))
    {
        puts("\nPls first create/open a table");
        return 0;
    }

    if((fp=fopen(PATH,"wb"))==NULL)
    {
        puts("\nFile write error!\n");
        return 0;
    }
    for(i=0;i<FLEN;i++)
        if(!FLAG[i])
            fwrite(&TEMP[i],sizeof(stu),1,fp);
    fclose(fp);

    puts("\nSave file success");
    SAVEFLAG=1;//存储完成后存储标志位置1
}
