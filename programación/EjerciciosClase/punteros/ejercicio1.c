#include <stdio.h>
#include <stdlib.h>

int main(){
	float num = 12;
	float *p;

	p = &num;

	printf("Valor de num: %f\n", num);
	printf("Dirección de num: %p\n", p);
	printf("Valor al que apunta p: %0.1f\n", *p);
	
	return 0;
}
