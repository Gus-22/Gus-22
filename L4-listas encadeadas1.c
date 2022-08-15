#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int preco;
    int cod;
    struct lista *prox;
};

struct lista *inicializa_lista()
{
return (struct lista*) NULL;
}

int insere(struct lista **p,int coda, int valore)
{
	int cod,preco;
    struct lista *atual;
    atual = (struct lista*)malloc(sizeof(struct lista));
    printf("digite o codigo do produto:  ");
    scanf("%d", &cod);
    coda=cod;
    printf("digite o preço deste produto:  ");
    scanf("%d", &preco);
    valore=preco;
    atual->preco = preco;
    atual->cod = cod;
    atual->prox = (*p);
    (*p) = atual;
}
 
int pop(struct lista **p, int cod)
{
    struct lista *aux;
    if((*p)==NULL)
    {
        return 0;
    }
    if((*p)->cod == cod)
    {
        aux = (*p);
        (*p) = (*p)->prox;
        free(aux);
        return 1;
    }
    else 
    pop(&((*p)->prox), cod);
}

void listar(struct lista *p)
{
    if(p!= NULL)
    {
        printf("\nitem : %d\n R$%d.00\n", p->cod, p->preco);
        listar(p->prox);
    }
}

int contar(struct lista *p, int cont)
{   
    if(p!= NULL)
    {
        cont++;
        contar(p->prox, cont);
    }
    else return cont;
}

int conta_item(struct lista **p, int conta, int x)
{   
    if((*p)!= NULL)
    {
    	if((*p)->preco == x)
    	{
    		 conta++;
    	}
    	conta_item(&((*p)->prox), conta, x);
    }
    else return conta;
}

void vazia (struct lista **p, int vazio)
{
	 if((*p)!= NULL)
    {
        vazio++;
        vazia(&((*p)->prox), vazio);
    }
   if ((*p) == NULL)
    {
    	if(vazio > 0)
    	{
    		printf("\nLista nao vazia\n");
    	}else printf("\nlista vazia\n");
    }
    
}

int main() {
    int cont=0, conta=0,vazio=0, y ,cod;
    struct lista *l1;
    l1 = inicializa_lista();
    insere(&l1,1,1);
    insere(&l1,1,1);
    insere(&l1,1,1);
    insere(&l1,1,1);
    printf("retirar qual cod? \n");
    scanf("%d", &cod);
    pop(&l1,cod);
    vazia(&l1, vazio);
    listar(l1);
    cont = contar(l1, cont);
    printf("tem tantos items : %d", cont);
    int x;
printf("\nquantos produtos tem com este valor : ");
scanf("%d", &x);
    conta = conta_item(&l1, conta, x);
    printf("tem tantos itens com esse valor : %d", conta);
}














