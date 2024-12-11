#include <stdio.h>
#include <stdlib.h>

int main(){

	int num;

	printf("Introduce un número: ");
	scanf("%d", &num);

	int *arr = (int *) malloc(num * sizeof(int));

	if (arr == NULL){
		printf("Error al asignar memoria.\n");
		return 1;
	}

	printf("Imprimir los valores del array:\n");

	for(int i = 0; i < num; i++){
		arr[i] = i*2 + 2;
	}

	for (int i = 0; i < num; i++){
		printf("%d\n", arr[i]);
	}            

	printf("parte 2:\n")

	int * arrAmpliado = (int *)realloc(arr, num*sizeof(int));

	if (arrAmpliado == NULL){
		
		free(arr);

		printf("Error: no se ha podido redimensionar\n");
		return EXIT_FAILURE;
	}



	for (int i = 0; i < num*2; i++){
		arr[i] = i*2 + 1;
	}

	for (int i = 0; i < num*2; i++){
		printf("array[%d]%d\n", i, arr[i]);
	}
	free(arr);
	return 0;
}