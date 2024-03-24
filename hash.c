#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->vetor[i] = NULL;
    }
    tabela->tamanho = 0;
}

unsigned int funcaoHash(char *chave) {
    unsigned int hash = 0;
    int c;

    while ((c = *chave++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TAMANHO_TABELA;
}

void inserirContato(TabelaHash *tabela, Contato novoContato) {
    unsigned int indice = funcaoHash(novoContato.nome);

    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: nao foi possivel alocar memoria.\n");
        return;
    }

    strcpy(novoNo->contato.nome, novoContato.nome);
    strcpy(novoNo->contato.telefone, novoContato.telefone);
    strcpy(novoNo->contato.email, novoContato.email);
    novoNo->prox = tabela->vetor[indice];
    tabela->vetor[indice] = novoNo;

    tabela->tamanho++;
}

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

void removerContato(TabelaHash *tabela, char *chave) {
    unsigned int indice = funcaoHash(chave);
    No *atual = tabela->vetor[indice];
    No *anterior = NULL;

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