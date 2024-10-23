#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;

	printf("Introduce un número: ");
	scanf("%d", &num);

	printf("Los divisores son: ");
	int i;

	for(i = 1; i < num; i++ ){
		if(num % i == 0){
			printf("%d, ", i);
		} 
	}
	printf("%d. \n", i);

	return 0;
}
