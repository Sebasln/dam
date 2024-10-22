#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	char str[100];
	char reemplazo;
	
	printf("Introduzca una palabra:");
	scanf("%s", str);

	printf("¿Qué posición desea modificar?");
	scanf("%i", &num);

	printf("¿Qué carácter desea poner?");
	scanf(" %c", &reemplazo);
		
	str[num - 1] = reemplazo;

	printf("La nueva palabra es: %s\n", str);

	return 0;
}
