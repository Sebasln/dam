#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int hex;
	printf("Introduce un número hexadecimal: ");
	scanf("%x", &hex);
	printf("Has introducido: %#x\n", hex);

	return 0;


}
