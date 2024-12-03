#include <stdio.h>
#include <stdlib.h>
int main(){
	int num;
	printf("Introduce un número, si quieres terminar el programa debe ser menor q cero. ");
	scanf("%d", &num);
	while(num > 0){
		printf("Introduce un número, si quieres terminar el programa debe ser menor q cero. ");
		scanf("%d", &num);
	}
	printf("acabé\n");
	return 0;
}

