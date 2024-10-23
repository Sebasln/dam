#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, suma = 0, digito;

	printf("Introduce un número entero positivo: ");
	scanf("%d", &n);

	while (n > 0) {
		digito = n % 10;
		suma += digito;
		n /= 10;
	}

	printf("La suma de los dígitos es: %d\n", suma);
	return 0;
}
