# INF/UFG 2025-1 — AED2 — Atividade Supervisionada 2

## Tema: Dicionário com Autocompletar na Árvore AVL

### Questão 1 (10,0 pontos)

## 1. Visão Geral

O programa é um Dicionário com Autocompletar baseado em uma árvore AVL, projetado para armazenar
e consultar palavras de forma eficiente. Ele permite ao usuário buscar palavras por prefixo e receber
sugestões automáticas em ordem alfabética, aproveitando a estrutura balanceada da AVL para garantir
desempenho logarítmico em operações de inserção e busca.

## 2. Requisitos Funcionais

Os requisitos funcionais descrevem o que o sistema deve fazer:

### 1. RF1 - Inserção de Palavras

* **Descrição:** O sistema deve permitir a inserção de palavras no dicionário.
* **Entrada:** Uma string representando a palavra (ex.: "apple").
* **Saída:** A palavra é adicionada à AVL, mantendo a propriedade de balanceamento.
* **Restrições:**
  * Palavras duplicadas são ignoradas.
  * Suporta apenas palavras com caracteres alfanuméricos (sem espaços ou caracteres
    especiais, a menos que especificado).
* **Complexidade:** O(log n), onde n é o número de palavras na AVL.

### 2. RF2 - Busca por Prefixo com Autocompletar

* **Descrição:** O sistema deve listar todas as palavras que começam com um prefixo fornecido
  pelo usuário.
* **Entrada:** Uma string representando o prefixo (ex.: "ap").
* **Saída:** Uma lista ordenada alfabeticamente de palavras que começam com o prefixo (ex.:
  "apple", "application").
* **Restrições:**
  * Se nenhuma palavra corresponder ao prefixo, exibir mensagem "Nenhuma sugestão
    encontrada".
* **Complexidade:** O(log n + k), onde k é o número de palavras com o prefixo.

### 3. RF3 - Carregamento de Vocabulário Inicial

* **Descrição:** O sistema deve permitir carregar um conjunto inicial de palavras a partir de uma
  fonte (ex.: array ou arquivo).
* **Entrada:** Lista de palavras (ex.: array em memória ou arquivo de texto).
* **Saída:** As palavras são inseridas na AVL.
* **Restrições:**
  * Formato do arquivo (se usado): uma palavra por linha.
* **Complexidade:** O(n log n) para n palavras.

### 4. RF4 - Interface Interativa

* **Descrição:** O sistema deve fornecer uma interface de linha de comando para interação com o
  usuário.
* **Entrada:** Comandos do usuário (ex.: prefixo a pesquisar, opção de sair).
* **Saída:** Resultados das consultas ou mensagens de status.
* **Restrições:**
  * Suporte a entrada contínua até o usuário encerrar (ex.: Ctrl+D ou comando "sair").

### 5. RF5 - Liberação de Memória

* **Descrição:** O sistema deve liberar toda a memória alocada ao encerrar.
* **Entrada:** Nenhuma (automático ao fim do programa).
* **Saída:** Árvore AVL e strings associadas desalocadas.
* **Complexidade:** O(n) para percorrer e liberar n nós.

## 3. Requisitos Não Funcionais

Os requisitos não funcionais definem as qualidades do sistema:

### 1. RNF1 - Eficiência

* Operações de inserção e busca devem ser realizadas em tempo logarítmico (O(log n)).
* O autocompletar deve listar sugestões em O(log n + k), onde k é o número de resultados.

### 2. RNF2 - Escalabilidade

* O sistema deve suportar pelo menos 10.000 palavras sem degradação significativa de
  desempenho.
* Memória deve ser alocada dinamicamente para evitar limites fixos.

### 3. RNF3 - Robustez

* O sistema deve tratar entradas inválidas (ex.: strings vazias) com mensagens claras.
* Não deve falhar ou vazar memória em caso de uso intensivo.

### 4. RNF4 - Manutenibilidade

* O código deve ser modular, com funções separadas para inserção, busca, autocompletar e
  gerenciamento de memória.
* Comentários devem documentar a lógica principal.

### 5. RNF5 - Portabilidade

* O sistema deve ser compilável em qualquer ambiente C padrão (ex.: gcc em
  Linux/Windows).

## 4. Funcionalidades do Sistema

Aqui estão as funcionalidades detalhadas, mapeadas aos requisitos:

### 1. Estrutura de Dados: Árvore AVL

* Implementação de uma árvore AVL com nós contendo:
  * `char *word`: A palavra armazenada.
  * `int height`: Altura do nó para balanceamento.
  * `Node *left, Node *right`: Ponteiros para subárvores.
* Funções básicas:
  * `insert`: Insere uma palavra (RF1).
  * `height, getBalance, rightRotate, leftRotate`: Mantêm o balanceamento.

### 2. Autocompletar por Prefixo

* Função `findFirstPrefix`: Localiza o primeiro nó com o prefixo em O(log n).
* Função `inorderPrefix`: Lista palavras a partir do nó encontrado em ordem alfabética (RF2).
* Suporte a mensagem de "nenhuma sugestão" se o prefixo não corresponder a nada.

### 3. Carregamento de Dados

* Função `loadVocabulary`: Carrega palavras de um array ou arquivo (RF3).
* Iteração sobre a fonte para inserção na AVL.

### 4. Interface de Usuário

* Loop interativo para receber prefixos do usuário, um caractere por vez via scanf (RF4).
* Exibição de resultados com formatação clara (ex.: "Sugestões para 'ap':").

### 5. Gerenciamento de Memória

* Função `freeTree`: Libera todos os nós e strings da AVL (RF5).

## 5. Casos de Uso

### Caso 1: Inserir Vocabulário
* **Ator:** Sistema
* **Pré-condição:** AVL vazia
* **Fluxo:** Carrega palavras de um array → Insere cada uma na AVL
* **Pós-condição:** AVL contém todas as palavras

### Caso 2: Consultar Prefixo
* **Ator:** Usuário
* **Pré-condição:** AVL populada
* **Fluxo:** Usuário digita "ap" → Sistema lista "apple", "application" → Exibe resultados
* **Pós-condição:** Sugestões exibidas ou mensagem de "nenhuma sugestão"

### Caso 3: Encerrar Programa
* **Ator:** Usuário
* **Pré-condição:** Sistema em execução
* **Fluxo:** Usuário usa Ctrl+D → Sistema libera memória → Encerra
* **Pós-condição:** Memória limpa, programa encerrado

---

**Equipe de execução:** Grupo de até 3 membros.

**Forma de entrega:**
Compactar todos os arquivos .dev (projeto), .c e .h do projeto e atribuir nome ao arquivo .zip no seguinte
formato: AS1_<primeiroNomeAluno><ultimoNomeAluno>.zip.

Exemplo: AS1_JoaoNaves.zip

Postar o arquivo .ZIP no SIGAA.

**Data de entrega:**
Até 08/04/2025

**Importante:**
1. Não serão aceitas entregas por e-mail.
2. Será atribuído nota 0 (zero) à atividade cujo código postado apresentar erro(s) de compilação.
3. No arquivo que contém a função 'main', deve constar, em ordem alfabética, o nome completo de cada um
dos estudantes.
4. Deve-se entregar também o projeto (arquivo .dev) no pacote compactado.