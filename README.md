# Tabela Hash

Este projeto é uma implementação de uma tabela hash em C com o objetivo de gerenciar contatos de forma eficiente.

## Funcionalidades

- **Inserção de Contatos:** Permite adicionar novos contatos à lista.
- **Busca de Contatos:** Permite encontrar um contato pelo nome.
- **Remoção de Contatos:** Permite excluir um contato da lista.
- **Estatísticas de Colisões:** Mostra o número de colisões ocorridas durante a inserção de contatos.
- **Capacidade de Armazenamento Otimizada:** Utiliza uma tabela hash com encadeamento exterior para armazenar os contatos de forma eficiente.

## Descrição

O projeto consiste em três partes principais:

1. `hash.h`: Este é o arquivo de cabeçalho que define as estruturas de dados e as funções para manipular a tabela hash.

2. `hash.c`: Este é o arquivo de implementação que contém as definições das funções declaradas em `hash.h`.

3. `main.c`: Este é o arquivo principal que usa as funções definidas em `hash.h` e `hash.c` para criar uma tabela hash de contatos.

O programa lê contatos de um arquivo chamado `contatos.txt` e insere-os na tabela hash. Em seguida, fornece um menu principal para o usuário interagir com o programa. O usuário pode inserir um contato, remover um contato, buscar um contato e visualizar o número de colisões na tabela hash.

## Compilação e Execução

Para compilar o programa, você pode usar o seguinte comando:

```bash
gcc -o main main.c hash.c
```

Para executar o programa, você pode usar o seguinte comando:

```bash
./main
```