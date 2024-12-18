#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definimos constantes para los caracteres del titulo y del autor y el número máximo de elementos que habrá en el catálogo
#define MAX_CHARS_TITLE 80
#define MAX_CHARS_AUTHOR 43
#define MAX_CATALOG 40

//Declaramos un tipo de variable enum llamada genre con la que podremos enumerar los distintos tipos de género 
typedef enum{
	FICTION,
	NON_FICTION,
	POETRY,
	THEATER,
	ESSAY
} genre;

//Definimos un struct con las propiedades que nos pide el enunciado
typedef struct{
	int id;
	char title[MAX_CHARS_TITLE];
	char author[MAX_CHARS_AUTHOR];
	float price;
	genre typeGenre;
	int stock;

} Book;


//Creamos el array de libros que nos da el enunciado con sus debidas propiedades
Book books[MAX_CATALOG] = {
	{1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10},
	{2, "1984", "George Orwell", 12.49, FICTION, 5},
	{3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8},
	{4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12},
	{5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7},
	{6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9},
	{7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6},
	{8, "The Odyssey", "Homer", 17.49, FICTION, 4},
	{9, "Ulysses", "James Joyce", 25.00, FICTION, 2},
	{10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3},
	{11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11},
	{12, "The Iliad", "Homer", 18.50, FICTION, 7},
	{13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15},
	{14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20},
	{15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13},
	{16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6},
	{17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5},
	{18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8},
	{19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4},
	{20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14},
	{21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6},
	{22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8},
	{23, "Othello", "William Shakespeare", 10.99, THEATER, 7},
	{24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5},
	{25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4},
	{26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10},
	{27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9},
	{28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3},
	{29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15},
	{30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10},
	{31, "Paradise Lost", "John Milton", 12.00, POETRY, 7},
	{32, "Beowulf", "Anonymous", 15.00, POETRY, 5},
	{33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4},
	{34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9},
	{35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11},
	{36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8},
	{37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5},
	{38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12},
	{39, "The Republic", "Plato", 16.00, ESSAY, 6},
	{40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10}
};
//Declaramos esta función con data como puntero de tipo const porque no nos interesa modificar su valor
void showAll(const Book * data){ 
	char input;

	printf("Do you want to see all books? (y/n) ");
	scanf("%c", &input);

	int validation = checkInput(input);

	if (validation == 0){
		return;
	} else if (validation == -1) {

		return;
	}

	printf("Here is the entire list of books: \n");

		//Pintamos todos los libros uno por uno
	for(int i = 0; i < MAX_CATALOG; i++){ 
		printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %i\n\tStock: %d\n",data[i].id,data[i].title,data[i].author,data[i].price,data[i].typeGenre,data[i].stock);
	}
}

void searchBook(const Book * data){
		char input; //Declaramos la variable donde guardaremos si el usuario quiere o no que el programa realice x función

		//Inicializamos un bucle while para que la función se repita constantemente hasta que el usuario elija seguir a la siguiente opción si la hay
				// printf("Do you want to search a book? (y/n) ");
				// scanf(" %c", &input);

				// int validation = checkInput(input); //Declaramos una variable validation con el valor de retorno que nos de la funcion checkInput después de que el usuario haya introducido si sí o si no

				// if (validation == 0){ //Si el usuario escribió que no, se dará este caso y terminará la función
				//         return;
				// } else if (validation == -1) { //Si no ha dicho que si o que no, habrá dado error en la función y aquí repetiremos el bucle otra vez
				//         return;
				// }

				int search; //Declaramos una variable en la que se guardará el valor introducido por el usuario

				printf("Enter an id(1-40): \n");
				scanf("%d", &search);

				for (int i = 0; i < MAX_CATALOG; ++i){  

						if(search == i + 1){ //Si el valor coincide con i + 1(porque las ids empiezan desde 1, no desde 0) se pintarán todos los datos de ese libro
							printf("Name: %s\nAuthor: %s\nId: %d\nPrice: %f\nGenre: %d\nStock: %d\n", data[i].title ,data[i].author ,data[i].id ,data[i].price ,data[i].typeGenre ,data[i].stock );
						}
					}

				if(search < 0 || search > 40){ //Si no hay niguna id con ese valor, se le pedirá al usuario que introduzca una id válida
					printf("Enter a valid number.\n");
				}
			}

//En este caso no declaramos data como const porque sí queremos modificar su valor
			void addStock(Book *data){
				char input;

				while(1) {
					printf("Do you want to add stock to a book? (y/n) ");
					scanf(" %c", &input);

					int validation = checkInput(input);

					if (validation == 0){
						return;
					} else if (validation == -1) {
						continue;               
					}

				//Declaramos las variables search y sum para guardar el libro buscado y el añadido de stock
					int search, sum;

					printf("Which book do you want to add stock to? Write its ID\n");
					scanf("%d", &search);

				//Si no hay libros con el id dado se acabará la iteración actual
					if (search < 1 || search > MAX_CATALOG) {
						printf("There are no books with ID %d.\n", search);
						continue;
					}

					printf("How many units do you want to add to the stock? ");
					scanf("%d", &sum);

				//Se modifica el valor del stock del número introducido menos uno porque el id es una unidad mayor a la posición del libro
					data[search - 1].stock += sum;

					printf("The stock for the book %s has been updated to %d units.\n", data[search - 1].title, data[search - 1].stock);
				}
			}

//No cambiamos el valor de data, pues se usa const
			void showCategory(const Book * data){
				char input;

				while(1){
					printf("Do you want to search books by category? (y/n) ");
					scanf(" %c", &input);

					int validation = checkInput(input);

					if (validation == 0){
						return;
					} else if (validation == -1) {
						continue;
					}

					int search;

					printf("Enter a number to display all books from the same category(1: FICTION, 2: NON_FICTION, 3: POETRY, 4: THEATER, 5: ESSAY)\n");
					scanf("%d", &search);

					for(int i = 0; i < MAX_CATALOG; i++){

						//Si el valor introducido menos una unidad(porque el id es una unidad mayor a la posición) concuerda con el tipo de género del libro que está en iteración entonces se pintará el libro i
						if((search - 1)== data[i].typeGenre){

							printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %i\n\tStock: %d\n",data[i].id,data[i].title,data[i].author,data[i].price,data[i].typeGenre,data[i].stock);
						}
					}

				//Si no elegido ninguna de las opciones da error y se repite el bucle
					if(search < 0 || search > 5){
						printf("Enter a valid number.\n");
						continue;
					}

				}
			}

			void displayByAuthor(const Book * data){
				char input;

				while(1){
					printf("Do you want to search by author? (y/n) ");
					scanf(" %c", &input);

				//Limpiamos el buffer para que luego el fgets no dé problemas
					getchar();

					int validation = checkInput(input);

					if (validation == 0){
						return;
					} else if (validation == -1) {

						continue;
					}

				//Declaramos un string con el número de carácteres máximo de autor
					char search[MAX_CHARS_AUTHOR];

					printf("Enter an author to display all their books:\n");

				//En vez de usar scanf, necesitamos un fgets porque algunos autores están compuestos por más de una sola palabra, por lo general nombre y apellido
					fgets(search, MAX_CHARS_AUTHOR, stdin);

				//La función fgets mete un salto de línea al final del string, así que nos toca quitarlo para que luego, al comparar strings, no de error

				//Pillamos la longitud del string
					size_t len = strlen(search);

				//Si el string no está vacío y el último carácter es un salto de línea, se reemplaza por un carácter vacío
					if (len > 0 && search[len - 1] == '\n') {
						search[len - 1] = '\0';
					}

				//Y se sigue con normalidad
					for(int i = 0; i < MAX_CATALOG; i++){

						//Si search es igual al nombre del autor, se pintará el libro de la iteración actual
						if(strcmp(search, data[i].author) == 0){

							printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %i\n\tStock: %d\n",data[i].id,data[i].title,data[i].author,data[i].price,data[i].typeGenre,data[i].stock);
						}
					}
				}
			}


			int main(int argc, char ** argv){

				printf("Lista de argumentos:\n");
				for (int i = 0; i < argc; i++){
					printf("\t Argumento %d: %s\n", i, argv[i]);
				}


				if (argc < 2) {
        printf("Pon en ./bibioteca [lo que quieres hacer] [argumentos] \n");		// hay que tener en cuenta que el primer argumento que coge es ./biblioteca, por lo que si ponemos solo esto nos saltara el printf de como hay que poner para iniciar el programa.	
        return 0;																	
    }

    if (strcmp(argv[1], "mostrar") == 0) {			//Lo que hace es comparar el primer argumento dado con la palabra mostrar y si son iguales entonces hara lo que hay dentro del if.
    	if (argc == 2) {							
            showAll();				//Aqui comprobamos si hay más argumentos aparte de de mostrar para saber si llamar a mostarTosdosLosLibros, o a mostrarLibroPorId.		
        } else if (argc == 3) {
            int id = atoi(argv[2]);					//Lo que hace es declarar el int id con el tercer argumento.
            searchBook(id);					//Llama a mostrarLibroPorId y le pasa el id a la funcion.
        }
    } else if(strcmp(argv[1], "stock") == 0) {		//Lo que hace es comparar el primer argumento dado con la palabra stock y si son iguales entonces hara lo que hay dentro del if.
    	if (argc == 2) {							//Comprueba si tiene los argumentos necesarios, sino te mostrara como ponerlos.
    		printf("Debes de poner ./biblioteca stock [ID] [CantidadAAñadir]\n ");
    	}else if(argc == 3){						//Comprueba si tiene los argumentos necesarios, sino te mostrara como ponerlos. 
    		printf("Debes de poner ./biblioteca stock [ID] [CantidadAAñadir]\n ");
    	}else if (argc == 4){						//Comprueba si tiene los argumentos necesarios.
    		int id = atoi(argv[2]);					//Lo que hace es declarar el int id con el tercer argumento.
        	int cantidad = atoi(argv[3]);			//Lo que hace es declarar el int cantidad con el cuarto argumento.
        	(id, cantidad);			//LLama a la función actualizar stock y le pasa id y cantidad a la función.
        }
    } else if(strcmp(argv[1], "categoria") == 0) {	//Lo que hace es comparar el primer argumento dado con la palabra categoria y si son iguales entonces hara lo que hay dentro del if.
    	if (argc == 2) {							//Comprueba si tiene los argumentos necesarios, sino te mostrara como ponerlos. 
    		printf("Debes de poner ./biblioteca categoria [Categoria 0 1 2 3 4]\n" );
    	} else if(argc == 3){						//Comprueba si tiene los argumentos necesarios.
    		Genero gen = atoi(argv[2]);  			//Lo que hace es declarar gen con el tercer argumento.
        	mostrarLibrosPorGenero(gen);			//Llama a la función mostrarLibroPorGenero.
        }
    } else if(strcmp(argv[1], "autor") == 0) {		//Lo que hace es comparar el primer argumento dado con la palabra autor y si son iguales entonces hara lo que hay dentro del if.
    	if (argc == 2) {							//Comprueba si tiene los argumentos necesarios, sino te mostrara como ponerlos .
    		printf("Debes de poner ./biblioteca autor [NombreAutor]\n");
    	} else if (argc == 3){						//Comprueba si tiene los argumentos necesarios.
    		mostrarLibrosPorAutor(argv[2]);			//Llama a la función mostrarLibrosPorAutor y le pasa el valor del tercer argumento.
    	}
    }	 -
		//Llamamos a todas las funciones

		// addStock(books);

		// showCategory(books);

		// displayByAuthor(books);

    return 0;
}
}
