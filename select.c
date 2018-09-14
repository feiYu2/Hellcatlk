#include "stum.h"
void sort(int f)//f为排序类型标志，0为升序，1位降序
{
	int i,j,t;
	int flag;
	stu temp;

    for(i=0;i<FLEN;i++)
    {
        flag=1;
        for(j=1;j<FLEN-i;j++)
            if( (strcmp(TEMP[j-1].stu_num,TEMP[j].stu_num)>0)&&!f ||
                (strcmp(TEMP[j-1].stu_num,TEMP[j].stu_num)<0)&&f )
            {
                temp=TEMP[j-1];
                TEMP[j-1]=TEMP[j];
                TEMP[j]=temp;

                t=FLAG[j-1];
                FLAG[j-1]=FLAG[j];
                FLAG[j]=t;

                flag=0;
            }
        if(flag) break;
    }
    SAVEFLAG=0;
}

void print()
{
    int i;
    printf("\nNAME\t\tSTU_NUM\t\tMARK_1\t\tMARK_2\t\tMARK_3\n");
    for(i=0;i<FLEN;i++)
        if(!FLAG[i])
            printf("%s\t\t%s\t\t%.1f\t\t%.1f\t\t%.1f\n",
                   TEMP[i].name,TEMP[i].stu_num,
                   TEMP[i].mark[0],TEMP[i].mark[1],TEMP[i].mark[2]);
}

int select()
{
    int flag;
    int i;
    char stu_num[SIZE2];

    if(!strlen(FILENAME))
    {
        puts("\nPls first create/open a table");
        return 0;
    }

    puts("\n0: select");
    puts("1: display all");
    printf("Pls enter your chose : ");
    do
    {
        scanf("%d",&flag);
        if(flag!=0&&flag!=1)
            printf("\nPls enter right chose (0/1): ");
        fflush(stdin);
    }while(flag!=0&&flag!=1);

    if(flag)
    {
        puts("\n1: Don't sort");
        puts("2: ase sort");//升序
        puts("3: desc sort");//降序
        printf("Pls enter your chose: ");
        do
        {
            scanf("%d",&flag);
            if(flag!=1&&flag!=2&&flag!=3)
                printf("Pls enter right chose (1/2/3): ");
            fflush(stdin);
        }while(flag!=1&&flag!=2&&flag!=3);

        switch(flag)
        {
            case 2: sort(0);break;
            case 3: sort(1);break;
        }
        print();
    }
    else
    {
        printf("\nPls enter the stu_num you want to select: ");
        gets(stu_num);

        for(i=0;i<FLEN;i++)
            if(!FLAG[i])
                if(!strcmp(stu_num,TEMP[i].stu_num))
                {
                    printf("\nNAME\t\tSTU_NUM\t\tMARK_1\t\tMARK_2\t\tMARK_3\n");
                    printf("%s\t\t%s\t\t%.1f\t\t%.1f\t\t%.1f\n",
                            TEMP[i].name,TEMP[i].stu_num,
                            TEMP[i].mark[0],TEMP[i].mark[1],TEMP[i].mark[2]);
                    break;
                }

        if(i==FLEN)
            puts("\nCan't find this record");
    }
}
