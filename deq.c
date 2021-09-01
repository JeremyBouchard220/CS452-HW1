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
 * @param r The list appending to
 * @param e The head or tail 
 * @param i The desired index
 * @return data
 * 
 */
static Data ith(Rep r, End e, int i) 
{ 
  if(e==Tail)
  {
    Node req=r->ht[Tail];
    for(int k=0; k!=i; k++)
    {
      req=req->np[Tail];
    }
    return req->data;
  }
  if(e==Head)
  {
    Node req=r->ht[Head];
    for(int k=0; k!=i; k++)
    {
      req=req->np[Head];
    }
    return req->data;
  }
  if(i<0 || i+1 > r->len)
  {
    printf("The desired index is not in the list.\n");
    return NULL;
  }
  return 0; 
}

static Data get(Rep r, End e) 
{


  return 0;
}

static Data rem(Rep r, End e, Data d) 
{
  

  return 0;  
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
