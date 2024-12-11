#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	int * p_error = malloc(sizeof(int));

	int *p = (int *) malloc(sizeof(int));

	if(p == NULL){

		printf("Error fatal\n");
		return 1;
	}

	*p = 42;
	printf("El valor es: %d\n", *p);
	free(p);
	free(p_error);

	return 0;
}
