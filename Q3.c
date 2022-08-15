#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int tamanho(struct lista *p){	

	if (p != NULL){
		return 1+tamanho(p->prox);
	}
	else return 0;
}