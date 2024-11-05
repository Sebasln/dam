#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); //cambia cada segundo
	int randomNumber = (rand() % 100) + 1; //se le suma 1 porque va de 0 a 99. //se le suma 1 porque va de 0 a 99.
	//modulo 100 da numeros entre 0 y 99
	int num = 150;
	
	printf("Adivina el número en el que estoy pensando: ");
	scanf("%d", &num);

	printf("%d\n", randomNumber);

	while(randomNumber != num){
		printf("Vuelvelo a intentar: ");
		scanf("%d", &num);
	}
	printf("Ganaste.\n");
	return 0;
}

