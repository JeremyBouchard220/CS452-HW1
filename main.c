#include <stdio.h>
#include <stdlib.h>

#include "deq.h"
#include "main.h"

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
  eleven();
  twelve();
  thirteen();
  fourteen();
  fifteen();
  sixteen();
  seventeen();
  eighteen();
  nineteen();
  twenty();
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

  char *rem = deq_tail_rem(q,d);

  if(point==rem)
  {
    printf("Pass:9\n");
    
  }
  else
  {
    printf("Fail:9\n");
    
  }
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

  char *rem = deq_head_rem(q,d);

  if(point==rem)
  {
    printf("Pass:10\n");
  }
  else
  {
    printf("Fail:10\n");
  }
  deq_del(q,0);
}

// Eleventh Test: Put->Put->Put->Put->RemSecond
static void eleven()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  char *rem = deq_head_rem(q,d2);

  if(point3==rem)
  {
    printf("Pass:11\n");
  }
  else
  {
    printf("Fail:11\n");
  }
  deq_del(q,0);
}

// Twelfth Test: Put->Put->Put->Put->RemThird
static void twelve()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);
  
  char *rem = deq_head_rem(q,d1);

  if(point2==rem)
  {
    printf("Pass:12\n");
  }
  else
  {
    printf("Fail:12\n");
  }
  deq_del(q,0);
}

// Thirteenth Test: Put->Put->Put->Put->GetTail
static void thirteen()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(point4==deq_head_get(q))
  {
    printf("Pass:13\n");
  }
  else
  {
    printf("Fail:13\n");
  }
  deq_del(q,0);
}

// Fourteenth Test: Put->Put->Put->Put->GetHead
static void fourteen()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(point==deq_tail_get(q))
  {
    printf("Pass:14\n");
  }
  else
  {
    printf("Fail:14\n");
  }
  deq_del(q,0);
}

// Fifteenth Test: Put->Put->Put->Put->PutTail
static void fifteen()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_tail_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_tail_put(q,d1);

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_tail_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_tail_put(q,d3);

  if(deq_len(q)==4)
  {
    printf("Pass:15\n");
  }
  else
  {
    printf("Fail:15\n");
  }
  deq_del(q,0);
}

// Sixteenth Test: Put->Put->Put->Put->PutTail->remTail
static void sixteen()
{
  Deq q=deq_new();
  char letter1 = 'z';
  char *point = &letter1;
  Data d = point;
  deq_tail_put(q,d);

  char letter2 = 'y';
  char *point2 = &letter2;
  Data d1 = point2;
  deq_tail_put(q,d1);

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_tail_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_tail_put(q,d3);

  deq_tail_rem(q,d);
  
  if(deq_len(q)==3)
  {
    printf("Pass:16\n");
  }
  else
  {
    printf("Fail:16\n");
  }
  deq_del(q,0);
}

// Seventeenth Test: Put->Put->Put->Put->ithHead
static void seventeen()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(deq_head_ith(q,0)==point4)
  {
    printf("Pass:17\n");
  }
  else
  {
    printf("Fail:17\n");
  }
  deq_del(q,0);
}

// Eighteenth Test: Put->Put->Put->Put->ithTail
static void eighteen()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(deq_head_ith(q,3)==point)
  {
    printf("Pass:18\n");
  }
  else
  {
    printf("Fail:18\n");
  }
  deq_del(q,0);
}

// Nineteenth Test: Put->Put->Put->Put->ithSecond
static void nineteen()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(deq_head_ith(q,1)==point3)
  {
    printf("Pass:19\n");
  }
  else
  {
    printf("Fail:19\n");
  }
  deq_del(q,0);
}

// Twentieth Test: Put->Put->Put->Put->ithThird
static void twenty()
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

  char letter3 = 'x';
  char *point3 = &letter3;
  Data d2 = point3;
  deq_head_put(q,d2);

  char letter4 = 'w';
  char *point4 = &letter4;
  Data d3 = point4;
  deq_head_put(q,d3);

  if(deq_head_ith(q,2)==point2)
  {
    printf("Pass:20\n");
  }
  else
  {
    printf("Fail:20\n");
  }
  deq_del(q,0);
}