#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main(){
	int num;
	char str[100];
	char reemplazo;

	printf("Introduce la palabra: ");
	scanf("%s", str);

	int longitud = strlen(str);

	printf("Introduce la letra que quieres poner al final: ");
	scanf(" %c", &reemplazo);

	str[longitud] = reemplazo;
	

	printf("Tu palabra nueva es: %s\n", str);


	
	return 0;
}
