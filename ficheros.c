#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	FILE *f;
	f = fopen("bolas.c","r");
	if(f==NULL) {
		puts("Error abriendo el fichero.\n");
		exit(1);
	}
	
	char c;
	do {
		c = fgetc(f);
		printf("%c", c);
	} while (c!=EOF);
	
	
	
	if(fclose(f)!=0) {
		puts("Error cerrando el fichero.\n");
	}
	
	
	exit(0);
}
