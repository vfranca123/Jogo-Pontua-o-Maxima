#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../interfaces/configArquivo.h"

FILE* lerArquivo(char *nome_arquivo){
    // Declaração de um array de caracteres para armazenar o caminho do arquivo
    char caminho_arquivo[100];

    // Copia "../data/" para o array caminho_arquivo
    strcpy(caminho_arquivo, "../data/");

    // Concatena o nome do arquivo ao final do caminho
    strcat(caminho_arquivo, nome_arquivo);

    // Declaração de um ponteiro para FILE (arquivo)
    FILE *arquivo;

    // Tenta abrir o arquivo especificado pelo caminho em modo de leitura ("r")
    arquivo = fopen(caminho_arquivo, "r");
    
    return arquivo;
}

void EscritaArquivo(int resposta){
    
    char caminho_arquivo2[100]; 
    // Abrindo o arquivo para escrita
    strcpy(caminho_arquivo2, "../data/output.txt");
        
    FILE *output_file = fopen(caminho_arquivo2, "w");
    if (output_file == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        
    }

    // Escrevendo a resposta no arquivo
    fprintf(output_file, "%d\n", resposta);
        
    // Fechando o arquivo
    fclose(output_file);
    
}