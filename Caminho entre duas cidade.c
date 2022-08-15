#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 6

void iniciarGrafo(int mat[][TAM]) {
    int i, j;
    for (i=0; i<TAM; i++)
        for (j=0; j<TAM; j++)
            mat[i][j] = 0;
}

void join(int mat[][TAM], int cidade1, int cidade2) {
    mat[cidade1][cidade2]=1;
}

int adjacente(int mat[][TAM], int cidade1, int cidade2) {
    if (mat[cidade1][cidade2])
        return 1;
    else return 0;
}

int procuraCaminho(int mat[][TAM], int cidade1, int cidade2, int k) {
    int c;
    if (k ==1) {
        if (adjacente(mat, cidade1, cidade2))
            return 1;
        else return 0;
    }
    for (c=0; c<TAM; ++c)
        if (adjacente(mat, cidade1, c) && procuraCaminho(mat, c, cidade2, k-1))
            return 1;
    return 0;
}

int main() {
    int matriz[TAM][TAM];
    int cidade1, cidade2, k, temCaminho;
    char resp='S', caminho[30]="\0";
    iniciarGrafo(matriz);
    while (toupper(resp) == 'S') {

    do {
        printf("Digite o codigo da cidade de origem: ");
        scanf("%i", &cidade1);
    } while (cidade1 <1 || cidade1 >TAM);

    do {
        printf("Digite o codigo da cidade de destino: ");
        scanf("%i", &cidade2);
    } while (cidade2 <1 || cidade2 >TAM);

    printf("Realizar outro join? ");
    join(matriz, cidade1-1, cidade2-1);
    fflush(stdin);
    scanf("%c", &resp);

    }//fim do laço

printf("Digite cidade A: ");
scanf("%i", &cidade1);
printf("Digite cidade B: ");
scanf("%i", &cidade2);
printf("Digite tamanho do caminho: ");
scanf("%i", &k);
temCaminho = procuraCaminho(matriz, cidade1-1, cidade2-1, k);

    if (temCaminho ==1)
        printf("Existe caminho de comprimento %i entre as cidades %i e% i", k, cidade1, cidade2);
    else
        printf("Nao existe caminho de comprimento %i entre as cidades %i e% i", k, cidade1, cidade2);
    system("pause");
    return 0;
}