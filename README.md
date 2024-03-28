# Tabela Hash

Este projeto é uma implementação de uma tabela hash em C com o objetivo de gerenciar contatos de forma eficiente, utilizando a função de hash de dobra com tratamento de colisão por encadeamento exterior.

## Funcionalidades

- **Inserção de Contatos:** Permite adicionar novos contatos à lista.
- **Busca de Contatos:** Permite encontrar um contato pelo nome.
- **Remoção de Contatos:** Permite excluir um contato da lista.
- **Estatísticas de Colisões:** Mostra o número de colisões ocorridas durante a inserção de contatos.

## Descrição

O projeto consiste em três partes principais:

1. `hash.h`: Este é o arquivo de cabeçalho que define as estruturas de dados e as funções para manipular a tabela hash.

2. `hash.c`: Este é o arquivo de implementação que contém as definições das funções declaradas em `hash.h`.

3. `main.c`: Este é o arquivo principal que usa as funções definidas em `hash.h` e `hash.c` para criar uma tabela hash de contatos.

O programa lê contatos de um arquivo chamado `contatos.txt` e insere-os na tabela hash. Em seguida, fornece um menu principal para o usuário interagir com o programa. O usuário pode inserir um contato, remover um contato, buscar um contato e visualizar o número de colisões na tabela hash.

## Observações

### Interface Gráfica

A interface gráfica foi implementada usando a biblioteca padrão de I/O do C. O programa fornece um menu principal onde o usuário pode escolher entre várias opções para interagir com a tabela hash.

### Problemas

Durante o desenvolvimento do projeto, encontramos alguns desafios:

- **Colisões na Tabela Hash:** As colisões são um problema comum ao usar tabelas hash. Utilizando o método de encadeamento exterior, onde cada posição na tabela contém uma lista encadeada de contatos, houve um pouco de dificuldade no entendimento de como funcionaria esse tipo de tratamento.

- **Leitura de Arquivos:** Tivemos que garantir que o arquivo `contatos.txt` fosse lido corretamente e que os contatos fossem inseridos na tabela hash, modificando a lista de contatos pré-definida.

### Justificativas e Mudanças

- **Alteração na lista pré-definida "contatos.txt:"** A alteração foi feita no arquivo da lista de contatos para remover o espaço entre os contatos. Isso foi feito para simplificar a leitura do arquivo, pois cada contato agora é seguido imediatamente pelo próximo contato sem espaços intermediários. Isso torna mais fácil determinar onde um contato termina e o próximo começa, simplificando o código de leitura do arquivo.

## Compilação e Execução

Para compilar o programa, você pode usar o seguinte comando:

```bash
gcc -o main main.c hash.c
```

Para executar o programa, você pode usar o seguinte comando:

```bash
./main
```
