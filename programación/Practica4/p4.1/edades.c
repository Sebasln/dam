#include <stdio.h>
#include <stdlib.h>

int main() {

	int edad;
	printf("Cuántos años tienes \n");
	scanf("%d", &edad);
	if(edad < 12){
		printf("Eres un niño\n");
	} else if(edad >= 12 && edad <= 17){
		printf("Eres un chaval\n");
	} else if(edad >= 18 && edad <= 64){
		printf("Eres un adulto\n");
	} else{
		printf("Eres un viejo\n");
	}

	return 0;
}
