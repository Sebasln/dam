#include <stdio.h>
#include <stdlib.h>

int main() {

	int dia;
	printf("Introduce un número:\n");
	scanf("%i", &dia);

	switch(dia){
		case 1: 
			printf("Es lunes.\n");
			break;
		case 2: 
			printf("Es martes.\n");
			break;
		case 3: 
			printf("Es miércoles.\n");
			break;

		case 4: 
			printf("Es jueves.\n");
			break;
		case 5: 
			printf("Es viernes.\n");
			break;
		case 6: 
			printf("Es sábado.\n");
			break;
		case 7: 
			printf("Es domingo.\n");
			break;

		default:
			printf("Número inválido\n");
			break;
	}

	return 0;
}
