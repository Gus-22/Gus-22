/******************************************************************************

grafo.c


Implementa um exemplo de manipulação de grafos
Autor: Leonardo R. Emmendorfer
Data: 21/07/2022

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct no{
    char nome[30];
    struct no *prox;
	struct filho *filhos;
};

struct filho{
	struct no *no_filho;
	struct filho *prox_filho;
};



struct no *inicializa_grafo()
{
    return (struct no*) NULL;
}

struct no *busca_no(char * nome_no,struct no *G)
{
	if (G==NULL)
		return NULL;
	else if (strcmp(G->nome,nome_no)==0)  /* encontrou o nome procurado */
		return(G);     /* devolve o endereço do no correspondente ao nome encontrado */
	else
		return(busca_no(nome_no,G->prox));	
}

void insere_no(struct no **G,char * nome_no)
{
    struct no *novo;
    novo=(struct no *) malloc(sizeof(struct no));
	strcpy(novo->nome,nome_no);
	novo->prox= (*G);
	novo->filhos=(struct filho *) NULL;  /* nenhuma aresta sai do novo nó   */
	(*G)=novo;	
}


void insere_link(char * nome_pai, char * nome_filho, struct no **G)
{
    struct no *pont_pai, *pont_filho;
	struct filho *F,*aux;
    pont_pai=busca_no(nome_pai,*G);
	pont_filho=busca_no(nome_filho,*G);
	
	if (pont_pai!= NULL && pont_filho!= NULL && pont_filho!= pont_pai)
	{	
		F= (struct filho *) malloc(sizeof(struct filho));
		F->no_filho=pont_filho;
		F->prox_filho = pont_pai->filhos;
		pont_pai->filhos=F;   /* inclui na lista de filhos */
	}	
}


void mostra_nos(struct no *G)
{   if (G!=NULL)
    {
      printf("%s\n",G->nome);
      mostra_nos(G->prox);
    }
}


void mostra_filhos_lista(struct filho *F)
{   if (F!=NULL)
    {
      printf("%s\n",F->no_filho->nome);
      mostra_filhos_lista(F->prox_filho);
    }
}

void mostra_filhos(char *nome, struct no *G)
{
    struct no *pont_pai;
    pont_pai=busca_no(nome,G);
    mostra_filhos_lista(pont_pai->filhos);    
}

int caminho(struct no *P,struct no *D, struct no *G)
{
    struct filho *F;
    if (P==D)    /*  Se o nó atual (P) corresponde ao nó de destino (D) */
    {
        printf("\n  CAMINHO ENCONTRADO: ");
        return 1;
    }   
    else if (P!=NULL)
    {
        F=P->filhos;
        while (F!=NULL)
        {
            if (caminho(F->no_filho,D,G)==1)
            {
                printf(" %s - ",F->no_filho->nome);   /* mostra cada um dos nós no caminho */
                return 1;
            }
            F=F->prox_filho;
        }            
    }
    return 0;
}

void mostra_caminho(char *origem, char *destino, struct no *G)
{
    struct no *O,*D;
    O=busca_no(origem,G);
    D=busca_no(destino,G);
    
    if (O!=NULL && D!=NULL)
        if (caminho(O,D,G)==1)      /*  Se encontrou u caminho do nó O até o nó D */
            printf("%s ",O->nome);   /* mostra a origem */
        
}
int main()
{
    struct no *grafo;
    grafo=inicializa_grafo();
    insere_no(&grafo,"E");     
    insere_no(&grafo,"D");     
    insere_no(&grafo,"C");    
    insere_no(&grafo,"B");  
    insere_no(&grafo,"A"); 

    insere_link("A","B", &grafo);   
    insere_link("B","C", &grafo);
    insere_link("D","C", &grafo);   
    insere_link("A","D", &grafo);
    insere_link("C","E", &grafo);
    insere_link("E","B", &grafo);    
    
    mostra_caminho("A","E",grafo); /* Mostra um caminho partindo do nó 
                            "A" e chegando ao nó "E" */    
	return 0;
}
