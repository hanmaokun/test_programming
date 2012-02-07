#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void maopao(int *p, int num)
{
  int i, j, temp;
  
  for(i=0;i<num;i++) {
    for(j=0;j<num-i;j++) {
      if(p[j]>p[j+1]) {
    temp = p[j+1]; p[j+1] = p[j]; p[j] = temp;
      }
    }
  }
}

int partition(int *p, int i, int j)
{
  int pivot;
  
  pivot = p[i];
  while(i<j) {
    while( (i<j) && (p[j]>=pivot) ) {
      j--;
    }
    if(i<j)
      p[i++] = p[j];
    
    while( (i<j) && (p[i]<=pivot) ) {
      i++;
    }
    if(i<j)
      p[j--] = p[i];
  }
  
  p[i] = pivot;
  return i;
}

void quicksort(int *p, int low, int high) 
{
  int pos;
  if(low < high) {
    pos = partition(p, low, high);
    quicksort(p, low, pos-1);
    quicksort(p, pos+1, high);
  }
}

void shellsort(int *p, int ctr)
{
  int i, temp, d = 7;
  while(d>1) {
    d = (d+1)/2;
    for(i=0;i<ctr-d;i++) {
      if(p[i]>p[i+d]) {
    temp = p[i];
    p[i] = p[i+1];
    p[i+1] = temp;
      }
    }
  }
  
  for(i=0;i<7;i++)
    printf(" %d", p[i]);

  printf("\n");
  
}

int main(int argc, char **argv)
{
  int i;
  int a[7] = {49, 38, 65, 97, 76, 13, 27};
  
  //shellsort(a, 7);
  //maopao(a, 6);
  //quicksort(a, 0, 6);
  for(i=0;i<7;i++)
    printf(" %d", a[i]);
  
  printf("\n");
  
  shellsort(a, 7);
  
  printf("\n");
  
  return 0;
}
