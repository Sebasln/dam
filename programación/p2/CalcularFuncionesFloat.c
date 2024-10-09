#include <stdio.h>
#include <stdlib.h>


int main() {

	float numero1;
	float numero2;
	
	printf("Escribe un float: ");
	scanf("%f", &numero1);

	printf("Escribe otro float: ");
	scanf("%f", &numero2);
	

int calcular_suma(float numero1, float numero2) {
	float resultado_suma;
	resultado_suma = numero1 + numero2;
	printf("Suma: %f\n", resultado_suma);
}

int calcular_resta(float numero1, float numero2) {
	float resultado_resta;
	resultado_resta = numero1 + numero2;
	printf("Resta: %f\n", resultado_resta);
}
	calcular_suma(numero1, numero2);
	calcular_resta(numero1, numero2);

	return 0;
}
