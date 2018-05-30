#include <stdio.h>
#include <stdlib.h>

/* definicion de la sorted list : START */

typedef struct node {
	int data;
	struct node *next;
} node;

node *create_node(int data) {
	node *n = (node *) malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	
	return n;
}

typedef struct sorted_list {
	int size;
	node *head;
} sorted_list;

sorted_list *create_sorted_list() {
	sorted_list *sl = (sorted_list *) malloc(sizeof(sorted_list));
	sl->size = 0;
	sl->head = NULL;
	
	return sl;
}

void add(sorted_list **sorted_list_ref, int data) {
	node *n = create_node(data);
	
	if((*sorted_list_ref)->size == 0 || (*sorted_list_ref)->head->data > data) {
		n->next = (*sorted_list_ref)->head;
		(*sorted_list_ref)->head = n;	
	} else {
		node *aux = (*sorted_list_ref)->head;
		while(aux->next!=NULL && aux->next->data < data) {
			aux = aux->next;
		}
		n->next = aux->next;
		aux->next = n;
	}

	(*sorted_list_ref)->size++;
}

void print_list(sorted_list *sl) {
	if(sl == NULL) return;
	
	node *aux = sl->head;
	printf("size: %d [", sl->size);
	while(aux!=NULL) {
		printf("%d",aux->data);
		aux=aux->next;
		if(aux!=NULL) printf(", ");
	}
	printf("]\n");
}



/* definicion de la sorted list : END */

void print_int(void *i) {
	printf("%d", *(int *)i);
}


/* main */

int main() {
	
	sorted_list *sl = NULL;
	print_list(sl);
	
	sl = create_sorted_list();
	print_list(sl);
	
	int i;
	i = 5;
	add(&sl, i);
	print_list(sl);
	
	i = 3;
	add(&sl, i);
	print_list(sl);
	i = 9;
	add(&sl, i);
	print_list(sl);
	i = 1;
	add(&sl, i);
	print_list(sl);
	i = 7;
	add(&sl, i);
	print_list(sl);
	
	return 0;
}
