
//questão 2

int contar(struct lista *p, int cont)
{   
    if(p!= NULL)
    {
        cont++;
        contar(p->prox, cont);
    }
    else return cont;
}

//questão 3

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

//questão 4

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
