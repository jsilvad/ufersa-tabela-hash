#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define LINHA_TAMANHO 120

// Função para ler contatos de um arquivo e inseri-los na tabela hash
void lerContatosDoArquivo(TabelaHash *tabela, char *nomeArquivo, int *colisoes) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    Contato contato;
    char linha[LINHA_TAMANHO];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "Nome: %[^\n]", contato.nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Telefone: %[^\n]", contato.telefone);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Email: %[^\n]", contato.email);
        unsigned int indice = funcaoHash(contato.nome);
        // Verifica se houve colisão ao inserir o contato na tabela hash
        if (tabela->vetor[indice] != NULL) {
            (*colisoes)++;
        }
        inserirContato(tabela, contato);
    }

    fclose(file);
}

int main() {
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    int colisoes = 0;
    lerContatosDoArquivo(&tabela, "contatos.txt", &colisoes);

    int opcao;
    char nome[TAMANHO_NOME];
    char telefone[TAMANHO_TELEFONE];
    char email[TAMANHO_EMAIL];
    No *resultadoBusca;
    int posicao;

    do {
        printf("\n---------------- MENU ----------------\n");
        printf("1. Inserir um contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar um contato\n\n");
        printf("4. Listar contatos em uma posicao\n");
        printf("5. Visualizar numero total de colisoes \n\n");
        printf("6. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
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
                printf("\nContato inserido com sucesso.\n");
                break;
            case 2:
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removerContato(&tabela, nome);
                printf("\nContato removido com sucesso.\n");
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                resultadoBusca = buscarContato(tabela, nome);
                if (resultadoBusca != NULL) {
                    printf("\nInformacoes do contato: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
                } else {
                    printf("\nContato nao encontrado.\n");
                }
                break;
            case 4:
                printf("Digite a posicao da tabela hash: ");
                scanf("%d", &posicao);
                if (posicao < 0 || posicao >= TAMANHO_TABELA) {
                    printf("\nPosição invalida. Tente novamente.\n");
                } else {
                    No *atual = tabela.vetor[posicao];
                    if (atual == NULL) {
                        printf("\nNao ha contatos na posicao %d.\n", posicao);
                    } else {
                        printf("\nContatos na posicao %d:\n", posicao);
                        while (atual != NULL) {
                            printf("Nome: %s, Telefone: %s, Email: %s\n", atual->contato.nome, atual->contato.telefone, atual->contato.email);
                            atual = atual->prox;
                        }
                    }
                }
                break;
            case 5:
                printf("Numero de colisoes: %d\n", colisoes);
                break;
            case 6:
                printf("Saindo...\n"); // Encerra o programa
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
     } while (opcao != 6); // Loop continua até que o usuário escolha a opção para sair

    liberarTabelaHash(&tabela); // Libera a memória alocada para a tabela hash

    return 0;
}