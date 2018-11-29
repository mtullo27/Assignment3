#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc != 5){
    printf("Usage %s <filename> <unit> <operation> <unit>\n", argv[0]);
    exit(-1);
  }
  unsigned char raw_bytes[300];
  typedef int (*Calc_fptr)(char, int, int);
  FILE *fp;
  int int1 = atoi(argv[2]);
  int int2 = atoi(argv[4]);
  char sym = *argv[3];
  Calc_fptr calculator;
  fp = fopen(argv[1], "rb");
  fread(raw_bytes, 1, 92, fp);
  calculator = (Calc_fptr)raw_bytes;
  int val = calculator(sym, int1, int2);
  printf("%i %c %i = %i", int1, sym, int2, val);
  return 0;
}
