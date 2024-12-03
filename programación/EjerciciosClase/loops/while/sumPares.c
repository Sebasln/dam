#include <stdio.h>
#include <stdio.h>

int main(){
	int num;

	printf("Introduce un número par: ");
	scanf("%d", &num);

	while(num % 2 == 0){
		num += 0;
		printf("%d\nEscribe otro número par: ", num);
		scanf("%d", &num);
	}
	printf("Ese número es impar pedazo de down.\n");

}
