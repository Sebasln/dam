#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 2;
	for(; i < 19; i = i + 2){
		printf("%d, ", i);
	}
	
	printf("%d. \n", i); //se queda el valor de i como 20, ya tras haber terminado el for.

	return 0;
}
