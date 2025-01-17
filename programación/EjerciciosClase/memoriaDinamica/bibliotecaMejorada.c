#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definimos las constantes para los tamaños máximos de título y autor
#define MAX_CHARS_TITLE 80
#define MAX_CHARS_AUTHOR 43

int booksQuantity = 0;  //Número de libros en el catálogo

//Declaramos un enum para representar los géneros de los libros
typedef enum{
    FICTION,
    NON_FICTION,
    POETRY,
    THEATER,
    ESSAY
} genre;

//Declaramos el struct para representar un libro en el que definimos su ID, título, autor, precio, tipo de género (Ficción, No ficción, Poesía, Teatro, Ensayo) y stock
typedef struct{
    int id;
    char title[MAX_CHARS_TITLE];
    char author[MAX_CHARS_AUTHOR];
    float price;
    genre typeGenre;
    int stock;
} Book;


//Creamos una función para convertir los valores enteros del enum en strings de las palabras de cada género, llamando al enum tipo género, haciendo que nos devuelva un string u otro dependiendo de su valor.
const char* convertGenre(genre gen);    

//Se imprime un libro basándose en los datos actuales del struct de tipo libro (Book).
void showBook(const Book* data);

//Se muestran todos los libros en el catálogo actual.
void showAll(const Book* data);

//Busca un libro por ID
void searchBook(const Book * data, int id);

//Agrega stock a un libro
void addStock(Book *data, int id, int sum);

//Muestra los libros de una categoría específica
void showCategory(const Book * data, genre gen);

//Muestra los libros de un autor específico
void displayByAuthor(const Book * data, const char *author);

//Creamos una función con la que añadimos los libros que teníamos en el enunciado, por lo que necesitamos un puntero a la posición del libro, y el resto de sus datos(ID, título, autor, precio, género, stock).
Book* addBook(Book* direction, int addId, const char* addTitle, const char* addAuthor, float addPrice, int addGender, int addQuantity);

//Agrega múltiples nuevos libros al catálogo. Se requiere el puntero a los libros y el número de nuevos libros a agregar.
Book* addNewBook(Book* data, int numNewBooks);

//Borra un libro
void deleteBook(Book* data, int id);

//Función principal para procesar los comandos ingresados por la línea de comandos
int main(int argc, char **argv){

    Book* books = (Book*)malloc(sizeof(Book));  //Inicializamos el catálogo con espacio para un libro
    if (books == NULL) {
        printf("Error: No se pudo asignar memoria inicial.\n");
        return 1;
    }

    //Inicialización del catálogo con 40 libros predefinidos
    books = addBook(books, 1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10);
    books = addBook(books, 2, "1984", "George Orwell", 12.49, FICTION, 5);
    books = addBook(books, 3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8);
    books = addBook(books, 4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12);
    books = addBook(books, 5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7);
    books = addBook(books, 6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9);
    books = addBook(books, 7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6);
    books = addBook(books, 8, "The Odyssey", "Homer", 17.49, FICTION, 4);
    books = addBook(books, 9, "Ulysses", "James Joyce", 25.00, FICTION, 2);
    books = addBook(books, 10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3);
    books = addBook(books, 11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11);
    books = addBook(books, 12, "The Iliad", "Homer", 18.50, FICTION, 7);
    books = addBook(books, 13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15);
    books = addBook(books, 14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20);
    books = addBook(books, 15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13);
    books = addBook(books, 16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6);
    books = addBook(books, 17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5);
    books = addBook(books, 18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8);
    books = addBook(books, 19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4);
    books = addBook(books, 20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14);
    books = addBook(books, 21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6);
    books = addBook(books, 22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8);
    books = addBook(books, 23, "Othello", "William Shakespeare", 10.99, THEATER, 7);
    books = addBook(books, 24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5);
    books = addBook(books, 25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4);
    books = addBook(books, 26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10);
    books = addBook(books, 27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9);
    books = addBook(books, 28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3);
    books = addBook(books, 29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15);
    books = addBook(books, 30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10);
    books = addBook(books, 31, "Paradise Lost", "John Milton", 12.00, POETRY, 7);
    books = addBook(books, 32, "Beowulf", "Anonymous", 15.00, POETRY, 5);
    books = addBook(books, 33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4);
    books = addBook(books, 34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9);
    books = addBook(books, 35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11);
    books = addBook(books, 36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8);
    books = addBook(books, 37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5);
    books = addBook(books, 38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12);
    books = addBook(books, 39, "The Republic", "Plato", 16.00, ESSAY, 6);
    books = addBook(books, 40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 1);

    if (argc < 2) {
        printf("Type in ./biblioteca [command] [arguments]\nList of arguments:\n\t./biblioteca mostrar\n\t./biblioteca mostrar [ID]\n\t./biblioteca stock [ID] [Quantity]\n\t./biblioteca categoria [Category]\n\t./biblioteca autor [name]\n\t./biblioteca autor '[Name composed of two or more words]'\n\t./biblioteca añadir\n\t./biblioteca eliminar\n");
        return 0;
    }

    //Comando para mostrar todos los libros o buscar un libro por ID
    if (strcmp(argv[1], "mostrar") == 0) {
        if (argc == 2) {
            showAll(books);
        } else if (argc == 3) {
            int id = atoi(argv[2]);
            searchBook(books, id);
        }
    }
    else if (strcmp(argv[1], "añadir") == 0){
        books = addNewBook(books, atoi(argv[2]));
    }
    //Comando para agregar stock a un libro
    else if (strcmp(argv[1], "stock") == 0) {
        if (argc == 4) {
            int id = atoi(argv[2]);
            int cantidad = atoi(argv[3]);
            addStock(books, id, cantidad);
        } else {
            printf("Usage: ./biblioteca stock [ID] [Quantity]\n");
        }
    }
    //Comando para mostrar los libros de una categoría específica
    else if (strcmp(argv[1], "categoria") == 0) {
        if (argc == 3) {
            int gen = atoi(argv[2]);

            showCategory(books, (genre)gen);
        } else {
            printf("Usage: ./biblioteca category [genre_id] (1: Fiction, 2: Non fiction, 3: Poetry, 4: Theater, 5: Essay)\n");
        }
    } 
    //Comando para mostrar los libros de un autor específico
    else if (strcmp(argv[1], "autor") == 0) {
        if (argc == 3) {
            displayByAuthor(books, argv[2]);
        } else {
            printf("Usage: ./biblioteca author '[author_name]'\n");
        }
    } else if(strcmp(argv[1], "eliminar") == 0){
        if(argc == 3){
            int id = atoi(argv[2]);
            deleteBook(books, id);
        } else {
            printf("Usage: ./biblioteca delete [ID]\n");
        }

    } 
    //Si el comando no es reconocido
    else {
        printf("Unknown command.\n");
    }

    free(books);
    return 0;
}

void searchBook(const Book * data, int id){

    //Si el ID del libro que se busca está fuera del catálogo actual, manda un mensaje de error y acaba.
    if (id < 1 || id > booksQuantity) {
        printf("Invalid ID.\n");
        return;
    }

    //Imprime el libro buscado.
    showBook(&data[id - 1]);
}

void addStock(Book *data, int id, int sum){

    //Si el ID del libro que se busca está fuera del catálogo actual, manda un mensaje de error y acaba.
    if (id < 1 || id > booksQuantity) {
        printf("Invalid ID.\n");
        return;
    }

    //Si la suma de stock que se quiere añadir es 0 o menor, o 1 o más letras, manda un mensaje de error y acaba.
    if (sum < 1 || sum > 10000) {
        printf("Invalid quantity.\n");
        return;
    }

    //Se le suma la cantidad pedida por el usuario al stock del libro pedido. Se le resta una unidad a la ID porque ésta es una unidad mayor a la posición del libro al que corresponde.
    data[id-1].stock += sum;

    //Imprime el nuevo stock
    printf("The stock for the book '%s' has been updated to %d units.\n", data[id-1].title, data[id-1].stock);
}

void showBook(const Book* data){       
    printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %s\n\tStock: %d\n",
     data->id, data->title, data->author, data->price, convertGenre(data->typeGenre), data->stock);
}

void showAll(const Book* data){ 
    printf("Here is the entire list of books: \n");

    for (int i = 0; i < booksQuantity; ++i) {
         if (data[i].id != 0) {                   //ignora los libros eliminados
            showBook(&data[i]);   
        }
    }
}

void showCategory(const Book * data, genre gen){
    if (gen == 0){
        printf("Invalid ID for genre\n");
        return;
    }

    //Declaramos un bucle for que haga tantas iteraciones como libros haya para que busque libro por libro.
    for(int i = 0; i < booksQuantity; i++){

        //Si en la iteración i el género introducido por el usuario coincide con el del libro de esa posición, se imprimirá dicho libro
        if ((data[i].typeGenre + 1) == gen){
            showBook(&data[i]);
        }
    }
}

void displayByAuthor(const Book * data, const char *author){
    int count = 0;

    //Declaramos un bucle for que haga tantas iteraciones como libros haya para que busque libro por libro.
    for(int i = 0; i < booksQuantity; i++){


        //Si en la iteración i el autor introducido por el usuario coincide con el del libro de esa posición, se imprimirá dicho libro
        if (strcmp(data[i].author, author) == 0){
            count++;
            showBook(&data[i]);
        } 
    }

    if(count == 0){
        printf("There are no books from this author.\n");
    }

}

Book* addBook(Book* direction, int addId, const char* addTitle, const char* addAuthor, float addPrice, int addGender, int addQuantity) {

    //Intentamos reasignar memoria para agregar un libro más al catálogo. 
    //Usamos realloc para aumentar el tamaño del array de libros.
    Book* temp = (Book*)realloc(direction, sizeof(Book) * (booksQuantity + 1));

    //Verificamos si realloc ha fallado (si devuelve NULL, no pudo asignar memoria).
    if (temp == NULL) {
        //En caso de error, liberamos la memoria previamente asignada y retornamos NULL.
        printf("Error: Couldn't reallocate memory.\n");
        free(direction);
        return NULL;
    }

    //Si realloc fue exitoso, asignamos el puntero temporal a la dirección original del array.
    direction = temp;

    //Asignamos los datos del nuevo libro al nuevo espacio en el array.

    //Mediante un puntero al libro de posición x, tomamos su ID y se la asignamos al nuevo libro, y repetimos con el resto de propiedades del libro.
    direction[booksQuantity].id = addId;
    strncpy(direction[booksQuantity].title, addTitle, MAX_CHARS_TITLE - 1);
    direction[booksQuantity].title[MAX_CHARS_TITLE - 1] = '\0';  //Aseguramos que el título esté bien terminado con '\0'.

    strncpy(direction[booksQuantity].author, addAuthor, MAX_CHARS_AUTHOR - 1);
    direction[booksQuantity].author[MAX_CHARS_AUTHOR - 1] = '\0';

    direction[booksQuantity].price = addPrice;  //Asignamos el precio del libro.
    direction[booksQuantity].typeGenre = (genre)addGender;  //Asignamos el género, convirtiendo el entero a tipo enum.
    direction[booksQuantity].stock = addQuantity;  //Asignamos el stock inicial del libro.

    //Incrementamos la cantidad total de libros en el catálogo.
    booksQuantity++;

    //Retornamos el puntero actualizado al array de libros.
    return direction;
}

Book* addNewBook(Book* data, int numNewBooks) {

    //Si la suma de stock que se quiere añadir es 0 o menor, o 1 o más letras, manda un mensaje de error y acaba.
    if (numNewBooks < 1) {
        printf("Invalid quantity.\n");
        return NULL;
    } else if(numNewBooks > 10) {
        printf("The maximum amount to add is 10 books.\n");
        return NULL;
    }

    //Reasignamos memoria para los libros existentes más los nuevos libros y calculamos el tamaño total necesario para todos los libros.
    Book* newData = (Book*)realloc(data, (booksQuantity + numNewBooks) * sizeof(Book));
    
    if (newData == NULL) {
        printf("Error: Couldn't reallocate memory.\n");
        free(data);  
        return NULL;  
    }

    //Actualizamos el puntero de los libros con la nueva memoria.
    data = newData;

    //Bucle para ingresar cada nuevo libro.
    for (int i = 0; i < numNewBooks; i++) {

        //Asignamos un ID único para cada nuevo libro, basado en la cantidad actual de libros.
        int newID = booksQuantity + i + 1;
        newData[booksQuantity + i].id = newID;

        //Solicitamos los detalles del libro al usuario.
        printf("\nEnter details for book %d:\n", newID);

        //Pedimos el título del libro y lo almacenamos en el array.
        printf("\tEnter the title: ");
        // while(getchar() != '\n');//Limpiamos el buffer de entrada antes de usar fgets.

        fgets(newData[booksQuantity + i].title, MAX_CHARS_TITLE, stdin);

        newData[booksQuantity + i].title[strcspn(newData[booksQuantity + i].title, "\n")] = '\0';  //Eliminamos el salto de línea.

        //Lo mismo con el autor que con el título
        printf("\tEnter the author: ");
        fgets(newData[booksQuantity + i].author, MAX_CHARS_AUTHOR, stdin);

        newData[booksQuantity + i].author[strcspn(newData[booksQuantity + i].author, "\n")] = '\0';  //Eliminamos el salto de línea.

        //Y lo mismo con el resto de propiedades
        printf("\tEnter the price: ");
        scanf("%f", &newData[booksQuantity + i].price);
        while(getchar() != '\n');//Limpiamos el buffer de entrada antes de usar fgets de nuevo.

        printf("\tEnter the genre (0: Fiction, 1: Non fiction, 2: Poetry, 3: Theater, 4: Essay): ");
        scanf("%d", (int*)&newData[booksQuantity + i].typeGenre);
        while(getchar() != '\n');

        printf("\tEnter the stock: ");
        scanf("%d", &newData[booksQuantity + i].stock);
        while(getchar() != '\n');
    }

    //Actualizamos la cantidad total de libros en el catálogo.
    booksQuantity += numNewBooks;

    //Confirmamos la adición exitosa y mostramos todos los libros del catálogo actualizado.
    printf("Successfully added %d new book(s).\nPrinting new books...\n\n", numNewBooks);
    showAll(data);

    //Devolvemos el puntero actualizado al array de libros.
    return data;
}

void deleteBook(Book* data, int id) {

    if (id < 1 || id > booksQuantity) {
        printf("Invalid ID.\n");
        return;
    }

    int index = -1;

    //Buscar el índice del libro con el ID especificado
    for (int i = 0; i < booksQuantity; i++) {
        if (data[i].id == id) {
            index = i;
            break;
        }
    }

    //Si no se encuentra el libro, da error
    if (index == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    //Desplazamos los elementos hacia la izquierda para eliminar el libro
    for (int i = index; i < booksQuantity - 1; i++) {

        //Copiamos el siguiente libro al índice actual
        data[i] = data[i + 1];
    }

    //Quitamos un libro
    booksQuantity--;

    //Reducimos el tamaño del array
    Book* temp = (Book*)realloc(data, sizeof(Book) * booksQuantity);

    if (temp == NULL && booksQuantity > 0) {
        printf("Memory reallocation failed after deletion.\n");
        return;
    }


    //Actualizamos el puntero al nuevo bloque de memoria
    data = temp;

    printf("Book with ID %d has been deleted successfully.\n", id);

    //Imprimimos el nuevo catálogo
    showAll(data);

    //Indicamos que el ID eliminado está disponible
    printf("Now ID %d is free to use.\n", id);  
}

const char* convertGenre(genre gen){    

    switch (gen) {
    case FICTION: return "Fiction";                     
    case NON_FICTION: return "Non fiction";
    case POETRY: return "Poetry";
    case THEATER: return "Theatre";
    case ESSAY: return "Essay";
    default: return "Unknown";
    }
}