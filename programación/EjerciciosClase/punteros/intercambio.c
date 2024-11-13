#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *int1, int *int2){
	int aux = *int1;
	*int1 = *int2;
	*int2 = aux;
}

int main(){
	int n1 = 10;
	int n2 = 5;

	intercambiar(&n1, &n2);

	printf("El valor de n1 es: %d\n", n1);
	printf("El valor de n2 es: %d\n", n2);

	return 0;
}
