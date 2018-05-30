#include <stdio.h>
#include <stdlib.h>

typedef struct proceso {
  char id;
  int turnos;
} proceso;

void print_cola(proceso *cola, int size) {
	printf("[");
	int i;
	for(i=0;i<size;i++) {
		printf("\"%c %d\"",cola[i].id, cola[i].turnos);
		if(i<size-1) printf(", ");
	}
	printf("]");
}

void swap_procesos(proceso *cola, int size) {
	proceso aux = cola[0];
	int i;
	for(i=0;i<size-1;i++) {
		cola[i] = cola[i+1];
	}
	cola[size-1] = aux;
}



/* main */

int main() {

	int n;

	printf("Numero de procesos:");
	scanf("%d",&n);
	
	proceso *cola = calloc(n, sizeof(proceso));
	
	int i;
	for(i=0;i<n;i++){
		proceso p;
		p.id = 'A' + i;
		printf("Proceso %c:",p.id);
		scanf("%d", &p.turnos);
		cola[i] = p;
	}
	
	printf("Estado inicial de la cola.\n");
	print_cola(cola, n);
	printf("\n");
	
	printf("Empezando Round Robin.\n");
	int turno = 1;
	int restantes = n;
	while(restantes>0){
		cola[0].turnos--;
		char id = cola[0].id;
		int turnos = cola[0].turnos;
		swap_procesos(cola, restantes);
		if(turnos == 0) {
			restantes--;
		}
		printf("Turno %3d - Proceso %c quedan %d: ",turno++, id, turnos);
		print_cola(cola, n);
		printf("\n");
	}
	
	return 0;
}
