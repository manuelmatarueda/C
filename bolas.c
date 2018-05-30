#include <stdio.h>
#include <stdlib.h>

unsigned const int BOLAS = 5;
unsigned const int TEMAS_TOTALES = 65;
unsigned const int TEMAS_ESTUDIADOS = 10;
unsigned const int SIMULACIONES = 1000000;
time_t t;

void init() {
    /* Intializes random number generator */
    srand((unsigned) time(&t));
}

/* Devuelve el valor si el elemento ya existe en el array, 0 en caso contrario */
int existeEnArray(int array[], int size, int valor) {
	int i;
	for(i=0;i<size;i++){
		if(array[i]==valor){
			return valor;
		}
	}
	return 0;
}

void imprimeArray(int array[], int size, char *s) {
	printf(s);
	int i;
	for(i=0;i<size;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void cargaArray(int array[], int size, int total) {
	int n=0;
	do {
		int valor=rand() % total + 1;
		if(!existeEnArray(array, size, valor)){
			array[n++]=valor;
			/*printf("Valor:%d\n",valor);*/
		} else {
			/*printf("Ya existe el valor %d\n", valor);*/
		}
	} while(n<size);
}

int exito(int bolas[], int size_bolas, int temas_estudiados[], int size_temas_estudiados) {
	int i;
	for(i=0; i<size_bolas; i++){
		int bola = existeEnArray(temas_estudiados, size_temas_estudiados, bolas[i]);
		if(bola){
			/* Devolvemos el tema que ha sido exito */
			return bola;
		}
	}
	return 0;
}

/* main */

int main() {
	
	int exitos=0;
	int bolas[BOLAS];
    int temas_estudiados[TEMAS_ESTUDIADOS];

	init();
	cargaArray(temas_estudiados, TEMAS_ESTUDIADOS, TEMAS_TOTALES);
	
	printf("Simulaciones totales:%d\n",SIMULACIONES);
	int i;
	for(i=0;i<SIMULACIONES;i++) {
		/*printf("\nSimulacion:%d de %d\n",i+1, SIMULACIONES);*/

		/* Bolas */
		/*printf("Cargando el array de bolas.\n");*/
		cargaArray(bolas, BOLAS, TEMAS_TOTALES);
		
	
	    /* Temas estudiados */
	    /*printf("Cargando el array de temas estudiados.\n");*/
		
		int tema = exito(bolas, BOLAS, temas_estudiados, TEMAS_ESTUDIADOS);
		if(tema) {
			/*imprimeArray(bolas, BOLAS, "Bolas:");
			imprimeArray(temas_estudiados, TEMAS_ESTUDIADOS, "Temas estudiados:");
			printf("Exito en tema:%d\n",tema);*/
			exitos++;
		}
		
	}
	
	printf("Exitos:%d (%2.2f%%)",exitos,((double)exitos/(double)SIMULACIONES)*100);
	
	exit(0);
}
