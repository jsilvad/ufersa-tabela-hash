typedef struct {
    char nome[50];
    char telefone[15];
    char email[40];
} Contato;

typedef struct No {
    Contato contato;
    struct No *prox;
} No;