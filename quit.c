#include "stum.h"

int quit()
{
    char f;

    if(SAVEFLAG)
    {
        puts("\nThank for your use.");
        exit(0);
    }
    else
    {
        printf("\nYou haven't save , do you want to quit (Y/N):");
        do
        {
            scanf("%c",&f);
            if(f!='y'&&f!='Y'&&f!='n'&&f!='N')
                printf("\nPls enter right chose (Y/N): ");
            fflush(stdin);
        }
        while(f!='y'&&f!='Y'&&f!='n'&&f!='N');

        if(f=='y'||f=='Y')
        {
            puts("\nThank for your use.");
            exit(0);
        }
    }
}
