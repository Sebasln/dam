#include <stdio.h>
#include <stdlib.h>

int main(){
	int factou;
	int container = 1;

	printf("introduce el número del que quieres obtener su factorial: \n");
	scanf("%d", &factou);

	for(int num = 1; num <= factou; num = num + 1){
		container *= num;
	}

		printf("%d\n", container);


	return 0;
}
