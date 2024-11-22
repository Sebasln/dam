#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20

typedef struct {
	char nombre[MAX_NOMBRE];
	int edad;
	float nota;
} Estudiante;



void inicializar(Estudiante * estudiante_a_rellenar,char * nombre, int edad, float nota){
		/*
	//Esto no compila porque estudiante_a_rellenar es un puntero, no un estudiante. Por lo q tocaria poner (*estudiante_a_rellenar).edad, pero como eso es muy feo, aprovechamos q C traduce esto mediante el operador ->
	
	estudiante_a_rellenar.edad = edad;
	estudiante_a_rellenar.nota = nota;

	//esto no sirve porque estas igualando direcciones de memoria y no valores

	estudiante_a_rellenar.nombre = nombre;
	*/

	estudiante_a_rellenar->edad = edad;
	estudiante_a_rellenar->nota = nota;
	strcpy(estudiante_a_rellenar->nombre, nombre);
}


int main(){
	Estudiante listado[MAX_ESTUDIANTES]; //Aquí se reserva la memoria para los estudiantes

	int num_estudiantes;

	int edad;
	float nota;
	char nombre[MAX_NOMBRE];

	printf("%p\n", listado);
	printf("Sizeof listado: %lu\n", sizeof(listado));
	printf("Sizeof estudiante: %lu\n", sizeof(Estudiante));

	printf("¿Cuántos estudiantes desea inicializar? ");
	scanf("%d", &num_estudiantes);

	for(int i = 0; i < num_estudiantes; i++){
		printf("Introduce la edad: ");
		scanf("%d", &edad);
		printf("Introduce la nota: ");
		scanf("%f", &nota);
		printf("Introduce el nombre: ");
		scanf("%s", nombre);

		inicializar(&listado[i], nombre, edad, nota);
	}
	return 0;
}

//No funciona porque las variables estan en diferentes scopes

/*
void inicializar(char * nombre, int edad, float nota){
	//Creo una variable de tipo Estudiante
	Estudiante e;

	// Inicializo el estudiante, e.edad = edad; e...

	return e;
}
*/

/*
Estudiante * inicializar(char * nombre; int edad, float nota){
	Estudiante * e = malloc; //Memoria dinámica 

	return &e;
}
*/
