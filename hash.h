#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA 10

#define TAMANHO_NOME 50
#define TAMANHO_TELEFONE 15
#define TAMANHO_EMAIL 40

// Estrutura para armazenar os dados de um contato
typedef struct {
    char nome[TAMANHO_NOME];
    char telefone[TAMANHO_TELEFONE];
    char email[TAMANHO_EMAIL];
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

// Declaração das funções que manipulam a tabela hash
void inicializarTabelaHash(TabelaHash *tabela);
unsigned int funcaoHash(char *chave);
void inserirContato(TabelaHash *tabela, Contato novoContato);
No *buscarContato(TabelaHash tabela, char *chave);
void removerContato(TabelaHash *tabela, char *chave);
void liberarTabelaHash(TabelaHash *tabela);

#endif