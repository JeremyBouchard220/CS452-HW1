#include <stdio.h>
#include <stdlib.h>

#include "deq.h"
#include "main.h"
//#include "main.d"

int main()
{
  test1();
  //test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  //test8();
  test9();
  test10();
  
  // Deq q=deq_new();

  // char *s=deq_str(q,0);
  // printf("%s\n",s);
  // free(s);

  // deq_del(q,0);
  // return 0;
}

/**
 * Test 1: Put data in empty list at head.
 */
static void test1(){
  Deq q=deq_new();
  char value = 'e';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);
  if(1==deq_len(q)){
    printf("Test 1 Pass\n");
  }
  else{
    printf("Test 1 Fail\n");
  }
  deq_head_get(q);
  deq_del(q,0);
  }
/**
 * Test 2: Get data from empty list at head.
 */
static void test2(){
  Deq q=deq_new();
  if(deq_head_get(q)==NULL){
    printf("Test 2 Pass\n");
  }
  else{
    printf("Test 2 Fail\n");
  }
   deq_del(q,0);
  }
/**
   * Test 3: Put three items in then get from tail
   */
static void test3(){
  Deq q=deq_new();
  char value = 'a';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);

  char value1 = 'b';
  char *pointer1 = &value1;
  Data d1 = pointer1;
  deq_head_put(q,d1);

  char value2 = 'c';
  char *pointer2 = &value2;
  Data d2 = pointer2;
  deq_head_put(q,d2);

  if(pointer==deq_tail_get(q)){
    printf("Test 3 Pass\n");
  }
  else{
    printf("Test 3 Fail\n");
  }
  deq_head_get(q);
  deq_head_get(q);
  deq_del(q,0);
  }
/**
* Test 4: Put three items in then get from head
*/
static void test4(){
  Deq q=deq_new();
  char value = 'a';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);

  char value1 = 'b';
  char *pointer1 = &value1;
  Data d1 = pointer1;
  deq_head_put(q,d1);

  char value2 = 'c';
  char *pointer2 = &value2;
  Data d2 = pointer2;
  deq_head_put(q,d2);

  if(pointer2==deq_head_get(q)){
    printf("Test 4 Pass\n");
  }
  else{
    printf("Test 4 Fail\n");
  }
  deq_head_get(q);
  deq_head_get(q);
  deq_del(q,0);
  }
/**
* Test 5: Put three items at tail then get from head
*/
static void test5(){
  Deq q=deq_new();
  char value = 'a';
  char *pointer = &value;
  Data d = pointer;
  deq_tail_put(q,d);

  char value1 = 'b';
  char *pointer1 = &value1;
  Data d1 = pointer1;
  deq_tail_put(q,d1);

  char value2 = 'c';
  char *pointer2 = &value2;
  Data d2 = pointer2;
  deq_tail_put(q,d2);

  if(pointer==deq_head_get(q)){
    printf("Test 5 Pass\n");
  }
  else{
    printf("Test 5 Fail\n");
  }
  deq_head_get(q);
  deq_head_get(q);
  deq_del(q,0);
  }
/**
 * Test 6: Put data in empty list at tail.
 */
static void test6(){
  Deq q=deq_new();
  char value = 'e';
  char *pointer = &value;
  Data d = pointer;
  deq_tail_put(q,d);
  if(1==deq_len(q)){
    printf("Test 6 Pass\n");
  }
  else{
    printf("Test 6 Fail\n");
  }
  deq_head_get(q);
  deq_del(q,0);
  }
/**
 * Test 7: Put data in empty list at head, remove it, then put at head.
 */
static void test7(){
  Deq q=deq_new();
  char value = 'e';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);
  deq_head_get(q);
  char value1 = 'f';
  char *pointer1 = &value1;
  Data f = pointer1;
  deq_head_put(q,f);
  if(deq_len(q)==1 && deq_head_get(q)==pointer1){
    printf("Test 7 Pass\n");
  }
  else{
    printf("Test 7 Fail\n");
  }
  deq_del(q,0);
  }
/**
 * Test 8: Get index 0 (head) from empty list
 */
static void test8(){
  Deq q=deq_new();
  if(deq_head_ith(q,0)==NULL){
    printf("Test 8 Pass\n");
  }
  else{
    printf("Test 8 Fail\n");
  }
  deq_del(q,0);
}
/**
* Test 9: Put three items in then get from index 1 (head).
*/
static void test9(){
  Deq q=deq_new();
  char value = 'a';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);

  char value1 = 'b';
  char *pointer1 = &value1;
  Data d1 = pointer1;
  deq_head_put(q,d1);

  char value2 = 'c';
  char *pointer2 = &value2;
  Data d2 = pointer2;
  deq_head_put(q,d2);

  if(pointer1==deq_head_ith(q,1)){
    printf("Test 9 Pass\n");
  }
  else{
    printf("Test 9 Fail\n");
  }
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_del(q,0);
  }
/**
* Test 10: Put three items in then get from index 1 (tail).
*/
static void test10(){
  Deq q=deq_new();
  char value = 'a';
  char *pointer = &value;
  Data d = pointer;
  deq_head_put(q,d);

  char value1 = 'b';
  char *pointer1 = &value1;
  Data d1 = pointer1;
  deq_head_put(q,d1);

  char value2 = 'c';
  char *pointer2 = &value2;
  Data d2 = pointer2;
  deq_head_put(q,d2);

  if(pointer1==deq_tail_ith(q,1)){
    printf("Test 10 Pass\n");
  }
  else{
    printf("Test 10 Fail\n");
  }
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_del(q,0);
}