#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA 40009

typedef struct {
    char nome[50];
    char telefone[15];
    char email[40];
} Contato;

typedef struct No {
    Contato contato;
    struct No *prox;
} No;

typedef struct {
    No *vetor[TAMANHO_TABELA];
    int tamanho;
} TabelaHash;

void inicializarTabelaHash(TabelaHash *tabela);
unsigned int funcaoHash(char *chave);
void inserirContato(TabelaHash *tabela, Contato novoContato);
No *buscarContato(TabelaHash tabela, char *chave);
void removerContato(TabelaHash *tabela, char *chave);
void liberarTabelaHash(TabelaHash *tabela);

#endif