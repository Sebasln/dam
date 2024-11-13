#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[5] = {10, 20, 30, 40, 50};
	int *p = arr, suma = 0;


	for(int i = 0; i < 5; i++){

		suma += *(p +i); 
	}

	printf("La suma es %d\n", suma);

	return 0;
}
