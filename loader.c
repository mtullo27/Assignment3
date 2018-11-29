#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	unsigned char raw_bytes[300];
	typedef int (*Calc_fptr)(char, int, int);
	FILE *fp;
	unsigned int i;
	int int1 = atoi(argv[1]);
	int int2 = atoi(argv[3]);
	char sym = *argv[2];
	Calc_fptr calculator;
	if(argc != 4){
		printf("Ussage %s <filename> <unit> <operation> <unit>\n", argv[0]);
		exit(-1);
	}
	fp = fopen(argv[0], "rb");
	fread(raw_bytes, sizeof(unsigned char), 92, fp);
	calculator = (Calc_fptr)raw_bytes;
	int val = calculator(sym, int1, int2);
	printf("%i %c %i = %i", int1, argv[2], int2, val);
	return 0;
}
