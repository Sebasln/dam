#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 5;

	//int arr[5];

	int * arr = (int *) malloc(sizeof(int)*5);

	if(arr = NULL){
		printf("Error: no se puede asignar memoria.\n");
		return 1;
	}
	
	for(int i = 0; i < n; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
		//printf("arr[%d] = %d\n", i, *(arr + i));

	}

	int * arr2 = (int *) calloc(5, sizeof(int));

	if(arr2 == NULL){
		printf("Error: no se puedo asignar memoria\n");
		return 1;
	}

for (int i = 0; i < n; i++){
		printf("arr2[%d] = %d\n", i, arr2[i]);
}


	free(arr);

	return 0;
}
