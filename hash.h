#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA_MIN 20011 // Tamanho mínimo da tabela hash (próximo número primo acima de 39999 / 2)
#define TAMANHO_TABELA_MAX 60037 // Tamanho máximo da tabela hash (próximo número primo acima de 39999 * 3 / 4)

typedef struct {
    char nome[50];
    char telefone[20];
    char email[40];
} Contato;

typedef struct No {
    Contato contato;
    struct No *prox;
} No;

typedef struct {
    No *vetor[TAMANHO_TABELA_MAX];
    int tamanho;
} TabelaHash;

// Funções da tabela hash
void inicializarTabelaHash(TabelaHash *tabela);
unsigned int funcaoHash(char *chave);
void inserirContato(TabelaHash *tabela, Contato novoContato);
No *buscarContato(TabelaHash tabela, char *chave);
void removerContato(TabelaHash *tabela, char *chave);

#endif