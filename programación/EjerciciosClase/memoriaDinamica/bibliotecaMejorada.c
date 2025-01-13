#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes para los tamaños máximos de título y autor
#define MAX_CHARS_TITLE 80
#define MAX_CHARS_AUTHOR 43

int books_quantity = 0;  // Número de libros en el catálogo

// Enum para representar los géneros de los libros
typedef enum{
    FICTION,
    NON_FICTION,
    POETRY,
    THEATER,
    ESSAY
} genre;

// Estructura para representar un libro
typedef struct{
    int id;                  // ID único del libro
    char title[MAX_CHARS_TITLE];  // Título del libro
    char author[MAX_CHARS_AUTHOR]; // Autor del libro
    float price;             // Precio del libro
    genre typeGenre;        // Género del libro (Ficción, No ficción, Poesía, Teatro, Ensayo)
    int stock;              // Cantidad disponible en stock
} Book;



const char* convertGenre(genre gen) {    

    switch (gen) {
    case FICTION: return "Fiction";                     
    case NON_FICTION: return "Non fiction";
    case POETRY: return "Poetry";
    case THEATER: return "Theatre";
    case ESSAY: return "Essay";
    default: return "Unknown";
    }
}

void showBook(const Book* data) {       // Lo que hace es mostrar un libro.
    printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %s\n\tStock: %d\n",
     data->id, data->title, data->author, data->price, convertGenre(data->typeGenre), data->stock);
}

// Función para mostrar todos los libros en el catálogo
void showAll(const Book* data) { 
    printf("Here is the entire list of books: \n");

    for (int i = 0; i < books_quantity; ++i) {
         if (data[i].id != 0) {                   //ignora los libros eliminados
            showBook(&data[i]);   
        }
    }
}


// Función para buscar un libro por ID
void searchBook(const Book * data, int id){
    if (id < 1 || id > books_quantity) {
        printf("Invalid ID.\n");
        return;
    }
    printf("Name: %s\nAuthor: %s\nId: %d\nPrice: %.2f\nGenre: %d\nStock: %d\n",
     data[id-1].title, data[id-1].author, data[id-1].id, data[id-1].price, data[id-1].typeGenre, data[id-1].stock);
}

// Función para agregar stock a un libro
void addStock(Book *data, int id, int sum){
    if (id < 1 || id > books_quantity) {
        printf("Invalid ID.\n");
        return;
    }
    data[id-1].stock += sum;
    printf("The stock for the book '%s' has been updated to %d units.\n", data[id-1].title, data[id-1].stock);
}

// Función para mostrar los libros de una categoría específica
void showCategory(const Book * data, genre gen){
    for(int i = 0; i < books_quantity; i++){
        if (data[i].typeGenre == gen){
            printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %.2f\n\tGenre: %i\n\tStock: %d\n",
             data[i].id, data[i].title, data[i].author, data[i].price, data[i].typeGenre, data[i].stock);
        }
    }
}

// Función para mostrar los libros de un autor específico
void displayByAuthor(const Book * data, const char *author){
    for(int i = 0; i < books_quantity; i++){
        if (strcmp(data[i].author, author) == 0){
            printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %.2f\n\tGenre: %i\n\tStock: %d\n",
             data[i].id, data[i].title, data[i].author, data[i].price, data[i].typeGenre, data[i].stock);
        }
    }
}


Book* addBook(Book* direction, int add_id, const char* add_title, const char* add_author, float add_price, int add_gender, int add_quantity) {
    Book* temp = (Book*)realloc(direction, sizeof(Book) * (books_quantity + 1));
    if (temp == NULL) {
        printf("Error: Couldn't reallocate memory.\n");
        free(direction);
        return NULL;
    }
    direction = temp;

    direction[books_quantity].id = add_id;
    strncpy(direction[books_quantity].title, add_title, MAX_CHARS_TITLE - 1);
    direction[books_quantity].title[MAX_CHARS_TITLE - 1] = '\0';

    strncpy(direction[books_quantity].author, add_author, MAX_CHARS_AUTHOR - 1);
    direction[books_quantity].author[MAX_CHARS_AUTHOR - 1] = '\0';

    direction[books_quantity].price = add_price;
    direction[books_quantity].typeGenre = (genre)add_gender;
    direction[books_quantity].stock = add_quantity;

    books_quantity++;
    return direction;
}

void addNewBook(Book* data, int numNewBooks) {
    // Reasignar memoria para los libros existentes más los nuevos libros
    Book* newData = (Book*)realloc(data, (books_quantity + numNewBooks) * sizeof(Book));
    if (newData == NULL) {
        printf("Error: Couldn't reallocate memory.\n");
        free(data);
        return;
    }

    data = newData;

    printf("Adding %d new books...\n", numNewBooks);

    // Agregar libros
    for (int i = 0; i < numNewBooks; i++) {
        // Asignar ID único para el nuevo libro
        int newID = books_quantity + i + 1;
        newData[books_quantity + i].id = newID;

        // Pedir datos para el nuevo libro
        printf("\nEnter details for book %d:\n", newID);

        // Ingresar el título
        printf("\tEnter the title: ");
        getchar();  // Limpiar el buffer antes de usar scanf
        fgets(newData[books_quantity + i].title, MAX_CHARS_TITLE, stdin);
        // Eliminar el salto de línea al final del título
        newData[books_quantity + i].title[strcspn(newData[books_quantity + i].title, "\n")] = '\0';

        // Ingresar el autor
        printf("\tEnter the author: ");
        fgets(newData[books_quantity + i].author, MAX_CHARS_AUTHOR, stdin);
        // Eliminar el salto de línea al final del autor
        newData[books_quantity + i].author[strcspn(newData[books_quantity + i].author, "\n")] = '\0';

        // Ingresar el precio
        printf("\tEnter the price: ");
        scanf("%f", &newData[books_quantity + i].price);

        // Ingresar el género
        printf("\tEnter the genre (0: Fiction, 1: Non fiction, 2: Poetry, 3: Theater, 4: Essay): ");
        scanf("%d", (int*)&newData[books_quantity + i].typeGenre);

        // Ingresar el stock
        printf("\tEnter the stock: ");
        scanf("%d", &newData[books_quantity + i].stock);
    }

    // Actualizar la cantidad total de libros
    books_quantity += numNewBooks;

    printf("Successfully added %d new book(s).\nPrinting new books...\n\n", numNewBooks);

    showAll(newData);
}

void deleteBook(Book* data, int id) {
    if (id < 1 || id > books_quantity) {
        printf("Invalid ID.\n");
        return;
    }

    int index = -1;

    // Buscar el índice del libro con el ID especificado
    for (int i = 0; i < books_quantity; i++) {
        if (data[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    // Desplazar los elementos hacia la izquierda para eliminar el libro
    for (int i = index; i < books_quantity - 1; i++) {
        data[i] = data[i + 1];
    }

    books_quantity--;

    // Reducir el tamaño del arreglo
    Book* temp = (Book*)realloc(data, sizeof(Book) * books_quantity);
    if (temp == NULL && books_quantity > 0) {
        printf("Memory reallocation failed after deletion.\n");
        return;
    }

    data = temp;

    printf("Book with ID %d has been deleted successfully.\n", id);

    showAll(data);

    printf("Now ID %d is free to use.\n", id);
}

// Función principal para procesar los comandos ingresados por la línea de comandos
int main(int argc, char **argv){

    Book* books = (Book*)malloc(sizeof(Book));  // Inicializamos el catálogo con espacio para un libro
    if (books == NULL) {
        printf("Error: No se pudo asignar memoria inicial.\n");
        return 1;
    }

    // Inicialización del catálogo con 40 libros predefinidos
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
        printf("Type in ./biblioteca [command] [arguments]\n");
        return 0;
    }

    // Comando para mostrar todos los libros o buscar un libro por ID
    if (strcmp(argv[1], "show") == 0) {
        if (argc == 2) {
            showAll(books);
        } else if (argc == 3) {
            int id = atoi(argv[2]);
            searchBook(books, id);
        }
    }
    else if (strcmp(argv[1], "add") == 0){
        addNewBook(books, atoi(argv[2]));
    }
    // Comando para agregar stock a un libro
    else if (strcmp(argv[1], "stock") == 0) {
        if (argc == 4) {
            int id = atoi(argv[2]);
            int cantidad = atoi(argv[3]);
            addStock(books, id, cantidad);
        } else {
            printf("Usage: ./biblioteca stock [ID] [Quantity]\n");
        }
    }
    // Comando para mostrar los libros de una categoría específica
    else if (strcmp(argv[1], "category") == 0) {
        if (argc == 3) {
            int gen = atoi(argv[2]);
            showCategory(books, (genre)gen);
        } else {
            printf("Usage: ./biblioteca category [genre_id]\n");
        }
    } 
    // Comando para mostrar los libros de un autor específico
    else if (strcmp(argv[1], "author") == 0) {
        if (argc == 3) {
            displayByAuthor(books, argv[2]);
        } else {
            printf("Usage: ./biblioteca author '[author_name]'\n");
        }
    } else if(strcmp(argv[1], "delete") == 0){
        if(argc == 3){
        int id = atoi(argv[2]);
        deleteBook(books, id);
        } else {
            printf("Usage: ./biblioteca delete [ID]\n");
        }

    } 
    // Si el comando no es reconocido
    else {
        printf("Unknown command.\n");
    }

    return 0;
}