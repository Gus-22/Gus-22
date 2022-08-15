int existel(char * nome_pai, char * nome_filho, struct no **G)
{
    struct no *pont_pai, *pont_filho;
	struct filho *F;
    pont_pai=busca_no(nome_pai,*G); // &a
	pont_filho=busca_no(nome_filho,*G);//&d
		
		if (pont_filho == pont_pai){
			printf("nos igual");
			return 0;
			
		}else{
			
		F= (struct filho *) malloc(sizeof(struct filho));
		F=pont_pai->filhos;
			
			while(F !=NULL){
				
				if(F->no_filho==pont_filho){
					printf("\n !!! aresta encontrada");
					return 1;
				}else{
					F= F->prox_filho;
			    }
			}
			printf("\n !!!! aresta NAO encontrada ");
			return 0;
					
		}	
}