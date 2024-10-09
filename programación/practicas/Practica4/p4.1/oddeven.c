#include <stdio.h>
#include <stdlib.h>

int main() {
	int numero;

	printf("Introduce un número entero:\n");

	scanf("%i", &numero);

	if(numero % 2 == 0){
		printf("Es par.\n");	
	} else {
		printf("Es impar.\n");
	
	}
	return 0;
}
