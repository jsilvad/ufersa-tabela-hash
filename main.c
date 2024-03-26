#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define LINHA_TAMANHO 120

int main() {
    TabelaHash tabela;
    inicializarTabelaHash(&tabela); // Inicializa a tabela hash

    FILE *file = fopen("contatos.txt", "r"); // Abre o arquivo contatos.txt para leitura
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo contatos.txt.\n");
        return 1;
    }

    Contato contato;
    int colisoes = 0;
    char linha[LINHA_TAMANHO];
    // Lê os dados do arquivo contatos.txt e insere na tabela hash
    while (fgets(linha, sizeof(linha), file)) {
        // Extrai os dados de cada linha do arquivo para um contato
        sscanf(linha, "Nome: %[^\n]", contato.nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Telefone: %[^\n]", contato.telefone);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Email: %[^\n]", contato.email);
        unsigned int indice = funcaoHash(contato.nome);
        // Verifica se houve colisão ao inserir o contato na tabela hash
        if (tabela.vetor[indice] != NULL) {
            colisoes++;
        }
        inserirContato(&tabela, contato); // Insere o contato na tabela hash
    }

    fclose(file); // Fecha o arquivo após a leitura dos contatos

    int opcao;
    char nome[50];
    char telefone[15];
    char email[40];
    No *resultadoBusca;

    // Menu principal para interação com o usuário
    do {
        printf("\n---------------- MENU ----------------\n");
        printf("1. Inserir um contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar um contato\n");
        printf("4. Listar numero de colisoes\n\n");
        printf("5. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Solicita ao usuário os dados do novo contato a ser inserido
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
                inserirContato(&tabela, novoContato); // Insere o novo contato na tabela hash
                printf("\nContato inserido com sucesso.\n");
                break;
            case 2:
                // Solicita ao usuário o nome do contato a ser removido
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removerContato(&tabela, nome);
                printf("\nContato removido com sucesso.\n");
                break;
            case 3:
                // Solicita ao usuário o nome do contato a ser buscado
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                resultadoBusca = buscarContato(tabela, nome);
                if (resultadoBusca != NULL) {
                    // Exibe os dados do contato encontrado
                    printf("\nContato encontrado: %s, %s, %s\n", resultadoBusca->contato.nome, resultadoBusca->contato.telefone, resultadoBusca->contato.email);
                } else {
                    printf("\nContato nao encontrado.\n");
                }
                break;
            case 4:
                printf("Numero de colisoes: %d\n", colisoes); // Exibe o número de colisões na tabela hash
                break;
            case 5:
                printf("Saindo...\n"); // Encerra o programa
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5); // Loop continua até que o usuário escolha a opção para sair

    liberarTabelaHash(&tabela); // Libera a memória alocada para a tabela hash

    return 0;
}