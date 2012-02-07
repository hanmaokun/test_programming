#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct student {
  int     data;
  struct student *next;
  struct student *pre;
}dnode;

dnode *dlistCreate()
{
  int     x=0, cycle = 1;
  dnode *head, *s, *p;
  
  head = (dnode*)malloc(sizeof(dnode));
  p = head;
  while(cycle) {
    printf("please input data: ");
    
    while(!x) {
      x = getchar();
    }
    
    if(10 == x){
    }
    else if(x!='q'){
      s = (dnode*)malloc(sizeof(dnode));
      s->data = x;
      printf(" %d\n", s->data);
      p->next = s;
      s->pre = p;
      p = s;
    }
    else if('q' == x) {
      cycle = 0;
    }
    x = 0;
  }
  head = head->next;
  head->pre = NULL;
  s->next = NULL;
  
  p = head;
  while(p) {
    printf(" %d", p->data);
    p=p->next;
  }
  
  printf("\n");
  
  return (head);
}

dnode *dlistDelete(dnode *head, int num)
{
  dnode *p1, *p2;
  p1 = head;
  
  while(num!=p1->data && p1->next!=NULL) {
    p1 = p1->next;
  }
  
  if(num == p1->data) {
    if(p1 == head) {
      head = p1->next;
      head->pre = NULL;
      free(p1);
    }
    else if(p1->next == NULL){
      p1->pre->next=NULL;
      free(p1);
    }
    else {
      p1->next->pre = p1->pre;
      p1->pre->next = p1->next;
    }
  }

  p1 = head;
  while(p1) {
    printf(" %d", p1->data);
    p1=p1->next;
  }
  
  printf("\n");
  
  return head;
}

dnode *dlistInsert(dnode *head, int num)
{
  dnode *p0, *p1;
  
  p0 = (dnode*)malloc(sizeof(dnode));
  p0->data = num;
  
  p1 = head;
  while(p0->data>p1->data && p1->next!=NULL) {
    p1 = p1->next;
  }
  
  if(p1->data >= p0->data) {
    if(p1 == head) {
      head = p0;
      head->next = p1;
      p1->pre = head;
      //head->pre = NULL;
    }
    else {
      p1->pre->next = p0;
      p0->next = p1;
      p0->pre = p1->pre;
      p1->pre = p0;
    }
  }
  else {
    p1->next = p0;
    p0->pre = p1;
    p0->next = NULL;
  }
  
  p1 = head;
  while(p1) {
    printf(" %d", p1->data);
    p1=p1->next;
  }
  
  printf("\n");
  
  return(head);
}

dnode *dlistReverse(dnode *head)
{
  dnode *p1, *p2, *p3;
  
  p1 = head;
  p2 = p1->next;
  p1->next = NULL;
  while(p2) {
    p1->pre = p2;
    p3 = p2->next;
    p2->next = p1;
    p1 = p2;
    p2 = p3;
  }
  
  head = p1;
  head->pre = NULL;
  
  p1 = head;
  while(p1) {
    printf(" %d", p1->data);
    p1=p1->next;
  }
  
  printf("\n");
  
  return(head);
}

int main(int argc, char **argv)
{
  dnode *head;
  
  head = dlistCreate();
  
  //head = dlistDelete(head, 50);
  
  //head = dlistInsert(head, 51);
  
  head = dlistReverse(head);
  head = dlistReverse(head);
  head = dlistReverse(head);
  
  return 0;
}
