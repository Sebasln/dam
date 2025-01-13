#include <stdio.h>
#include <stdlib.h>

int main(){

	//Declara un array de tamaño 3 utilizando memoria dinámica

	int * arr = (int *) calloc(3, sizeof(int));

	//Siempre hay que comprobar si el array me ha dado NULL, y devolver un 1 si es así

	if (arr = NULL){
		printf("Error\n");
		return EXIT_FAILURE;
	}

	for (int i = 1; i < 3; i++){
		arr[i] = 2*i + 1;

		printf("arr[%d] es %d.\n", i, arr[i]);
	}

	int * arrAmpliado = (int *)realloc(arr, 5*sizeof(int));

	if (arrAmpliado == NULL){
		
		free(arr);

		printf("Error: no se ha podido redimensionar\n");
		return EXIT_FAILURE;
	}

	//Para evitar confusiones entre arr_ampliado y arr, es recomendable añadir: 
	// arr = arr_ampliado;

	//Terminamos de inicializar

	arrAmpliado[3] =  7;
	arrAmpliado[4] =  9;

	for (int i = 0; i < 5; i++){
		printf("arr[%d]: %d.\n", i, arrAmpliado[i]);
	}

	free(arr);
	free(arrAmpliado);

	return EXIT_SUCCESS;
}