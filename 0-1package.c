#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     nVal=9, mVal=10;
int    *p;

void calFunc(int m, int n)
{
    int i;

    if( (m<1) || (n<1) || ( (n==1)&&(m!=1) ) )
        return;

    if(m == n){
        p[n] = 1;
        for(i=1;i<nVal;++i){
            if(p[i])
                printf(" %d", i);
        }
        printf("\n");
        p[n] = 0;
    }


    calFunc(m, n-1);
    p[n] = 1;
    calFunc(m-n, n-1);
    p[n] = 0;
}

int main(int argc, char **argv)
{
//    int n=9, m=10;
//    int *p;
    
    p = malloc(9*sizeof(int));

    memset(p, 0, 9*sizeof(int));

    calFunc(mVal, nVal);

//    free(p);
    
    return 0;
}
