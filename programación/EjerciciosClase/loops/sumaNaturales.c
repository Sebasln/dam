#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 0;
	for(int i = 0; i < 11; i++){
			a += i;
		printf("%d\n", a);
	}
	printf("La suma es: %d\n", a);

	return 0;
}
