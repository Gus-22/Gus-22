/******************************************************************************

lista.c


Implementa um exemplo de Lista Encadeada com alocação dinâmica de memória.
Autor: Leonardo R. Emmendorfer
Data: 24/06/2022

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lista{
    int valor;
    struct lista * prox;
};


struct lista *inicializa_lista()
{
    return (struct lista*) NULL;
}

void insere_item_inicio(struct lista **L,int item)
{
    struct lista *novo;
    
    novo=(struct lista *) malloc(sizeof(struct lista));
    novo->valor=item;
    novo->prox= (*L);
    (*L)=novo;
}


int remove_item(struct lista **L, int item)
{
    struct lista *aux;
    if ((*L)==NULL)
        return 0;
    if ((*L)->valor==item)
    {
        aux=(*L);
        (*L)=(*L)->prox;
        free(aux);
        return 1;
    }
    else
       remove_item(&((*L)->prox),item);    
}

void mostra_lista(struct lista *L)
{   if (L!=NULL)
    {
      printf("%d\n",L->valor);
      mostra_lista(L->prox);
    }
}

int main()
{
    struct lista *l1;
    l1=inicializa_lista();
    insere_item_inicio(&l1,10);
    insere_item_inicio(&l1,20);
    insere_item_inicio(&l1,30);
    insere_item_inicio(&l1,40);
    if (remove_item(&l1,20)) 
        printf ("Removido item de valor 20.\n");
    else 
        printf ("Item 20 não encontrado.\n");
    printf("\n Lista final:\n");
    mostra_lista(l1);  
}

