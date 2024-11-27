#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 20
#define MAX_BUFFER 200


typedef struct {
	char nombre[MAX_NOMBRE];
	int edad;
	float nota;
} Estudiante;



void inicializar(Estudiante * estudiante_a_rellenar,char * nombre, int edad, float nota){

	estudiante_a_rellenar->edad = edad;
	estudiante_a_rellenar->nota = nota;
	strcpy(estudiante_a_rellenar->nombre, nombre);

}

void cumpleanios(Estudiante * cumpleanios) {
	cumpleanios->edad++;
	

}

void imprimirEstudiante(const Estudiante * estudiante_a_imprimir){

	printf("Nombre: %s\n", estudiante_a_imprimir->nombre);
	printf("\tEdad: %d\n", estudiante_a_imprimir->edad);
	printf("\tNota: %f\n", estudiante_a_imprimir->nota);

}



char * estudianteToString(const Estudiante * datos, char * retval){

	snprintf(retval, MAX_BUFFER*sizeof(char), "El estudiante %s de %d años ha sacado un %f.", datos->nombre, datos->edad, datos->nota);
}

char * modificarNombreEstudiante(Estudiante * datos){
	printf("Elige el nombre nuevo para este estudiante: ");
	scanf("%s", datos->nombre);
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

	//El estudiante de la primera posición ha cumplido años
	printf("Edad antigua de %s: %d\n", listado[0].nombre, listado->edad);
	cumpleanios(&listado[0]);
	printf("Edad nueva: %d\n", listado[0].edad);

	//Vamos a imprimir estudiantes
	imprimirEstudiante(&listado[0]);
	
	

	

	char StringARellenar[MAX_BUFFER];
	estudianteToString(&listado[0], StringARellenar);
	printf("%s\n", StringARellenar);

	modificarNombreEstudiante(&listado[0]);
	printf("%s\n", listado[0].nombre);

	return 0;
}