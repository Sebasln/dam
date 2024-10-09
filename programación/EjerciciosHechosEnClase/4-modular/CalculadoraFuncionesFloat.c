#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcular_suma(float numero1, float numero2) {
	float resultado_suma;
	resultado_suma = numero1 + numero2;
	printf("Suma: %f\n", resultado_suma);
	return 0;
}

int calcular_resta(float numero1, float numero2) {
	float resultado_resta;
	resultado_resta = numero1 + numero2;
	printf("Resta: %f\n", resultado_resta);
	return 0;
}

int calcular_multiplicacion(float numero1, float numero2) {
	float resultado_multiplicacion;
	resultado_multiplicacion = numero1 * numero2;
	printf("Multiplicación: %f\n", resultado_multiplicacion);
	return 0;
}

int calcular_division(float numero1, float numero2) {
	float resultado_division;
	resultado_division = numero1 / numero2;
	printf("División: %f\n", resultado_division);
	return 0;

}

int main() {
	float numero1;
	float numero2;

	printf("Escribe un float: ");
	scanf("%f", &numero1);
	
	printf("Escribe otro float: ");
	scanf("%f", &numero2);
	
	calcular_suma(numero1, numero2);
	calcular_resta(numero1, numero2);
	calcular_multiplicacion(numero1, numero2);
	calcular_division(numero1, numero2);

	return 0;
}
