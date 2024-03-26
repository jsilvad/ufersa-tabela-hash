#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA 2000

// Estrutura para armazenar os dados de um contato
typedef struct {
    char nome[50];
    char telefone[15];
    char email[40];
} Contato;

// Estrutura de um nó da lista encadeada utilizada na tabela hash
typedef struct No {
    Contato contato;
    struct No *prox;    // Ponteiro para o próximo nó na lista encadeada
} No;

// Estrutura da tabela hash
typedef struct {
    No *vetor[TAMANHO_TABELA];  // Vetor de ponteiros para os nós da lista encadeada
    int tamanho;                // Número de elementos na tabela hash
} TabelaHash;

void inicializarTabelaHash(TabelaHash *tabela);
unsigned int funcaoHash(char *chave);
void inserirContato(TabelaHash *tabela, Contato novoContato);
No *buscarContato(TabelaHash tabela, char *chave);
void removerContato(TabelaHash *tabela, char *chave);
void liberarTabelaHash(TabelaHash *tabela);

#endif