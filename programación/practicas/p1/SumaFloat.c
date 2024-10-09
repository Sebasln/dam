#include <stdio.h>
#include <stdlib.h>

int main() {
	float numero1;
	float numero2;
	float resultado_suma;
	float resultado_resta;
	float resultado_division;
	float resultado_multiplicacion;
	
	printf("Escribe un float: ");
	scanf("%f", &numero1);
	printf("Escribe otro float: ");
	scanf("%f", &numero2);
	
	resultado_suma = numero1 + numero2;
	resultado_resta = numero1 - numero2;
	resultado_multiplicacion = numero1 * numero2;
	resultado_division = numero1 / numero2;
	
	printf("Suma: %f\n", resultado_suma);
	printf("Resta: %f\n", resultado_resta);
	printf("Multiplicación: %f\n", resultado_multiplicacion);
	printf("División: %f\n", resultado_division);

	return 0;

}
