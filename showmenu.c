#include "stum.h"

int showmenu()
{
    int f1;
    char f2;
    puts("1: open table");
    puts("2: insert");
    puts("3: delete");
    puts("4: updata");
    puts("5: select");
    puts("6: save");
    puts("7: quit");
    puts("0: show table");
 L: printf("Pls enter your chose: ");
    do
    {
        scanf("%d",&f1);
        if(f1<0||f1>7)
            printf("\nPls enter righe chose (0~7): ");
        fflush(stdin);
    }while(f1<0||f1>7);

    printf("\nDo this operation or not (Y/N) ");
    do
    {
        scanf("%c",&f2);
        getchar();
        if(f2!='y'&&f2!='Y'&&f2!='n'&&f2!='N')
            printf("\nPls enter right chose (Y/N): ");
        fflush(stdin);
    }
    while(f2!='y'&&f2!='Y'&&f2!='n'&&f2!='N');
    if(f2=='n'||f2=='N')
        goto L;

    return f1;
}
