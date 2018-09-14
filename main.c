#include "stum.h"

int main()
{
    int f;//清屏标志，0不清屏，1清屏
    SAVEFLAG=1;//初始化存储标志
    while(1)
    {
        f=showmenu();
        switch(f)
        {
            case 1:system("cls");opentable();getchar();break;
            case 2:system("cls");insert();getchar();break;
            case 3:system("cls");delete();getchar();break;
            case 4:system("cls");updata();getchar();break;
            case 5:system("cls");select();getchar();break;
            case 6:system("cls");save();getchar();break;
            case 7:system("cls");quit();getchar();break;
            case 0:system("cls");system("dir table");getchar();
        }
        system("cls");
    }
}
