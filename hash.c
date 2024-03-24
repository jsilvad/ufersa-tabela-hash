#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int funcaoHash(char *chave) {
    unsigned int hash = 0;
    int c;

    while ((c = *chave++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TAMANHO_TABELA;
}