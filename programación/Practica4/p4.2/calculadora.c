#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1, num2, resultado;
	char operador;

	printf("Introduce el primer número:\n");
	scanf("%i", &num1);
	printf("Introduce el segundo número:\n");
	scanf("%i", &num2);

	printf("Introduce el operador:\n");
	scanf(" %c", &operador);

	switch(operador){
		case '+':
			resultado = num1 + num2;
			printf("%i\n", resultado);
			break;
		case '-':
			resultado = num1 - num2;
			printf("El resultado es: %i\n", resultado);
			break;

		case '*':
			resultado = num1 * num2;
			printf("El resultado es:%i\n", resultado);
			break;
		case '/':
			resultado = num1 / num2;
			printf("El resultado es: %i\n", resultado);
			break;
		default:
			printf("Operador no válido.\n");

	} 

	return 0;
}
