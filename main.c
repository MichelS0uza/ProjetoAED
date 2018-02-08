#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcs.c"//arquivo onde estão as funções de comparação de strings.
#include "ferramentas.c"//Arquivo onde estão as funções de tratamento de strings.

#define MAX 1024

int main(){

    int i;
    int valorGraus[MAX];    
    vetorString palavrasLCS;
    palavrasLCS.palavras = 0;
    tipoStrings conteudo = lerArquivo("texto.txt", "texto2.txt");//ler o conteudo dos respectivos arquivos
    
    vetorString teste = fatiador(conteudo.texto1);//tira os caracteres especiais do texto 1
    vetorString teste2 = fatiador(conteudo.texto2);//

    for(i = 0; i<teste2.palavras; i++){
        int tamP1 = strlen(teste.conteudo[i]);// ler o tamanho da string do texto 1
        int tamP2 = strlen(teste2.conteudo[i]);// ler o tamanho da string do texto 2       
 
        tipoMatriz teste3 = findLCS(teste.conteudo[i], teste2.conteudo[i], tamP1, tamP2);//realiza a comparação das strings    
        tipoLcs result = mostrarLCS(teste.conteudo[i], teste2.conteudo[i], teste3);//chama a função que retorna o grau e a sequência
        
        strcpy(palavrasLCS.conteudo[i], result.seqComum);//copia a sequência para um vetor de strings
        valorGraus[i] = result.grau;//copia os graus para um vetor        
        palavrasLCS.palavras++;//incrementa o numero de palavras comparadas    
    }

    printf(" \nTexto 1:\n");
    for(i=0; i<teste.palavras;i++){
        printf("%s ", teste.conteudo[i]);
    }
    //imprime o primeiro texto
    printf("\nTexto 2:\n");
    for(i=0; i<teste2.palavras;i++){
        printf("%s ", teste2.conteudo[i]);
    }
    //imprime o segundo
    printf("\nSequência Comum:\n");
        for(i=0; i<palavrasLCS.palavras;i++){
            printf(" %s ", palavrasLCS.conteudo[i]);
    }
    //imprime a sequência comum entre os textos
    printf("\nSequência Comum com Graus:\n");
    for(i=0; i<palavrasLCS.palavras;i++){
        printf("LCS: '%s' |Grau %d ", palavrasLCS.conteudo[i], valorGraus[i]);
        if(valorGraus[i]==0) 
            printf("LCS: Nenhum. Grau: %d ", valorGraus[i]);
    printf("\n");    
    }
    //imprime a sequência junto com os valores dos graus
    return 0;
}
