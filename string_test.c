#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

void itoa(int num, char *string)
{
  int i = 0;
  while(num) {
    string[i] = num%10 + '0';
    num = num/10;
    i++;
  }
  string[i] = 0;
  printf("string = %s\n", string);
}

char *mystrtok(char *s, char *delim)
{
  static char *last;
  char    *tok;
  char    *ucdelim;
  int     found = 0;
  
  
  if(NULL == s)
    s = last;
  
  if(NULL == s)
    return NULL;
  
  tok = s;
  
  while(!found && *s!=NULL) {
    ucdelim = delim;
    while(*ucdelim) {
      if(*ucdelim == *s) {
    *s = '\0';
    found = 1;
    last = s+1;
    break;
      }
      ucdelim++;
    }
    s++;
  }
  
  return tok;
}

char *strCopy(char *destString, const char *srcString)
{
  char *dest;
  
  dest = destString;
  assert(destString!=NULL && srcString!=NULL);
  
  while( (*destString++ = *srcString++) != '\0' )
  {}
  return dest;
}

int main(int argc, char **argv)
{
  int num = 56789;
  char    string[6];
  char    *sString = "how are you?";
  char  *dString;
  char    inorder[] = "i am from shadong.", tempchar;
  int     ctr, begin, end;
  char  *stringTemplate = "adaskdaskdaskg";
  char  *stringSub = "ask";
  char  *p1, *p2, result[10], *rst;
  int     i=0, j=0, temp;
  
  
  
  ctr = strlen(inorder) - 1;
  while(ctr>i) {
    tempchar = inorder[ctr];
    inorder[ctr] = inorder[i];
    inorder[i]     = tempchar;
    i++; ctr--;
  }
  printf("%s\n", inorder);
  i = 0;
  while(inorder[i]) {
    if(inorder[i]!=' '){
      begin = i;
      while(inorder[i] && inorder[i]!=' ') {
    i++;
      }
      i-=1;
      end = i;
    }
    
    while(end>begin) {
      tempchar = inorder[end];
      inorder[end] = inorder[begin];
      inorder[begin]     = tempchar;
      begin++; end--;
    }
    i+=2;
  }
  printf("%s\n", inorder);
  
  
  p1 = stringSub; p2 = stringTemplate;
  
  for(i=0;stringTemplate[i]!='\0';i++) {
    j = 0;
    temp = i;
    if(stringTemplate[i] == stringSub[j]) {
      while(stringTemplate[i++] == stringSub[j++]) {
    if(stringSub[j] == '\0')
      rst = &stringTemplate[i-j];
      printf("%s\n", rst);
      break;
      }
      i = temp;
    }
  }
  printf("%s\n", rst);
  printf("%s\n", stringTemplate);
  /*
  while(*p2) {
    while(*p1) {
      if(*p1 == *p2)
    break;
      
      p1++;
    }
      if(*p1 == '\0') {
    result[i] = *p2;
    i++;
      }
    
    p2++;
    p1 = stringSub;
  }
  result[i] = 0;
  printf("%s\n", result);
  
  */
  dString = (char*)malloc(strlen(sString));
  strCopy(dString, sString);
  printf("after copy: %s\n", dString);
  //itoa(num, string);
  
  return 0;
}
