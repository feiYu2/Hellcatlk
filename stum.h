#ifndef STUM_H_INCLUDED
#define STUM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

#define SIZE1 1024
#define SIZE2 20
#define SIZE3 3
#define PLEN 40

typedef struct STU
{
    char name[SIZE2];
    char stu_num[SIZE2];
    float mark[SIZE3]
}stu;

stu TEMP[SIZE1];//文件内容临时存储
int FLAG[SIZE1];//删除标志，0未删除，1删除
char PATH[PLEN/2];//文件路径
char FILENAME[PLEN/2];//文件名
int FLEN;//文件长度
int SAVEFLAG;//存储标志，0未存储，1存储

int showmenu();
int opentable();
int insert();
int updata();
int delete();
int select();
int save();
int quit();

#endif // STUM_H_INCLUDED
