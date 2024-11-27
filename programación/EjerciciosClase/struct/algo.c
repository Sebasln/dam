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

//No es necesario un valor de retorno.
// Cumpleanios 

void cumpleanios(Estudiante * cumpleanios) {
	cumpleanios->edad++;
	

}

/*
27/11 vamos a crear una función para imprimir un estudiante, lo vamos a hacer de dos formas (pasarlo por valor o por referencia)
*/

//Recibe un estudiante y muestra por pantalla todos sus datos
void imprimirEstudiante(const Estudiante * estudiante_a_imprimir){

	printf("Nombre: %s\n", estudiante_a_imprimir->nombre);
	printf("\tEdad: %d\n", estudiante_a_imprimir->edad);
	printf("\tNota: %f\n", estudiante_a_imprimir->nota);

}

//Me interesa una función de imprimir sin los printfs. 

/*0
char * estudianteToString_warning(Estudiante * datos){
	char retval[MAX_BUFFER];

	//snprintf (donde, cuanto, el qué [lo q harias con un printf])
	snprintf(retval, MAX_BUFFER, "El estudiante %s de %d años ha sacado un %f.", datos->nombre, datos->edad, datos->nota);

	return retval;
}
*/

char * estudianteToString(const Estudiante * datos, char * retval){

	//snprintf (donde, cuanto, el qué [lo q harias con un printf])
	snprintf(retval, MAX_BUFFER*sizeof(char), "El estudiante %s de %d años ha sacado un %f.", datos->nombre, datos->edad, datos->nota);
}

char * modificarNombreEstudiante(Estudiante * datos, char * nombreNuevo){

	printf("Elige el nombre nuevo para este estudiante: ");
	scanf("%s", datos->nombre);

}

//Crea una función que cree una cadena de teto con la informacion del estuidaitne
//(Puedes emepzar creando una funcion que imprima por pantalla la info de un estudiante).


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

	char stringNombreNuevo[MAX_BUFFER];
	modificarNombreEstudiante(&listado[0], stringNombreNuevo);
	printf("%s\n", stringNombreNuevo);

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
