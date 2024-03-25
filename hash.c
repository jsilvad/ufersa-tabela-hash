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
    int len = strlen(chave);
    int partes = len / 4;

    for (int i = 0; i < partes; i++) {
        char parte[5];
        strncpy(parte, &chave[i * 4], 4);
        parte[4] = '\0';
        hash += atoi(parte);
    }

    if (len % 4 != 0) {
        char parte[5];
        strncpy(parte, &chave[partes * 4], len % 4);
        parte[len % 4] = '\0';
        hash += atoi(parte);
    }

    return hash % TAMANHO_TABELA;
}

void inserirContato(TabelaHash *tabela, Contato novoContato) {
    unsigned int indice = funcaoHash(novoContato.nome);

    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: não foi possível alocar memória.\n");
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

void liberarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        No *atual = tabela->vetor[i];
        while (atual != NULL) {
            No *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        tabela->vetor[i] = NULL;
    }
}