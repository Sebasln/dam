#include <stdio.h>
#include <stdlib.h>

int main() {

	int numero1;
		printf("Escribe un número: ");
		scanf("%d", &numero1);
	int numero2;
		printf("Escribe otro número: ");
		scanf("%d", &numero2);
	
	int resultadoSuma;
	int resultadoResta;

	resultadoSuma = numero1 + numero2;
	resultadoResta = numero1 - numero2;
	
	int resultadoMultiplicacion;
        int resultadoDivision;

        resultadoMultiplicacion = numero1 * numero2;
        resultadoDivision = numero1 / numero2;

	printf("Suma: %d\n", resultadoSuma);
	printf("Resta: %d\n", resultadoResta);
	printf("Multiplicación: %d\n", resultadoMultiplicacion);
	printf("División: %d\n", resultadoDivision);

	return 0;
}
