#include <stdio.h>
#include <stdlib.h>

int main(){
	int numeroAsteriscos;
	char asterisco = '*';

	printf("Introduce el numero de asteriscos por lado: ");
	scanf("%d", &numeroAsteriscos);

	for(int i = 0;i < numeroAsteriscos; ++i){
		for(int i = 0;i < numeroAsteriscos; ++i){
			printf("%c ", asterisco);
		}
		printf("\n");
	}
	return 0;
}
