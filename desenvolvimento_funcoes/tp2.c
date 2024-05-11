#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../interfaces/tempo.h"
#include "../interfaces/array.h"
#include "../interfaces/dinamica.h"
#include "../interfaces/configArquivo.h"
#include "../interfaces/alternativo.h"

int main(int argc, char *argv[]){
    
    struct timeval ini_tempo_total, fim_tempo_total;
    struct rusage inicio, fim;
    iniciar_contagem(&ini_tempo_total, &inicio);
// checando se todos os argumentnos necessarios foram inseridos  
    if (argc != 3) {
        printf("Formato para estar no terminal: \n");
        printf("Uso: %s <estrategia> entrada.txt\n", argv[0]);
        return 1;
    }
    char *estrategia = argv[1];
    char *nome_arquivo = argv[2]; 
    
// abrindo e configurando o aquivo 
    FILE *arquivo =lerArquivo(nome_arquivo);
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
        
    }
//passando os dados do txt para o array------------
    DynamicArray *myArray = createDynamicArray();
    
    int n;
    fscanf(arquivo, "%d", &n);
    
    for (int i = 0; i < n; i++) {
        int numero;
        fscanf(arquivo, "%d", &numero);
        addElement(myArray, numero);
    }
//-----------------------------------------------------
//estrategia Dinamica
    if( strcmp(estrategia, "d") == 0 || strcmp(estrategia, "D") == 0){    
        int resposta = Dinamica(myArray->array, myArray->size);
        EscritaArquivo(resposta);
    }

//estrategia Alternativa
    if( strcmp(estrategia, "a") == 0 || strcmp(estrategia, "A") == 0){    
        int resposta = alternativo(myArray->array,myArray->size);
        EscritaArquivo(resposta);
    }
    
    free(myArray->array);
    free(myArray);
    fclose(arquivo);
    parar_contagem(&fim_tempo_total, &fim);
    printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim);
    return 0;
}

