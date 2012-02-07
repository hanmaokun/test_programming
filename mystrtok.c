#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*mystrtok is the same as the function "strtok" in string.h*/
char *mystrtok(register char *s, register const char *delim);
int main(void) {
       char test[] = "abcdefghijkl";
       
       test[0] = '\0';
       printf("%s\n", test);
    
        printf("---mystrtok---\n");
        char myinput[16] = "abcde,fgh";
        char *s;
        s = mystrtok(myinput, "c,h");
        printf("%s\n", s);
        s = mystrtok(NULL, ",h");
        if (s)
                printf("%s\n", s);
        s = mystrtok(NULL, ",");
        if (s)
                printf("%s\n", s);
        printf("%s\n", myinput);

        return EXIT_SUCCESS;
}

char *mystrtok(register char *s, register const char *delim) {
        static char *last;
        char *tok;
        char *ucdelim;

        /*(1)s为空，并且上次剩余值也为空，则直接返回NULL，否则s为last或当前值中有值的一方*/
        /*if (s == NULL && (s = last) == NULL)
                return NULL;*/
        /*(2)以上内容与下面等价：
                 下面意为：如果s==NULL的时候，s则为last（上次执行该项的时候的剩余值）；
                 若这时候s还为空（即上次没有剩余），则返回NULL。
         */

        if (s == NULL)
                s = last;
        if(s == NULL)
                return NULL;

        /*(3)也意为：若后续值为NULL则不进行操作，否则继续操作。
                 其中，后续值的界定方法为: 若last不为空的时候，则s为last，否则为输入值
         * */
        /*
        if(last != NULL)
                s = last;
        else if(s == NULL)
                return NULL;*/

        tok = s;

        int found = 0;
        while (!found && *s != '\0') {
                ucdelim = (char *) delim;
                while (*ucdelim) {
                        if (*s == *ucdelim) {
                                found = 1;
                                *s = '\0';
                                last = s + 1;
                                break;
                        }
                        ucdelim++;
                }
                if (!found) {
                s++;
                }
        }

        return tok;
}
