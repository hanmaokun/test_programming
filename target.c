#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum;
int store[10];

void output()
{
    int i;
    for(i=0;i<10;i++)
        printf(" %d", store[i]);

    printf("\n");
    sum++;
}

void target(int score, int num)
{
    int i;
    //if( (score < 0) || (score > (num+1)*10) )
    if( score > (num+1)*10 )
        return;

    if( 0 == num )
    {
        store[num] = score;
        output();
        return;
    }

    for(i=0;i<=10;++i)
    {
        store[num] = i;
        target(score-i, num-1);
    }
}

int main(int argc, char **argv)
{
    target(90, 9);
    printf("sum = %d\n", sum);
    return 0;
}
