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
    // No *resultadoBusca = buscarContato(tabela, "Nome Contato");
    // if (resultadoBusca != NULL) {
    //     printf("Contato encontrado: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
    // } else {
    //     printf("Contato não encontrado.\n");
    // }

    // Testando a inserção
    // Contato novoContato = {"Teste Nome", "Teste Telefone", "Teste Email"};
    // inserirContato(&tabela, novoContato);
    // No *resultadoBusca = buscarContato(tabela, "Teste Nome");
    // if (resultadoBusca != NULL) {
    //     printf("Contato inserido com sucesso: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
    // } else {
    //     printf("Falha ao inserir o contato.\n");
    // }

    // Testando a remoção
    // removerContato(&tabela, "Teste Nome");
    // resultadoBusca = buscarContato(tabela, "Teste Nome");
    // if (resultadoBusca == NULL) {
    //     printf("Contato removido com sucesso.\n");
    // } else {
    //     printf("Falha ao remover o contato.\n");
    // }

    return 0;
}