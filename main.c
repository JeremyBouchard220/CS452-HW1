#include <stdio.h>
#include <stdlib.h>

#include "deq.h"
#include "main.h"
//#include "main.d"

int main()
{
  one();
  two();
  three();
  four();
  five();
  six();
  seven();
  eight();
  nine();
  ten();
  // Deq q=deq_new();

  // char *s=deq_str(q,0);
  // printf("%s\n",s);
  // free(s);

  // deq_del(q,0);
  // return 0;
}

// First Test: Empty->puthead
static void one()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_head_put(q,d);
  if(deq_len(q)==1)
  {
    printf("Pass:1\n");
  }
  else
  {
    printf("Fail:1\n");
  }
  deq_head_get(q);
  deq_del(q,0);
}

// Second Test: Empty->Gethead
static void two()
{
  Deq q=deq_new();
  if(deq_head_get(q)==NULL)
  {
    printf("Pass:2\n");
  }
  else
  {
    printf("Fail:2\n");
  }
  deq_del(q,0);
}

// Third Test: Empty->Remhead
static void three()
{
  Deq q=deq_new();
  if(deq_head_rem(q,0)==NULL)
  {
    printf("Pass:3\n");
  }
  else
  {
    printf("Fail:3\n");
  }
  deq_del(q,0);
}

// Fourth Test: Empty->Gettail
static void four()
{
  Deq q=deq_new();
  if(deq_tail_get(q)==NULL)
  {
    printf("Pass:4\n");
  }
  else
  {
    printf("Fail:4\n");
  }
  deq_del(q,0);
}

// Fifth Test: Empty->Remtail
static void five()
{
  Deq q=deq_new();
  if(deq_head_rem(q,0)==NULL)
  {
    printf("Pass:5\n");
  }
  else
  {
    printf("Fail:5\n");
  }
  deq_del(q,0);
}

// Sixth Test: Empty->Puttail
static void six()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_tail_put(q,d);
  if(deq_len(q)==1)
  {
    printf("Pass:6\n");
  }
  else
  {
    printf("Fail:6\n");
  }
  //deq_tail_get(q);
  deq_del(q,0);
}

// Seventh Test: Put->Put->Gettail
static void seven()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_head_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_head_put(q,d1);

  if(point==deq_tail_get(q))
  {
    printf("Pass:7\n");
  }
  else
  {
    printf("Fail:7\n");
  }
  //deq_head_get(q);
  deq_del(q,0);
}

// Eigth Test: Put->Put->GetHead
static void eight()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_head_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_head_put(q,d1);

  if(point2==deq_head_get(q))
  {
    printf("Pass:8\n");
  }
  else
  {
    printf("Fail:8\n");
  }
  //deq_head_get(q);
  deq_del(q,0);
}

// Ninth Test: Put->Put->Remtail
static void nine()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_head_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_head_put(q,d1);

  deq_tail_rem(q,d);

  if(point2==deq_tail_get(q))
  {
    printf("Pass:9\n");
    
  }
  else
  {
    printf("Fail:9\n");
    
  }
  //deq_head_get(q);
  deq_del(q,0);
}

// Tenth Test: Put->Put->Remhead
static void ten()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_head_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_head_put(q,d1);

  
  Data test = deq_head_rem(q,d1);
  char thing = *(char*)test;
  printf("%c", thing);

  if(point==deq_head_get(q))
  {
    printf("Pass:10\n");
  }
  else
  {
    printf("Fail:10\n");
  }
  deq_head_get(q);
  //deq_del(q,0);
}