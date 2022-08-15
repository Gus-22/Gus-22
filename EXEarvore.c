/******************************************************************************

arvore.c


Implementa um exemplo de árvore binária.
Autor: Leonardo R. Emmendorfer
Data: 16/07/2022

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo{
    int valor;
    struct nodo * left;
    struct nodo * right;
};


struct nodo *inicializa_arvore()
{
    return (struct nodo*) NULL;
}

void insere_item(struct nodo **L,int item)
{
    struct nodo *new;
    if ((*L)==NULL)
    {
        new=(struct nodo  *) malloc(sizeof(struct nodo));
        new->valor=item;
        new->left=NULL;
        new->right= NULL;
        
        (*L)=new;
    }    
    else if (item > (*L)->valor)
        insere_item(&(*L)->right,item);   
    else    
        insere_item(&(*L)->left,item);  
   
}


void mostra_arvore(struct nodo *L)
{   if (L!=NULL)
    {
      mostra_arvore(L->left);
      printf("%d\n",L->valor);
      mostra_arvore(L->right);
    }
}

int main()
{
    struct nodo *tree;
    tree=inicializa_arvore();
    insere_item(&tree,30);    
    insere_item(&tree,10);     
    insere_item(&tree,20);
    insere_item(&tree,50);    
    insere_item(&tree,40);
    mostra_arvore(tree);
	return 0;
}

