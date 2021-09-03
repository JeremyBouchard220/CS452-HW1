#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deq.h"
#include "error.h"

// indices and size of array of node pointers
typedef enum {Head,Tail,Ends} End;

typedef struct Node {
  struct Node *np[Ends];		// next/prev neighbors
  Data data;
} *Node;

typedef struct {
  Node ht[Ends];			// head/tail nodes
  int len;
} *Rep;

static Rep rep(Deq q) {
  if (!q) ERROR("zero pointer");
  return (Rep)q;
}

/**
 * Using this method, you can append an item to the beginning or end of a list at the head or tail position.
 * @param r The list appending to
 * @param e The head or tail enum
 * @param d The data being added
 * @return void
 * 
 */
static void put(Rep r, End e, Data d) 
{
  //This section adds at the tail
  if(e==Tail)
  {
    Node start = malloc(sizeof(*start));
    start->data=d;
    if(r->len==0)
    {
      r->ht[Tail]=start;
      r->ht[Head]=start;
    }
    else
    {
      r->ht[Tail]->np[Head]=start;
      start->np[Tail]=r->ht[Tail];
      r->ht[Tail]=start;
    }
    r->len=r->len+1;
  }
  //This section adds at the head
  if(e==Head)
  {
    Node start = malloc(sizeof(*start));
    start->data=d;
    if(r->len==0)
    {
      r->ht[Head]=start;
      r->ht[Tail]=start;
    }
    else
    {
      start->np[Head]=r->ht[Head];
      r->ht[Head]->np[Tail]=start;
      r->ht[Head]=start;
    }
    r->len=r->len+1;
  }
}

/**
 * This method returns the data from a desired index while leaving the list unchanged.
 * @param r The list being parsed
 * @param e The head or tail enum
 * @param i The desired index
 * @return data
 * 
 */
static Data ith(Rep r, End e, int i) 
{ 
  //this section covers starting at the tail
  if(e==Tail)
  {
    Node req=r->ht[Tail];
    for(int k=0; k!=i; k++)
    {
      req=req->np[Tail];
    }
    return req->data;
  }
  //this section covers starting at the head
  if(e==Head)
  {
    Node req=r->ht[Head];
    for(int k=0; k!=i; k++)
    {
      req=req->np[Head];
    }
    return req->data;
  }
  //covers out of bounds index
  if(i<0 || i+1 > r->len)
  {
    printf("The desired index is not in the list.\n");
    return NULL;
  }
  return 0; 
}

/**
 * This method removes a node from the beginning or end of the desired list.
 * @param r The list appending from
 * @param e The head or tail enum
 * @return data
 * 
 */
static Data get(Rep r, End e) 
{
  //this section pops the tail
  if(e==Tail)
  {
    if(r->len > 0)
    {
      Data d=r->ht[Tail]->data;
      if(r->ht[Tail]->np[Tail] != NULL)
      {
        r->ht[Tail]->np[Tail]->np[Head] = NULL;
      }
      //Node back=r->ht[Tail]->np[Tail];
      free(r->ht[Tail]);
      //r->ht[Tail];
      r->len=r->len+1;
      return d;
    }
  }
  //this section pops the head
  if(e==Head)
  {
    if(r->len > 0)
    {
      Data d=r->ht[Head]->data;
      if(r->ht[Head]->np[Head] != NULL)
      {
        r->ht[Head]->np[Head]->np[Tail] = NULL;
      }
      Node ahead = r->ht[Head]->np[Head];
      free(r->ht[Head]);
      r->ht[Head]=ahead;
      r->len=r->len+1;
      return d;
    }
  }
  //case for empty list
  if(r->len==0)
  {
    printf("Unable to remove from empty list.\n");
    return NULL;
  }
  return 0;
}

/**
 * This method removes specified data if it is found in the desired list.
 * @param r The desired list
 * @param e The head or tail enum
 * @param d The specified data to be found
 * @return data
 * 
 */
static Data rem(Rep r, End e, Data d) 
{
  //Takes care of Tail
  if(e==Tail)
  {
    Node pos=r->ht[Tail];
    while(pos != NULL)
    {
      //This section covers if the data is equal
      if(pos->data == d)
      {
        if(pos==r->ht[Head])
        {
          return get(r,Head);
        }
        if(pos==r->ht[Tail])
        {
          return get(r,Tail);
        }
        Data rem_data=pos->data;
        pos->np[Tail]->np[Head]=pos->np[Head];
        pos->np[Head]->np[Tail]=pos->np[Tail];
        free(pos);
        r->len=r->len-1;
        return rem_data;
      }
      //this section covers if data isn't equal
      else
      {
        if(pos==r->ht[Head])
        {
          break;
        }
        else
        {
          pos=pos->np[Tail];
        }
      }
    }
  }
  //Takes care of Head
  if(e==Head)
  {
    Node pos=r->ht[Head];
    while(pos != NULL)
    {
      if(pos->data == d)
      {
        if(pos==r->ht[Head])
        {
          return get(r,Head);
        }
        if(pos==r->ht[Tail])
        {
          return get(r,Tail);
        }
        Data rem_data = pos->data;
        pos->np[Tail]->np[Head]=pos->np[Head];
        pos->np[Head]->np[Tail]=pos->np[Tail];
        free(pos);
        r->len=r->len-1;
        return rem_data;
      }
      else
      {
        if(pos==r->ht[Tail])
        {
          break;
        }
        else
        {
          pos=pos->np[Head];
        }
      }
    }
  }
  //Takes care of empty list
  if(r->len==0)
  {
    printf("Data cannot be removed due to desired list being empty.\n");
    return NULL;
  }
  //this section only returns in the break is activated.
  printf("Data was not found in desired list.\n");
  return NULL;  
}

extern Deq deq_new() {
  Rep r=(Rep)malloc(sizeof(*r));
  if (!r) ERROR("malloc() failed");
  r->ht[Head]=0;
  r->ht[Tail]=0;
  r->len=0;
  return r;
}

extern int deq_len(Deq q) { return rep(q)->len; }

extern void deq_head_put(Deq q, Data d) {        put(rep(q),Head,d); }
extern Data deq_head_get(Deq q)         { return get(rep(q),Head); }
extern Data deq_head_ith(Deq q, int i)  { return ith(rep(q),Head,i); }
extern Data deq_head_rem(Deq q, Data d) { return rem(rep(q),Head,d); }

extern void deq_tail_put(Deq q, Data d) {        put(rep(q),Tail,d); }
extern Data deq_tail_get(Deq q)         { return get(rep(q),Tail); }
extern Data deq_tail_ith(Deq q, int i)  { return ith(rep(q),Tail,i); }
extern Data deq_tail_rem(Deq q, Data d) { return rem(rep(q),Tail,d); }

extern void deq_map(Deq q, DeqMapF f) {
  for (Node n=rep(q)->ht[Head]; n; n=n->np[Tail])
    f(n->data);
}

extern void deq_del(Deq q, DeqMapF f) {
  if (f) deq_map(q,f);
  Node curr=rep(q)->ht[Head];
  while (curr) {
    Node next=curr->np[Tail];
    free(curr);
    curr=next;
  }
  free(q);
}

extern Str deq_str(Deq q, DeqStrF f) {
  char *s=strdup("");
  for (Node n=rep(q)->ht[Head]; n; n=n->np[Tail]) {
    char *d=f ? f(n->data) : n->data;
    char *t; asprintf(&t,"%s%s%s",s,(*s ? " " : ""),d);
    free(s); s=t;
    if (f) free(d);
  }
  return s;
}
