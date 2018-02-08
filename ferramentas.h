#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Arquivo de cabeçalho onde são declaradas as funções e estruturas do programa;
Contém pequenos comentários acerca das funções e estruturas. 
*/

#define MAX 1024
    //Valor máximo das variaveis utilizadas no programa.

typedef struct arquivo{ 
    //estrutura utilizada para receber o conteúdo dos arquivos
    FILE* pontArquivo1;
    FILE* pontArquivo2;
}arquivo;

typedef struct tipoStrings{
    //Estrutura utilizada na função lerArquivo para retonar
    // de forma prática o conteúdo dos arquivos em duas variaveis do tipo char.     
    char texto1[MAX];
    char texto2[MAX];
}tipoStrings;

typedef struct vetorString{
    //Estrutura criada para receber o conteúdo dos textos sem nenhum caractere especial( "",.;/?!_-).
    //A mesma é um vetor de strings para otimizar a comparação futura das palavras.
    //para evitar calculos futuros nessa estrutura é salvo o número de palavras do nosso vetor de strings. 
    char conteudo[MAX][MAX];
    int  palavras;
}vetorString;

tipoStrings lerArquivo(char caminhoArq1[100], char caminhoArq2[100]);
    //A função recebe como parâmetro o caminho dos dois arquivos e depois 
    //retorna o conteúdo de cada um texto em uma variavel to tipo: tipoStrings

vetorString fatiador(char texto[MAX]);
    //Para reduzir a ambiguidade na compração dos arquivos é retirado todos os espaços em branco e 
    //todos os caracteres especiais(",.;:/?!-_") e substituidos por NULL.
    //Após isso cada palavra é inserida numa variavel do tipo vetorString onde a função retorna a mesma.

int erro();
    //Retorna erro caso haja algum.

