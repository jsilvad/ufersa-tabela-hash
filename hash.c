#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa uma tabela hash, definindo todos os ponteiros de lista encadeada como NULL
void inicializarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->vetor[i] = NULL;
    }
    tabela->tamanho = 0;
}

// Função de hash (dobra) que converte uma chave (nome) em um índice na tabela hash
unsigned int funcaoHash(char *chave) {
    unsigned int hash = 0;
    int len = strlen(chave);
    int partes = len / 4;

    for (int i = 0; i < partes; i++) {
        for (int j = 0; j < 4; j++) {
            hash += chave[i * 4 + j];
        }
    }

    if (len % 4 != 0) {
        for (int i = 0; i < len % 4; i++) {
            hash += chave[partes * 4 + i];
        }
    }

    return hash % TAMANHO_TABELA;
}

// Insere um novo contato na tabela hash
void inserirContato(TabelaHash *tabela, Contato novoContato) {
    unsigned int indice = funcaoHash(novoContato.nome); // Calcula o índice usando a função de hash

    No *novoNo = malloc(sizeof(No)); // Aloca memória para um novo nó
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: nao foi possivel alocar memoria.\n");
        return;
    }

    // Copia os dados do novo contato para o novo nó
    strcpy(novoNo->contato.nome, novoContato.nome);
    strcpy(novoNo->contato.telefone, novoContato.telefone);
    strcpy(novoNo->contato.email, novoContato.email);

    // Insere o novo nó no início da lista encadeada correspondente ao índice calculado
    novoNo->prox = tabela->vetor[indice];
    tabela->vetor[indice] = novoNo;

    tabela->tamanho++; // Incrementa o tamanho da tabela hash
}

// Busca por um contato na tabela hash a partir de uma chave (nome)
No *buscarContato(TabelaHash tabela, char *chave) {
    unsigned int indice = funcaoHash(chave); // Calcula o índice usando a função de hash
    No *atual = tabela.vetor[indice]; // Inicia a busca a partir do primeiro nó na lista encadeada correspondente ao índice

    while (atual != NULL) {
        if (strcmp(atual->contato.nome, chave) == 0) {
            printf("\nContato encontrado na posicao: %u", indice); // Imprime a posição na tabela hash onde o contato está localizado
            return atual;
        }
        atual = atual->prox;
    }

    printf("Contato nao encontrado.\n");
    return NULL;
}

// Remove um contato da tabela hash a partir de uma chave (nome)
void removerContato(TabelaHash *tabela, char *chave) {
    unsigned int indice = funcaoHash(chave);
    No *atual = tabela->vetor[indice];
    No *anterior = NULL;

    // Percorre a lista encadeada buscando pelo contato a ser removido
    while (atual != NULL) {
        if (strcmp(atual->contato.nome, chave) == 0) {
            if (anterior == NULL) {
                tabela->vetor[indice] = atual->prox; // Remove o primeiro nó da lista
            } else {
                anterior->prox = atual->prox; // Remove um nó do meio ou do fim da lista
            }
            free(atual); // Libera a memória alocada para o nó
            tabela->tamanho--; // Decrementa o tamanho da tabela hash
            return;
        }
        anterior = atual;
        atual = atual->prox; // Avança para o próximo nó na lista
    }
}

// Libera a memória alocada para todos os nós da tabela hash
void liberarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        No *atual = tabela->vetor[i];
        while (atual != NULL) {
            No *proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        tabela->vetor[i] = NULL; // Define o ponteiro na tabela hash como NULL após liberar a lista encadeada
    }
}