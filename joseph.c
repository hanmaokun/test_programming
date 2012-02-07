#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct student {
    int         data;
    struct student    *next;
}node;

node *head;
int length;

int listLength(node *head) 
{
    int length = 0;
    node *p;

    p = head;
    while(p!=NULL) {
        p = p->next;
        length++;
    }
    
    return length;
}

void listPrint(node *head)
{
    node *p;

    p = head;
    while(p!=NULL){
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

node *listCreate() 
{
    node    *p, *s, *head;
    int    cycle = 1, i;
    char    x = 0;

    head = (node*)malloc(sizeof(node));
    p = head;

    for(i=0;i<17;i++) {
        s = (node*)malloc(sizeof(node));
        s->data = i+1;
        printf(" s->data: %d ||", s->data);
        p->next = s;
        p = s;
        x = 0;    
    }    
    //p->data = 0;
    head = head->next;
    p->next = head;
    printf("created list! head point to %d\n", head->data);
    return(head);

}

node *listDelete(node *head, int num)
{
  node *p1, *p2;
  
  p1 = head;
  printf("deleting list member...");
  while(num!=p1->data && p1->next!=NULL) {
    p2 = p1; p1 = p1->next;
  }
  
  printf("\n");
  if(num == p1->data) {
    if(p1 == head) {
      head = p1->next; 
      free(p1);
    }
    
    else {
      p2->next = p1->next;
    }
  }
  
  printf("after delete: \n");
  p1 = head;
  while(p1!=NULL) {
    printf(" %d", p1->data);
    p1 = p1->next;
  }
  printf("\n");
  
  return head;
}

node *listInsert(node *head, int num)
{
  node *p0, *p1, *p2;
  
  p0 = (node*)malloc(sizeof(node));
  p0->data = num;
  p1 = head;
  while ( (p0->data > p1->data) && (p1->next != NULL) ) {
    p2 = p1;
    p1 = p1->next;
  }
  
  if(p0->data <= p1->data) {
    if(p1 == head) {
      p0->next = p1;
      head = p0;
    }
    
    else {
      p2->next = p0;
      p0->next = p1;
    }
  }
  else {
    p1->next = p0;
    p0->next = NULL;
  }
  
  p1 = head;
  while(p1!=NULL) {
    printf(" %d ", p1->data);
    p1 = p1->next;
  }
}

node *listReverse(node *head)
{
  node *p1, *p2, *p3;
  
  if( (NULL == head) || (NULL == head->next) )
    return;
  
  p1 = head;
  p2 = head->next;
  while(p2) {
    p3 = p2->next;
    p2->next = p1;
    p1 = p2;
    p2 = p3;
  }
  
  head->next = NULL;
  head = p1;
  
  while(p1) {
    printf(" %d", p1->data);
    p1 = p1->next;
  }
  printf("\n");
  
  return head;
}

node *listMerge(node *head1, node *head2)
{
  node *p1, *p2;
  if(head1 == NULL)
    return head2;
  
  if(head2 == NULL)
    return head1;
  
  if(head1->data < head2->data) {
    head = head1;
    p1 = head1->next;
    p2 = head2;
  }
  else {
    head = head2;
    p1 = head2->next;
    p2 = head1;
  }
  
  node *pcurrent = head;
  
  while(p1!=NULL && p2!=NULL) {
    if(p1->data < p2->data) {
      pcurrent->next = p1;
      pcurrent = p1;
      p1 = p1->next;
    }
    else {
      pcurrent->next = p2;
      pcurrent = p2;
      p2 = p2->next;
    }
    
  }
  
}

node *listMergeRecursive(node *head1, node *head2)
{
  node *head;
  if(NULL == head1)
    return head2;
  
  if(NULL == head1)
    return head1;
  
  if(head1->data < head2->data) {
    head = head1;
    head->next = listMergeRecursive(head1->next, head2);
  }
  else {
    head = head2;
    head->next = listMergeRecursive(head1, head2->next);
  }
  return head;
}

node *convert_array_to_list_with_increasing_order(int *array, int ncount) 
{
  int    i;
  node    *head, *s, *p;
  if(!ncount)
    return NULL;
  
  head = (node*)malloc(sizeof(node));
  p = head;
  for(i=0;i<ncount;i++) {
    s = (node*)malloc(sizeof(node));
    s->data = array[ncount];
    p->next = s;
    p = s;
  }
  head = head->next;
  p->next = NULL;
  //
  return head;
  //head = quicksort(head, 0, ncount);
}

node *listMN(node *head, int m, int n)
{
  int     i, j, k;
  node     *p1, *p2;
  
  p1 = head;
  
  while(p1->next->next != p1) {
    for(i=0;i<2;i++) {
      p2 = p1;
      p1 = p1->next;
    }
    p2->next = p1->next;
    p1 = p2->next;
  }
  
  printf("%d\n", p1->data);
}

int main(int argc, char **argv)
{
    int c;
    node *l;

    while( (c = getchar()) != 'q' ) {
        if(c) {
            //printf(" %c", c);
            switch(c) {
                case 'c':
                    head = listCreate();
                    break;
                case 'l':
                    length = listLength(head);
                    printf("listLength returns: %d\n", length);
                    break;
                case 'p':
                    listPrint(head);
                    break;
                case 'd':
                    head = listDelete(head, 50);
                    break;
                case 'i':
                  head = listInsert(head, 51);
                  break;
                case 'r':
                  head = listReverse(head);
                  break;
                case 'j':
                  head = listMN(head, 3, 17);
                  break;
                default:break;
            }
        }
    }
    
    return 0;
}
