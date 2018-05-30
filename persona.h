#include <stdio.h>

#ifndef PERSONA_H
#define PERSONA_H

typedef struct persona {
	char *nombre;
	int telefono;
} persona;

void print_persona(void *p) {
	printf("\"%s %d\"", ((persona *)p)->nombre, ((persona *)p)->telefono);
}

persona create_persona(char *nombre, int telefono) {
	persona p;
	p.nombre = nombre,
	p.telefono = telefono;
	
	return p;
}


#endif




