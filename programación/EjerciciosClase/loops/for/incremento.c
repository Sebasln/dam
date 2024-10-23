#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 0;

	i = i + 1;
	printf("%d\n", i); 

	i += 1;
	printf("%d\n", i); 
	

	i += 3;
	printf("%d\n", i); 

	
	i += 5;
	printf("%d\n", i); 

	for (int i = 0; i < 101;i = i + 2){
		printf("%d, ", i);
	}

	printf("Hecho\n");

	return 0;
}
