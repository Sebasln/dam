#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *str1 = malloc(100 * sizeof(char));
	char *str2 = malloc(100 * sizeof(char));

	printf("Escribe una palabra: ");
	scanf("%s", str1);

	printf("Escribe otra palabra: ");
	scanf("%s", str2);


	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);


	if (strcmp(str1, str2) == 0) {
		printf("Las dos cadenas son iguales.\n");
	} else {
		printf("Las dos cadenas son diferentes.\n");
	}

	if(len1 > len2){
		printf("La primera palabra(%s) es más larga que la seguna(%s)\n", str1, str2);
	} else if( len2 > len1) {
		printf("La segunda palabra(%s) es más larga que la primera(%s)\n", str2, str1);
	} else {
		printf("Son igual de largas\n");
	}

	if(str1[0] == str2[0] && str1[1] == str2[1]){
		printf("Las dos palabras coinciden en los dos primeros caracteres, que son: %c%c\n", str1[0], str1[1]);
	} else if(str1[0] == str2[0]){
		printf("Las dos palabras coinciden en el primer carácter, que es: %c\n", str1[0]);
	} else {
		printf("Las dos palabras no coinciden ni en el segundo, ni en el primer carácter.\n");
	}
	return 0;

}
