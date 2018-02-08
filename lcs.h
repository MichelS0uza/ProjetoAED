#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Arquivo de cabeçalho onde são declaradas as funções e estruturas do programa;
Contém pequenos comentários acerca das funções e estruturas. 
*/

#define MAXIMO 200
    //Valor máximo para inicialização das variaveis utilizadas no programa.

typedef struct tipoMatriz{
    //estrura criada para a função que calcula a lcs.
    //Esta estrutura guarda a matriz e o tamanho das palavras que serão analizadas na função.
    int mat[MAXIMO][MAXIMO];
    int p1Tam;
    int p2Tam;
}tipoMatriz;

typedef struct tipoLcs{
    //Estrutura que guarda o resultado da lcs o grau de assimilaridade e a sequência em comum das palavras. 
    int grau;
    char seqComum[MAXIMO];
}tipoLcs;

tipoMatriz findLCS(char palavra1[MAXIMO], char palavra2[MAXIMO], int p1Tam, int p2Tam);
    //Essa função realiza a compração de cada caractere das palavras formando uma matriz de adjacências com ponteuações.
    //A mesma retona essa matriz de pontuações preenchida.
int max(int a, int b);
    //retorna o valor máximo de dois valores
tipoLcs mostrarLCS(char palavra1[MAXIMO], char palavra2[MAXIMO], tipoMatriz matriz);
    //Essa função recebe a matriz de adjacências preenchida e imprime a a sequência comum das palavras
    //e o grau de similaridade das mesmmas.

