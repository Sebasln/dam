#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcular_suma(float numero1, float numero2) {
	float resultado_suma;
	resultado_suma = numero1 + numero2;
	printf("Suma: %f\n", resultado_suma);
}

int calcular_resta(float numero1, float numero2) {
	float resultado_resta;
	resultado_resta = numero1 - numero2;
	printf("Resta: %f\n", resultado_resta);
}

int calcular_multiplicacion(float numero1, float numero2) {
	float resultado_multiplicacion;
	resultado_multiplicacion = numero1 * numero2;
	printf("Multiplicación: %f\n", resultado_multiplicacion);
}

int calcular_division(float numero1, float numero2) {
	float resultado_division;
	resultado_division = numero1 / numero2;
	printf("División: %f\n", resultado_division);

}

int main() {

	float numero1;
	float numero2;
	printf("Escribe un float: ");
	scanf("%f", &numero1);

	printf("Escribe otro float: ");
	scanf("%f", &numero2);

	char operacion;

	printf("¿Qué operación deseas realizar?\nPulse 's' para sumar, 'r' para restar, 'm' para multiplicar y 'd' para dividir.\n");

	scanf(" %c", &operacion);

	if(operacion == 's'){
		calcular_suma(numero1, numero2);
	} else if(operacion == 'r'){
		calcular_resta(numero1, numero2);
	
	} else if(operacion == 'm'){
		calcular_multiplicacion(numero1, numero2);

	} else if(operacion == 'd'){
		calcular_division(numero1, numero2);

	} else{
		printf("Por favor, seleccione una de las opciones.\n");

	}
	return 0;
}
