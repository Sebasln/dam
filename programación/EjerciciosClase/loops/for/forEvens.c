#include <stdio.h>
#include <stdlib.h>

int main(){
	for (int i = 0; i < 101;i = i + 2){
		printf("%d, ", i);
	}

	printf("Hecho\n");

	return 0;
}
