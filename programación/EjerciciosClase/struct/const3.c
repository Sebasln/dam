#include <stdio.h>

int main() {
    int numero = 10;
    int trampa = 30;

    const int * const ptr = &numero;
    //El valor apuntado es constatnte

    printf("Valor: %d\n", *ptr);

    //*ptr = 20; //Esto daría un error porque el valor es constante
    numero = 20; //Cambiar el valor directamente es válido
    printf("Nuevo valor: %d\n", *ptr);

    //Vamos a trampear:

    ptr = &trampa;//Ahora da error porque es connstante la dirreccion de memoria que apunta

    *ptr = 30; // Ahora si puedo modificar el contenido que apunta el puntero.
    //Ahora al haber definido ambas cosas como constantes no puedo hacer una trampa

    printf("Nuevo valor: %d\n", *ptr);

    return 0;
}