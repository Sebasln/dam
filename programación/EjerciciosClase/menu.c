#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char es_vocal(){
	char letra;
	printf("Escribe una letra: ");
	scanf(" %c", &letra); //El espacio permite que  el scanf no se bugee por ir detras del scanf que pide un integrer.

	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
		printf("La letra %c es una vocal.\n", letra);
	} else if(letra < 'A' || letra > 'Z' && !(letra > 'a')){ // Esta condición permite que caracteres que 
		printf("Error en la función es_vocal.\n");
	} else if(letra < 'a' || letra > 'z' && !(letra < 'Z')){
		printf("Error en la función es_vocal.\n");
	}else {
		printf("La letra %c no es una vocal.\n", letra);
	}


}
float calcular_area_figura(){
	float area;
	float radio;
	float lado;
	int figura;
	printf("¿Qué figura deseas calcular (círculo=1, cuadrado=2)? ");
	scanf("%d", &figura);
	if (figura == 2){
		printf("Introduce el lado del cuadrado: ");
		scanf("%f", &lado);
		area = lado * lado;
		printf("El área del cuadrado de lado %.0f es %.2f\n", lado, area);
	}else if (figura == 1){
		printf("Introduce el radio del circulo: ");
		scanf("%f", &radio);
		area = M_PI * (radio * radio);
		printf("El area del círculo con radio %.0f es %.2f\n", radio, area);
	}else{
		printf("Error en la función calcular_area_figura\n");
	}
}

double calcular_promedio_tres_num(){
	double num1, num2, num3, promedio;
	printf("Introduzca el primer número: ");
	scanf("%lf", &num1);

	printf("Introduzca el segundo número: ");
	scanf("%lf", &num2);

	printf("Introduzca el tercer número: ");
	scanf("%lf", &num3);

	promedio = (num1 + num2 + num3) / 3;
	printf("El promedio de %.0lf, %.0lf y %.0lf es %.2f.\n", num1, num2, num3, promedio);
	return promedio;
}

double calcular_promedio_cuatro_num(){
	double promedio, num1, num2, num3, num4;
	printf("Introduzca el primer número: ");
	scanf("%lf", &num1);

	printf("Introduzca el segundo número: ");
	scanf("%lf", &num2);

	printf("Introduzca el tercer número: ");
	scanf("%lf", &num3);

	printf("Introduzca el cuarto número: ");
	scanf("%lf", &num4);

	promedio = (num1 + num2 + num3 + num4) / 4;

	printf("El promedio de %.0lf, %.0lf, %.0lf y %.0lf es %.2lf.\n", num1, num2, num3, num4, promedio);
	return 0;
}

float calcular_promedio(){
	int num;

	printf("¿De cuántos números quiere hacer el promedio? (3 o 4)\n");
	scanf("%i", &num);

	if(num == 3){
		calcular_promedio_tres_num();
	} else if(num == 4){
		calcular_promedio_cuatro_num();
	} else {
		printf("Error en la función calcular_promedio.\n");
	}
	return 0;
}

int convertir_hora_24_a_12(){
	int hora;
	printf("Introduce la hora en formato 24 horas: ");
	scanf("%i", &hora);

	if(hora >= 0 && hora <= 12){
		printf("La hora en formato de 12 horas es %i AM.\n", hora);
	} else if(hora <=24 && hora >= 13){
		hora = hora - 12;
		printf("La hora en formato de 12 horas es %i PM.\n", hora);
	} else {

		printf("Hora no válida.\n");
	}

}

int es_primo(){
	int num;
	printf("Introduce un número menor de 10: ");
	scanf("%i", &num);

	if(num == 0 || num == 1 || num == 4 || num == 6 || num == 8 || num == 9){
		printf("El número %i no es primo.\n", num);
	} else if(num == 2 || num == 3 || num == 5 || num == 7){
		printf("El número %i es primo.\n", num);
	} else if(num >= 10){
		printf("El número debe ser menor que 10.\n");
	}
}

int comparar_3_numeros(){
	int num1, num2, num3;

	printf("Introduce el número 1: ");
	scanf("%i", &num1);

	printf("Introduce el número 2: ");
	scanf("%i", &num2);

	printf("Introduce el número 3: ");
	scanf("%i", &num3);

	if(num1 > num2 && num1 > num3){
		printf("El mayor número es %i.\n", num1);
	} else if(num2 > num1 && num2 > num3){
		printf("El mayor número es %i.\n", num2);
	} else if(num3 > num2 && num3 > num1){
		printf("El mayor número es %i.\n", num3);
	} else {
		printf("Los números son iguales.\n");
	}
}

int main(){
	int opcion;
	printf("Selecciona una opción: \n1. Verificar si una letra es una vocal.\n2.Calcular el área de una figura (círculo o cuadrado).\n3. Calcular el promedio de 3 o 4 números.\n4. Convertir una hora en formato de 24 horas a 12 horas.\n5. Verificar si un numero menor de 10 es primo.\n6. Comparar tres números.\n7. Salir.\nOpción: ");

	scanf("%d", &opcion);

	if(opcion == 1 ){
		es_vocal();
	}else if(opcion == 2){
		calcular_area_figura();
	}else if(opcion == 3){
		calcular_promedio();
	}else if(opcion == 4){
		convertir_hora_24_a_12();
	}else if(opcion == 5){
		es_primo();
	}else if(opcion == 6){
		comparar_3_numeros();
	}else if(opcion == 7){
		printf("Has decidido salir\n");
	}else{
		printf("No has elegido ninguna opción\n");
	}



	return 0;
}
