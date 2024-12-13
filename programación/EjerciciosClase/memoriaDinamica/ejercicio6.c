#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, *arr;

    // Solicitar el tamaño del arreglo al usuario
    printf("Introduce el tamaño del arreglo: ");
    scanf("%d", &n);

    // Reservar memoria para el arreglo
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Solicitar los valores del arreglo
    printf("Introduce %d elementos para el arreglo:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Imprimir los valores del arreglo
    printf("Los elementos del arreglo son:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i + 1, arr[i]);
    }

    // Liberar la memoria reservada
    free(arr);

	return 0; 
}