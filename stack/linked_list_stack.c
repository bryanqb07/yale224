#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
  struct node *next;
  int value;
};

typedef struct node Node;

typedef struct node *Stack;

#define STACK_EMPTY (0)

void StackPush(Stack *s, int value)
{
  Node *e;
  e = malloc(sizeof(Node));
  assert(e);

  e->value = value;
  e->next = *s;
  *s = e;
}

int StackEmpty(const Stack *s)
{
  return(*s == 0);
}

int StackPop(Stack *s)
{
  assert(!StackEmpty(s));
  
  int returnVal = (*s)->value;
  Node *e = *s;
  *s = e->next;

  free(e);

  return returnVal;
}

void
StackPrint(Stack *s){
  Node *e = *s;

  while(e != 0){
    printf("%d ", e->value);
    e = e->next;
  }
  putchar('\n');
}

void StackReversePrint(Stack *s)
{
  Node *e = (*s)->next;

  if(e != 0) StackReversePrint(&e);
 
  printf("%d ", (*s)->value);

}

int main(int argc, char**argv)
{
  Stack s = STACK_EMPTY;

  for(int i = 0; i < 5; i++){
    printf("Push %d\n", i);
    StackPush(&s, i);
    printf("Printing stack...\n");
    StackPrint(&s);
    printf("Reverse print...\n");
    StackReversePrint(&s);
    putchar('\n');
  }
  
  while(!StackEmpty(&s)){
    printf("pop gets %d\n", StackPop(&s));
    StackPrint(&s);
  }

  return 0;
}
