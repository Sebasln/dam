#include <stdio.h>
#include <stdlib.h>

int main(){
	int nota;

	printf("Introduce la nota:\n");
	scanf("%i", &nota);
	
	(nota >= 5) ? printf("Aprobado\n") : printf("Suspenso\n");
	return 0;
}
