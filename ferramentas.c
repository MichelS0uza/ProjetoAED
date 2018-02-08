#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ferramentas.h"// arquivo de cabeçalhos e declaração de estruturas

#define MAX 1024     //Valor máximo das variaveis utilizadas no programa.

tipoStrings lerArquivo(char caminhoArq1[100], char caminhoArq2[100]){
    
    //A função ler o caminho dos arquivos e retorna o conteudo deles    
    tipoStrings conteudo;
    arquivo textos;
    textos.pontArquivo1 = fopen (caminhoArq1, "r");
    textos.pontArquivo2 = fopen (caminhoArq2, "r");

    if ((textos.pontArquivo1 == NULL) || (textos.pontArquivo2 == NULL))
        erro();
    
    if (fgets(conteudo.texto1, MAX, textos.pontArquivo1) && fgets(conteudo.texto2, MAX,textos.pontArquivo2) != NULL)

    fclose (textos.pontArquivo1);
    fclose (textos.pontArquivo2);
    return conteudo;
}

vetorString fatiador(char texto[MAX]){
    
    //todos os caracteres especiais(",.;:/?!-_") são substituidos por NULL.
    int i, j, palavras = 0;
    const char excluidos[] = ", .:/-;*!?"; 
    vetorString textoLimpo;
    for (char *aux = strtok(texto, excluidos); aux != NULL; aux = strtok(NULL, excluidos)){
        strcpy(textoLimpo.conteudo[palavras++], aux);
}
    textoLimpo.palavras = palavras;
    return textoLimpo; //retorna o texto limpo sem caracteres especiais. 
}

int erro(){
    
    printf("Ocorreu algum problema na leitura de um arquivo");
    return 1;
}
