#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j, a[101];
    for(i=0;i<101;i++)
        a[i] = 1;

    for(i=2;i<101;i++) {
        if(a[i]!=0) {
            for(j=i+i;j<101;){
                if(j%i == 0)
                    a[j] = 0;j+=i;
            }
        }
    }

    for(i=2;i<101;i++) {
        if(a[i] != 0)
            printf(" %d", i);
    }

    printf("\n");

    return 0;
}
