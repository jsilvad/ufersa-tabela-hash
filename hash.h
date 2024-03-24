#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA 10019  // Tamanho da tabela hash (número primo)

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

typedef struct No {
    Contato contato;
    struct No *prox;
} No;

typedef struct {
    No *vetor[TAMANHO_TABELA];
    int tamanho;  // Tamanho atual da tabela
} TabelaHash;

void inicializarTabelaHash(TabelaHash *tabela);
unsigned int funcaoHash(char *chave);
void inserirContato(TabelaHash *tabela, Contato novoContato);
No *buscarContato(TabelaHash tabela, char *chave);
void removerContato(TabelaHash *tabela, char *chave);

#endif