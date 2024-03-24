#define TAMANHO_TABELA 10019  // Tamanho da tabela hash (número primo)

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