#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA_MAX; i++) {
        tabela->vetor[i] = NULL;
    }
    tabela->tamanho = 0;
}

unsigned int funcaoHash(char *chave) {
    unsigned int hash = 0;
    int len = strlen(chave);

    // Técnica de dobramento
    for (int i = 0; i < len; i++) {
        hash = (hash << 5) + chave[i];
    }

    return hash % TAMANHO_TABELA_MAX;
}

// Insere um contato na tabela hash
void inserirContato(TabelaHash *tabela, Contato novoContato) {
    // Calcula o índice do vetor usando a função de hash
    unsigned int indice = funcaoHash(novoContato.nome);

    // Aloca memória para o novo nó
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: nao foi possivel alocar memoria.\n");
        return;
    }

    // Copia os dados do contato para o novo nó
    strcpy(novoNo->contato.nome, novoContato.nome);
    strcpy(novoNo->contato.telefone, novoContato.telefone);
    strcpy(novoNo->contato.email, novoContato.email);
    // Insere o novo nó no início da lista encadeada na posição adequada do vetor
    novoNo->prox = tabela->vetor[indice];
    tabela->vetor[indice] = novoNo;

    // Incrementa o tamanho da tabela
    tabela->tamanho++;
}


// Busca por um contato na tabela hash
No *buscarContato(TabelaHash tabela, char *chave) {
    unsigned int indice = funcaoHash(chave);
    No *atual = tabela.vetor[indice];

    while (atual != NULL) {
        if (strcmp(atual->contato.nome, chave) == 0) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

// Remove um contato da tabela hash
void removerContato(TabelaHash *tabela, char *chave) {
    unsigned int indice = funcaoHash(chave);
    No *atual = tabela->vetor[indice];
    No *anterior = NULL;

    // Percorre a lista encadeada buscando pelo contato a ser removido
    while (atual != NULL) {
        if (strcmp(atual->contato.nome, chave) == 0) {
            if (anterior == NULL) {
                tabela->vetor[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            tabela->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
