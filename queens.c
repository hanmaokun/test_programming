#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char     Queen[8][8];
static int    a[8];
static int     b[15];
static int     c[15];
static int    iQueenNum = 0;

void qu(int i);

int main(int argc, char **argv)
{
    int iLine, iColumn;
    for(iLine=0;iLine<8;iLine++)
    {
        a[iLine] = 0;
        for(iColumn=0;iColumn<8;iColumn++)
        {
            Queen[iLine][iColumn] = '*';
        }
    }
    
    for(iLine=0;iLine<15;iLine++)
        b[iLine] = c[iLine] = 0;

    qu(0);

    return 0;    
}

void qu(int i)
{
    int iColumn;
    for(iColumn=0;iColumn<8;iColumn++)
    {
        if(a[iColumn]==0&&b[i-iColumn+7]==0&&c[i+iColumn]==0)
        {
            Queen[i][iColumn]='@';
            a[iColumn] = 1;
            b[i-iColumn+7] = 1;
            c[i+iColumn] = 1;
            if(i<7) qu(i+1);
            else
            {
                int iLine, iColumn;
                printf("the %d th: \n", ++iQueenNum);
                for(iLine=0;iLine<8;iLine++)
                {
                    for(iColumn=0;iColumn<8;iColumn++)
                        printf("%c ", Queen[iLine][iColumn]);
                    printf("\n");

                }
                printf("\n\n");
            }
            Queen[i][iColumn] = '*';
            a[iColumn] = 0;
            b[i-iColumn+7] = 0;
            c[i+iColumn] = 0;
        }

    }
}
