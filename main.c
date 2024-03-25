#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    FILE *file = fopen("contatos.txt", "r");

    Contato contato;
    int colisoes = 0;

    char linha[120];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "Nome: %[^\n]", contato.nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Telefone: %[^\n]", contato.telefone);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Email: %[^\n]", contato.email);
        unsigned int indice = funcaoHash(contato.nome);
        if (tabela.vetor[indice] != NULL) {
            colisoes++;
        }
        inserirContato(&tabela, contato);
    }

    printf("Numero de colisoes: %d\n", colisoes);
    fclose(file);

    // Testando a busca
    // No *resultadoBusca = buscarContato(tabela, "Gustavo Carvalho");
    // if (resultadoBusca != NULL) {
    //     printf("Contato encontrado: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
    // } else {
    //     printf("Contato não encontrado.\n");
    // }

    return 0;
}