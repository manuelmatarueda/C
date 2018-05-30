#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

/* Definición del binary tree : START */

typedef struct node {
  void *data;
  struct node *left;
  struct node *right;
} node;

/* crea un nodo */
node *create(void *data, size_t data_size){
	node *n = (node*) malloc(sizeof(node));
	
	n->data = malloc(data_size);
	n->left = NULL;
	n->right = NULL;
	
	/* copia el contenido de *data en la memoria reservada para este */
	int i;
    for (i=0; i<data_size; i++)
        *(char *)(n->data + i) = *(char *)(data + i);
	
	return n;
}

void in_order(node *root, void (*fptr)(void *)) {
	if(root!=NULL) {
		(*fptr)(root->data);/* Llama a la funcion pasada como parametro */
		printf(" ");
		in_order(root->left, fptr);
		in_order(root->right, fptr);
	}
}

void pre_order(node *root, void (*fptr)(void *)) {
	if(root!=NULL) {
		pre_order(root->left, fptr);
		(*fptr)(root->data);/* Llama a la funcion pasada como parametro */
		printf(" ");
		pre_order(root->right, fptr);
	}
}

void post_order(node *root, void (*fptr)(void *)) {
	if(root!=NULL) {
		post_order(root->left, fptr);
		post_order(root->right, fptr);
		(*fptr)(root->data);/* Llama a la funcion pasada como parametro */
		printf(" ");
	}
}

/* Definición del binary tree : END */


/* Funciones de impresion para tipos genericos */

void print_int(void *i) {
	printf("%d", *(int *)i);
}

void print_float(void *f) {
	printf("%f", *(float *)f);
}




/* main */

int main() {
	
	/* Binary tree de int */
	
	int i;
	i=22;
	node *root_int = create(&i, sizeof(int));
	
	i=14;
	root_int->left = create(&i, sizeof(int));
	
	i=8;
	root_int->left->left = create(&i, sizeof(int));
	
	i=17;
	root_int->left->right = create(&i, sizeof(int));
	
	i=34;
	root_int->right = create(&i, sizeof(int));
	
	in_order(root_int, print_int);
	printf("\n");
	pre_order(root_int, print_int);
	printf("\n");
	post_order(root_int, print_int);
	printf("\n");
	
	/* Binary tree de float */
	
	float f = 70.23;
	node *root_float = create(&f, sizeof(float));
	
	f = 27.04;
	root_float->left = create(&f, sizeof(float));
	
	f = 3.1421;
	root_float->right = create(&f, sizeof(float));
	
	f = 0.78;
	root_float->right->right = create(&f, sizeof(float));
	
	in_order(root_float, print_float);
	printf("\n");
	pre_order(root_float, print_float);
	printf("\n");
	post_order(root_float, print_float);
	printf("\n");
	
	/* Binary tree de persona */
	
	persona *p = (persona*) malloc(sizeof(persona));
	p->nombre = "Manuel Mata";
	p->telefono = 615311707;
	node *root_persona = create(p, sizeof(persona));
	
	p = (persona *) malloc(sizeof(persona));
	p->nombre = "Juan Perez";
	p->telefono = 609789881;
	root_persona->left = create(p, sizeof(persona));
	
	p = (persona *) malloc(sizeof(persona));
	p->nombre = "Mercedes Garcia";
	p->telefono = 955805674;
	root_persona->right = create(p, sizeof(persona));
	
	in_order(root_persona, print_persona);
	printf("\n");
	pre_order(root_persona, print_persona);
	printf("\n");
	post_order(root_persona, print_persona);
	printf("\n");
	
	return 0;
}
