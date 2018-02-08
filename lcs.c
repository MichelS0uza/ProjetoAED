#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcs.h" //arquivo de cabeçalhos e declaração de estruturas

#define MAXIMO 200

int max(int a, int b) {//testa qual o maior entre dois valores 
    return (a > b)? a : b;
}

tipoMatriz findLCS(char palavra1[MAXIMO], char palavra2[MAXIMO], int p1Tam, int p2Tam) {

    tipoMatriz matriz;
    int linha, coluna, i;
    matriz.p1Tam = p1Tam;//adiciona o tamanho da string a matriz
    matriz.p2Tam = p2Tam;
    for(linha = 0; linha <= p1Tam; linha++) { //construção a matriz de adjacências
        for(coluna = 0; coluna <= p2Tam; coluna++) {
            if(linha == 0 || coluna == 0) {
                matriz.mat[linha][coluna] = 0;
            }
            else if(palavra1[linha - 1] == palavra2[coluna - 1]) {
                matriz.mat[linha][coluna] = matriz.mat[linha - 1][coluna - 1] + 1;
            } 
            else {
                matriz.mat[linha][coluna] = max(matriz.mat[linha - 1][coluna], matriz.mat[linha][coluna - 1]);
            }
        }
    }
    return matriz;//retorna a matriz de adjacências
}

tipoLcs mostrarLCS(char palavra1[MAXIMO], char palavra2[MAXIMO], tipoMatriz matriz){
    //Função que recebe a matriz e retorna o grau e a sequência
    tipoLcs resultado;
    int linha = matriz.p1Tam;
    int coluna = matriz.p2Tam;
    int i = matriz.mat[linha][coluna];
    char LCS[MAXIMO];

    LCS[i] = '\0'; // seta /\0 para sinalizar o final da sequência
    while(linha > 0 && coluna > 0) {  
        if(palavra1[linha - 1] == palavra2[coluna - 1]) {
            LCS[i - 1] = palavra1[linha - 1];
            i--;
            linha--;
            coluna--;//estratégia de BottomUp para encontrar a sequência
        }   
    else if(matriz.mat[linha - 1][coluna] > matriz.mat[linha][coluna - 1]) {
        linha--;
        }
    else {
        coluna--;
        }
    }
    
    resultado.grau = matriz.mat[matriz.p1Tam][matriz.p2Tam];//recebe o valor do grau de similaridade
    strncpy(resultado.seqComum, LCS, MAXIMO);//recebe a sequência
    return resultado;//retorna a sequência e o grau
}
