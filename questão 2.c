#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
    int valor;
    struct nodo *left;
    struct nodo *right;
};

struct nodo *inicializa_arvore()
{
    return (struct nodo*) NULL;
}

void insere_item(struct nodo **L, int item)
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


void remover(struct nodo **g, int valor, int flag) {

    if (*g ==   NULL) {
        return;
    }

    if (flag) {
        remover(&(*g)->right, valor, 1);
        remover(&(*g)->left, valor, 1);
        free(*g);
        return;
    }

    if ((*g)->right != NULL && (*g)->right->valor == valor) {
        remover(&(*g)->right, valor, 1);
        (*g)->right = NULL;
        return;
    }else if ((*g)->left != NULL && (*g)->left->valor == valor) {
        remover(&(*g)->left, valor, 1);
        (*g)->left = NULL;
        return;
    } else {
        remover(&(*g)->right, valor, 0);
        remover(&(*g)->left, valor, 0);
    }


}

void mostra_arvore(struct nodo *L)
{   if (L!=NULL)
    {
      mostra_arvore(L->left);
      printf("%d ",L->valor);
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
    insere_item(&tree,60);
    insere_item(&tree,70);

	//remover(&tree, 50);
    remover(&tree, 50, 0);
    mostra_arvore(tree);
	return 0;
}
