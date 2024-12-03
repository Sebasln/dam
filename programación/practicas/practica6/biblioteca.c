#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 200
#define MAX_CHARS_TITLE 80
#define MAX_CHARS_AUTHOR 43
#define MAX_CATALOG 40


typedef enum{
	FICTION,
	NON_FICTION,
	POETRY,
	THEATER,
	ESSAY
} genre;

typedef struct{
	int id;
	char title[MAX_CHARS_TITLE];
	char author[MAX_CHARS_AUTHOR];
	float price;
	genre typeGenre;
	int stock;

} Book;

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


void searchBook(Book * data, char * retVal){
	int search;

	printf("Enter an id(1-40): \n");
	scanf("%d", &search);

	for (int i = 0; i < MAX_CATALOG; ++i){	
			
		if(search == i + 1 ){
			snprintf(retVal, MAX_BUFFER*sizeof(char), "Name: %s\nAuthor: %s\nId: %d\nPrice: %f\nGenre: %d\nStock: %d\n",data[i].title ,data[i].author ,data[i].id ,data[i].price ,data[i].typeGenre ,data[i].stock );
			return;
		}
	}
		printf("Enter a valid number.\n");
}


void showAll(Book * data, char * retVal){

	printf("Here is the entire list of books: \n");

	for(int i = 0; i < MAX_CATALOG; i++){
            printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %i\n\tStock: %d\n",data[i].id,data[i].title,data[i].author,data[i].price,data[i].typeGenre,data[i].stock);
        }
}

void newBook(Book * data, char * retVal){
	char input;

	printf("Do you want to add stock to a book? (y/n) ");

	for(int i = 0; i < MAX_CATALOG; i++){

	printf("Do you want to add stock to a book? (y/n) ");

	if(input == 'n'){
		return;
	} else if(input != 'y'){
		printf("Enter a valid argument.\n");
		continue;
	}

	int search, sum;

	printf("Which book do you want to add stock to? Write its ID\n");
	scanf("%d", &search);



	if (search < 0 || search > MAX_CATALOG){
		printf("There are no books with ID %d.\n", search);
		continue;
	}

	printf("How many units do you want to add from stock?");
	scanf("%d", &sum);

	data[search - 1].stock += sum;

	printf("The stock from the book %s has been reestablished in %d units.\n", data[search - 1].title, data[search - 1].stock);
	}
}

// void displayCategory(Book * data, input){
// 	for(int i = 0; i < MAX_CATALOG; i++){

//             printf("ID %i\n\tTitle: %s\n\tAuthor: %s\n\tPrice: %0.2f\n\tGenre: %i\n\tStock: %d\n",data[i].id,data[i].title,data[i].author,data[i].price,data[i].typeGenre,data[i].stock);
//             return;
//         }
// }

void showCategory(Book * data, char * retVal){
	int input;

	printf("Enter a number to display all books from the same category(1: FICTION, 2: NON_FICTION, 3: POETRY, 4: THEATER, 5: ESSAY) ");

	// displayCategory(data, input);

	printf("Enter a valid number.\n");
}




int main(){
	char stringBookList[MAX_BUFFER];

	showAll(books, stringBookList);
	printf("%s", stringBookList);

	char stringResult[MAX_BUFFER];

	searchBook(books, stringResult);
	printf("%s", stringResult);

	char stringNewBook[MAX_BUFFER];

	newBook(books, stringNewBook);
	printf("%s", stringNewBook);



	return 0;
}