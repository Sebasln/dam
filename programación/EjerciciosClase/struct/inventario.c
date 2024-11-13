#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 100

typedef struct{
	char nombre[50];
	char direccion[50];
	char telefono[50];
} Proveedor;

typedef struct{
	char nombre[50];
	float precio;
	Proveedor proveedor;
} Articulo;

typedef struct{
	Articulo articulos[MAX_ITEMS];
	int cantidades[MAX_ITEMS];
	int totalArticulos;
} Inventario;

int main(){
	Inventario miInventario;
	Articulo articulo = {"Nombre", 10, {"NomPro", "DirPro", "telPro"}};

	miInventario.articulos[0] = articulo;
	miInventario.cantidades[0] = 10;
	
	printf("Nombre artículo: %s\n", 
			miInventario.articulos[0].nombre
			);

	printf("Cantidad: %d\n",
			miInventario.cantidades[0]
			);

	printf("Nombre del proveedor: %s\n",
		       miInventario.articulos[0].proveedor.nombre
		       );

	return 0;
}
