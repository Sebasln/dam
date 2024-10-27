#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;

	printf("Quieres pintar un perro(1) o un gato(2)? ");
	scanf("%d", &num);

	switch(num){
		case 1:
			printf("  __      _\no'')}____//\n `_/      )\n (_(_/-(_/\n");
			break;
		case 2:
			printf("           / \n       )  ( ')\n      (  /  )\njgs     (__)|\n");
			break;
		default:
			printf("Elige una opción\n");
			break;

	}
}
