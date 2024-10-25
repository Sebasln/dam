#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, suma = 0, digito;
	
	printf("mete un numero: ");
	scanf("%d", &n);

	while(n > 0){
		digito = n % 10;
		suma += digito;
		printf("%d", suma);
		n /= 10;
		suma = 0;
	}
	
		printf("\n");

	return 0;
}
