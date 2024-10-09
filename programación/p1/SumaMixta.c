#include <stdio.h>
#include <stdlib.h>

int main() {

   int numero1;
   int numero2;
   float resultado_suma;
   float resultado_resta;
   float resultado_division;
   float resultado_multiplicacion;



   printf("Escribe un integrer: ");
   scanf("%d", &numero1);

   printf("Escribe otro integrer: ");
   scanf("%d", &numero2);


   resultado_suma = numero1 + numero2;
   resultado_resta = numero1 - numero2;
   resultado_multiplicacion = numero1 * numero2;
   resultado_division = numero1 / numero2;

   printf("Suma: %lf\n", resultado_suma);
   printf("Resta: %lf\n", resultado_resta);
   printf("Multiplicación: %lf\n", resultado_multiplicacion);
   printf("División: %lf\n", resultado_division);
   return 0;
} 
