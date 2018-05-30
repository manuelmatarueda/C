#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

/* Definicion de la lista simple : START */

typedef struct node {
	void *data;
	struct node *next;
} node;

void add_first(node **head_ref, void *data, size_t data_size) {
	
	node *new_node = (node *) malloc(sizeof(node));/* nuevo nodo */
	new_node->data = malloc(data_size);/* espacio para el dato */
	new_node->next = *head_ref;
	
	int i;
	for(i=0;i<data_size;i++) *(char *)(new_node->data+i) = *(char *)(data+i);
	
	(*head_ref) = new_node;
}

void remove_first(node **head_ref) {
	if(*head_ref!=NULL){
		node *aux = *head_ref;
		(*head_ref) = (*head_ref)->next;
		free(aux);
	}
}

void print_list(node *head, void (* fptr)(void *)) {
	printf("[");
	node *aux = head;
	while(aux!=NULL) {
		(*fptr)(aux->data);
		aux=aux->next;
		if(aux!=NULL) printf(", ");
	}
	printf("]\n");
}

/* Definicion de la lista simple : END */

/* funciones para imprimir tipo basicos */
void print_int(void *i) {
	printf("%d", *(int *)i);
}


/* main */
int main() {
	
	/* lista de int */
	node *head_int=NULL;
	int i;
	i=23;
	add_first(&head_int, &i, sizeof(int));
	i=12;
	add_first(&head_int, &i, sizeof(int));
	i=15;
	add_first(&head_int, &i, sizeof(int));
	i=89;
	add_first(&head_int, &i, sizeof(int));
	i=73;
	add_first(&head_int, &i, sizeof(int));
	
	print_list(head_int, print_int);
	remove_first(&head_int);
	remove_first(&head_int);
	print_list(head_int, print_int);
	remove_first(&head_int);
	remove_first(&head_int);
	remove_first(&head_int);
	/* Aqui la lista ya esta vacia y vemos que no peta */
	remove_first(&head_int);
	print_list(head_int, print_int);
	
	/* lista de persona */
	node *head_persona = NULL;
	persona *p = (persona *) malloc(sizeof(persona));
	p->nombre="Manuel Mata";
	p->telefono=615311707;
	add_first(&head_persona,p,sizeof(persona));
	
	p = (persona *) malloc(sizeof(persona));
	p->nombre="Mercedes Garcia";
	p->telefono=955807653;
	add_first(&head_persona,p,sizeof(persona));
	
	persona pp; /* variable en lugar de puntero */
	pp.nombre = "Julian Abad";
	pp.telefono = 608976502;
	add_first(&head_persona,&pp,sizeof(persona));

	print_list(head_persona, print_persona);
	remove_first(&head_persona);
	print_list(head_persona, print_persona);
	remove_first(&head_persona);
	remove_first(&head_persona);
	/* lista vacia */
	print_list(head_persona, print_persona);

	return 0;
}
