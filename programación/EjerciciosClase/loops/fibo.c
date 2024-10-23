#include <stdio.h>
#include <stdlib.h>

int main(){
	for(int i = 0, j = 1, k = 1;k <= 5;k++, i = j + i){
		printf("%d ", i);

		j = j + i;
		printf("%d ", j);
	}
	printf("\n");
	return 0;
}
