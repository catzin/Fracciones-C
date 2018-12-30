#include<stdio.h>
#include"fracs.h"

int main(void){
  int opcion = 0;
	int respuesta = 0;

	printf("PROGRAMA DE OPERACIONES CON FRACCIONES\n");
	printf("Entrada, 2 fracciones: entero, numerador , denominador. Si no existe parte entera ingresar 0\n");
	printf("\n");
	menu();
	printf("\n");
	opcion = lee_opcion();
	ejecuta_opcion(opcion);
	printf("¿Deseas realizar otra operación?\n");
	printf("1.Si\n");
	printf("2.No\n");
	scanf("%d",&respuesta);
	if(respuesta != 2){
		menu();
		opcion = lee_opcion();
		ejecuta_opcion(opcion);
	}
	else{

		printf("Gracias por participar \n");
	}
	return 0;
}
