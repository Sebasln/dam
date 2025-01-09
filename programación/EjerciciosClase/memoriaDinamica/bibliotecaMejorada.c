#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes para los tamaños máximos de título, autor y catálogo
#define MAX_CHARS_TITLE 80
#define MAX_CHARS_AUTHOR 43
#define MAX_CATALOG 40

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

// Inicialización del catálogo con 40 libros predefinidos
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

void showBook(const Book* books) {                     // Lo que hace es mostrar un libro.
    printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %s\n\tStock: %d\n",
               data[i].id, data[i].title, data[i].author, data[i].price, convertGenre(data->typeGenre), data[i].stock);
}

void mostrarTodosLosLibros() {                              //Lo que hace es un bucle que permite mostrar todos los libros llamando a la función mostrarLibros, ya que el bucle va desde el 0 hasta MAX_LIBROS que es 40 
    for (int i = 0; i < MAX_LIBROS; ++i) {
         if (libros[i].id != 0) {                   //ignora los libros eliminados
            showBook(&libros[i]);   
        }
    }
}

// Función para mostrar todos los libros en el catálogo
void showAll(const Book * data){
    printf("Here is the entire list of books: \n");
    for(int i = 0; i < MAX_CATALOG; i++){ 
       
    }
}

// Función para buscar un libro por ID
void searchBook(const Book * data, int id){
    if (id < 1 || id > MAX_CATALOG) {
        printf("Invalid ID.\n");
        return;
    }
    printf("Name: %s\nAuthor: %s\nId: %d\nPrice: %.2f\nGenre: %d\nStock: %d\n",
           data[id-1].title, data[id-1].author, data[id-1].id, data[id-1].price, data[id-1].typeGenre, data[id-1].stock);
}

// Función para agregar stock a un libro
void addStock(Book *data, int id, int sum){
    if (id < 1 || id > MAX_CATALOG) {
        printf("Invalid ID.\n");
        return;
    }
    data[id-1].stock += sum;
    printf("The stock for the book '%s' has been updated to %d units.\n", data[id-1].title, data[id-1].stock);
}

// Función para mostrar los libros de una categoría específica
void showCategory(const Book * data, genre gen){
    for(int i = 0; i < MAX_CATALOG; i++){
        if (data[i].typeGenre == gen){
            printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %.2f\n\tGenre: %i\n\tStock: %d\n",
                   data[i].id, data[i].title, data[i].author, data[i].price, data[i].typeGenre, data[i].stock);
        }
    }
}

// Función para mostrar los libros de un autor específico
void displayByAuthor(const Book * data, const char *author){
    for(int i = 0; i < MAX_CATALOG; i++){
        if (strcmp(data[i].author, author) == 0){
            printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %.2f\n\tGenre: %i\n\tStock: %d\n",
                   data[i].id, data[i].title, data[i].author, data[i].price, data[i].typeGenre, data[i].stock);
        }
    }
}

// Función principal para procesar los comandos ingresados por la línea de comandos
int main(int argc, char **argv){
    if (argc < 2) {
        printf("Type in ./biblioteca [command] [arguments]\n");
        return 0;
    }

    // Comando para mostrar todos los libros o buscar un libro por ID
    if (strcmp(argv[1], "mostrar") == 0) {
        if (argc == 2) {
            showAll(books);
        } else if (argc == 3) {
            int id = atoi(argv[2]);
            searchBook(books, id);
        }
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
    else if (strcmp(argv[1], "categoria") == 0) {
        if (argc == 3) {
            int gen = atoi(argv[2]);
            showCategory(books, (genre)gen);
        } else {
            printf("Usage: ./biblioteca categoria [genre_id]\n");
        }
    } 
    // Comando para mostrar los libros de un autor específico
    else if (strcmp(argv[1], "autor") == 0) {
        if (argc == 3) {
            displayByAuthor(books, argv[2]);
        } else {
            printf("Usage: ./biblioteca autor [author_name]\n");
        }
    }
    // Si el comando no es reconocido
    else {
        printf("Unknown command.\n");
    }

    return 0;
}