#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define LINHA_TAMANHO 120

int main() {
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    FILE *file = fopen("contatos.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo contatos.txt.\n");
        return 1;
    }

    Contato contato;
    int colisoes = 0;
    char linha[LINHA_TAMANHO];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "Nome: %[^\n]", contato.nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Telefone: %[^\n]", contato.telefone);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Email: %[^\n]", contato.email);
        unsigned int indice = funcaoHash(contato.nome);
        if (tabela.vetor[indice] != NULL) {
            colisoes++;
        }
        inserirContato(&tabela, contato);
    }

    fclose(file);

    int opcao;
    char nome[50];
    char telefone[15];
    char email[40];
    No *resultadoBusca;

    do {
        printf("\n----------- MENU -----------\n");
        printf("1. Ver numero de colisoes\n");
        printf("2. Inserir um contato\n");
        printf("3. Remover contato\n");
        printf("4. Buscar um contato\n");
        printf("5. Sair\n");
        printf("----------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero de colisoes: %d\n", colisoes);
                break;
            case 2:
                printf("Digite o nome do contato: ");
                scanf(" %[^\n]", nome);
                printf("Digite o telefone do contato: ");
                scanf(" %[^\n]", telefone);
                printf("Digite o email do contato: ");
                scanf(" %[^\n]", email);
                Contato novoContato;
                strcpy(novoContato.nome, nome);
                strcpy(novoContato.telefone, telefone);
                strcpy(novoContato.email, email);
                inserirContato(&tabela, novoContato);
                printf("Contato inserido com sucesso.\n");
                break;
            case 3:
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removerContato(&tabela, nome);
                printf("Contato removido com sucesso.\n");
                break;
            case 4:
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                resultadoBusca = buscarContato(tabela, nome);
                if (resultadoBusca != NULL) {
                    printf("\nContato encontrado: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
                } else {
                    printf("\nContato nao encontrado.\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    liberarTabelaHash(&tabela);

    return 0;
}