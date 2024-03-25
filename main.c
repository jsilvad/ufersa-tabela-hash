#include <stdio.h>
#include "hash.h"

int main() {
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    FILE *file = fopen("contatos.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    Contato contato;
    int colisoes = 0;
    while (fscanf(file, "%s %s %s", contato.nome, contato.telefone, contato.email) == 3) {
        unsigned int indice = funcaoHash(contato.nome);
        if (tabela.vetor[indice] != NULL) {
            colisoes++;
        }
        inserirContato(&tabela, contato);
    }

    fclose(file);

    return 0;
}