#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

/* definicion de la lista : START */

typedef struct node {
	void *data;
	struct node *previous;
	struct node *next;
} node;

node *create_node(void *data, size_t data_size) {
	/* creamos el nuevo nodo */
	node *n = (node *) malloc(sizeof(node));
	n->data = malloc(data_size);
	n->next = NULL;
	n->previous = NULL;
	
	/* copiamos el contenido de data */
	int i;
	for(i=0;i<data_size;i++) *(char *)(n->data+i) = *(char *)(data+i);
	
	return n;
}

typedef struct list {
	int size;
	node *first;
	node *last;
} list;

list *create_list() {
	list *l = (list *) malloc(sizeof(list));
	l->size = 0;
	l->first = NULL;
	l->last = NULL;
}

void add_first(list **list_ref, void* data, size_t data_size){
	/* creamos el nuevo nodo */
	node *n = create_node(data, data_size);
	
	/* metemos el elemento en la lista */
	if((*list_ref)->size == 0) {
		(*list_ref)->first = n;
		(*list_ref)->last = n;
		
	} else {
		n->next = (*list_ref)->first;
		(*list_ref)->first->previous = n;
		(*list_ref)->first = n;
	}
	printf("n: %d %p\n", *(int *)n->data, n);
	printf("l->first: %d %p %p %p\n", *(int *)(*list_ref)->first->data, (*list_ref)->first, (*list_ref)->first->next, (*list_ref)->first->previous);
	printf("l->last:  %d %p %p %p\n", *(int *)(*list_ref)->last->data, (*list_ref)->last, (*list_ref)->last->previous, (*list_ref)->last->next);

	/* incrementamos el contador de la lista */	
	(*list_ref)->size++;
}

void add_last(list **list_ref, void* data, size_t data_size){
	/* creamos el nuevo nodo */
	node *n = create_node(data, data_size);
	
	/* metemos el elemento en la lista */
	if((*list_ref)->size == 0) {
		(*list_ref)->first = n;
		(*list_ref)->last = n;
	} else {
		n->previous = (*list_ref)->last;
		(*list_ref)->last->next = n;
		(*list_ref)->last = n;
	}

	/* incrementamos el contador de la lista */	
	(*list_ref)->size++;
}

node *get_first(list *l) {
	return l->first;
}

node *get_last(list *l) {
	return l->last;
}

void print_list_forward(list *l, void (*fptr)(void *)) {
	if(l==NULL) return;
	
	printf("size: %d [", l->size);
	node *aux;
	aux = l->first;
	while(aux!=NULL) {
		(*fptr)(aux->data);
		aux=aux->next;
		if(aux!=NULL) printf(", ");
	}
	printf("]\n");
}

void print_list_backward(list *l, void (*fptr)(void *)) {
	if(l==NULL) return;
	
	printf("size: %d [", l->size);
	node *aux;
	aux = l->last;
	while(aux!=NULL) {
		(*fptr)(aux->data);
		aux=aux->previous;
		if(aux!=NULL) printf(", ");
	}
	printf("]\n");
}

/* definicion de la lista : END */

/* funciones de impresion de tipos basicos */
void print_int(void *i) {
	printf("%d",*(int *)i);
}



/* main */

int main() {
	
	/*
	
	lista de int
	
	*/
	printf(" *** Lista de enteros ***\n");
	list *list_int = NULL;
	
	/* esto no pinta nada */
	print_list_forward(list_int, print_int);
	print_list_backward(list_int, print_int);

	/* esto pinta la lista vacia dos veces */
	list_int = create_list();
	print_list_forward(list_int, print_int);
	print_list_backward(list_int, print_int);
	
	int i;
	i=12;
	add_first(&list_int, &i, sizeof(int));
	i=34;
	add_first(&list_int, &i, sizeof(int));
	i=56;
	add_first(&list_int, &i, sizeof(int));
	i=78;
	add_first(&list_int, &i, sizeof(int));
	
	/*
	i=90;
	add_last(&list_int, &i, sizeof(int));
	i=101;
	add_last(&list_int, &i, sizeof(int));
	*/

	print_list_forward(list_int, print_int);
	print_list_backward(list_int, print_int);
	
	/* */
	node *n = NULL;
	n = get_first(list_int);
	printf("first: %d\n",*(int *)n->data);
	n = get_last(list_int);
	printf("last: %d\n",*(int *)n->data);
	
	
	
	/* 
	
	lista de persona
	
	printf(" *** Lista de persona ***\n");
	list *list_persona = NULL;
	
	print_list_forward(list_persona, print_persona);
	print_list_backward(list_persona, print_persona);

	list_persona = create_list();
	print_list_forward(list_persona, print_persona);
	print_list_backward(list_persona, print_persona);
	
	persona p;
	p = create_persona("Manuel Mata", 615311707);
	add_first(&list_persona, &p, sizeof(persona));
	p = create_persona("Jose Fernandez", 955800776);
	add_first(&list_persona, &p, sizeof(persona));
	p = create_persona("Rocio Abad", 910346792);
	add_first(&list_persona, &p, sizeof(persona));
	
	print_list_forward(list_persona, print_persona);
	print_list_backward(list_persona, print_persona);
	*/
	
	return 0;
}
