#include <stdio.h>
#include <stdlib.h>

int g = 10;

typedef struct {
  unsigned char *address;
  unsigned int size;
  unsigned char data;
  unsigned char *next;
}var_state;
var_state *head;

void save_state(void *addr, unsigned int size1){
  var_state element = (unsigned char)addr, size1, (unsinged char)*addr, head);
head = element;
}
