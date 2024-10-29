#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int randomNumber = rand() % 100;
	int num = 150;
	
	printf("Adivina el número en el que estoy pensando: ");
	scanf("%d", &num);

	printf("%d", randomNumber);
	while(randomNumber != num){
		printf("Vuelvelo a intentar: ");
		scanf("%d", &num);
	}
	printf("Ganaste.\n");
	return 0;
}

