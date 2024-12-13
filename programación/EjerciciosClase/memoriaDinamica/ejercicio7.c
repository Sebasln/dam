#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, *arr;

    printf("Introduce el tamaño inicial del arreglo: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Introduce %d elementos para el arreglo inicial:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Los elementos iniciales del arreglo son:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i + 1, arr[i]);
    }

    printf("Introduce el nuevo tamaño del arreglo: ");
    scanf("%d", &m);

    arr = (int *)realloc(arr, m * sizeof(int));
    if (arr == NULL) {
        printf("Error al redimensionar la memoria.\n");
        return 1;
    }

    if (m > n) {
        printf("Introduce %d elementos adicionales para el arreglo:\n", m - n);
        for (int i = n; i < m; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }

    printf("Los elementos del arreglo redimensionado son:\n");
    for (int i = 0; i < m; i++) {
        printf("Elemento %d: %d\n", i + 1, arr[i]);
    }

    free(arr);

    return 0;
}
