#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define ARQUIVO_CONTATOS "contatos.txt"

int main() {
    // Inicializa a tabela hash
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    // Abre o arquivo contatos.txt para leitura
    FILE *file = fopen(ARQUIVO_CONTATOS, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    Contato contato;
    int colisoes = 0;
    // Lê os contatos do arquivo e insere na tabela hash
    while (fscanf(file, "Nome: %[^\n]\nTelefone: %[^\n]\nEmail: %[^\n]\n\n", contato.nome, contato.telefone, contato.email) == 3) {
        unsigned int indice = funcaoHash(contato.nome);
        if (tabela.vetor[indice] != NULL) {
            colisoes++; // Conta as colisões encontradas durante a inserção
        }
        inserirContato(&tabela, contato);
    }

    // Exibe o número de colisões encontradas durante a inserção
    printf("Numero de colisoes: %d\n", colisoes);

    fclose(file);

    return 0;
}