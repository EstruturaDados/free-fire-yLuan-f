#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// struct para representar um item na mochila
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// vetor para armazenar os itens na mochila

struct Item Mochila[MAX_ITENS];
int totalItens = 0;

void inserirItem(){
    if (totalItens >= MAX_ITENS)
    {
        printf("Mochila cheia! Nao e possivel adicionar mais itens\n");
    } else {
        printf("\nDigite o nome do item:\n");
        scanf("%s", Mochila[totalItens].nome);

        printf("\nDigite o tipo do item:\n");
        scanf("%s", Mochila[totalItens].tipo);

        printf("\nDigite a quantidade de itens:\n");
        scanf("%d", &Mochila[totalItens].quantidade);

        totalItens++;

        printf("O item foi adicionado!\n");
    }
}

// Função para remover um item da mochila

void removerItem(){
    char nomeRemov[30];
    int posicaoRemov = -1;

    printf("Digite o nome do item que deve ser removido: \n");
    scanf("%s", nomeRemov);

    for (int i = 0; i < totalItens; i++)
    {
        if (strcmp(Mochila[i].nome, nomeRemov) == 0) {
            posicaoRemov = i;
            break;
        }
    }

    if (posicaoRemov == -1){
        printf("Item nao encontrado!\n");
        return;
    }

    for (int i = posicaoRemov; i < totalItens - 1; i++)
    {
        Mochila[i] = Mochila[i + 1];
    }
    totalItens--;
    printf("O item %s foi removido!\n", nomeRemov);
}

// funcao para listar os itens na mochila

void listarItens() {
    printf("\n======== ITENS NA MOCHILA ======== \n");

    if (totalItens == 0) {
        printf("A mochila esta vazia!\n");
    }
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n", Mochila[i].nome, Mochila[i].tipo, Mochila[i].quantidade);
    }

    printf("==================================\n");
}

// funcao para buscar um item na mochila e exibir seus detalhes
void buscarItem(){
    char nomeBusca[30];
    int encontrado = 0;

    printf("Digite o nome do item que deseja procurar: \n");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++)
    {
        if (strcmp(Mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado! \n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n", Mochila[i].nome, Mochila[i].tipo, Mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Item nao encontrado!\n");
    }
}
// funcao principal do programa

int main() {
    int opcao;

    // loop principal do menu
    do {
        printf("===============================\n");
        printf("ADMINISTRACAO DE ITENS - MOCHILA\n");
        printf("===============================\n");

    listarItens();

       printf("Selecione uma das opcoes a seguir:\n");
       printf("1. Inserir item.\n");
       printf("2. Remover item.\n");
       printf("3. Listar itens. \n");
       printf("4. Buscar item por nome. \n");
       printf("5. Sair. \n");
       scanf("%d", &opcao);

         switch (opcao)
         {
         case 1:
             inserirItem();
             listarItens();
             break;
         case 2:
             removerItem();
             listarItens();
             break;
         case 3:
             listarItens();
             break;
         case 4:
             buscarItem();
             break;
         case 5:
             printf("Saindo do programa. Ate mais!\n");
             break;
         default:
             printf("Opcao invalida! Por favor, selecione uma opcao valida.\n");
             break;
         }

        } while (opcao != 5);

// fim do loop principal

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
