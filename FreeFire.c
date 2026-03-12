#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// definicao de constantes
#define MAX_ITENS 20

// variavel global para controle da ordenacao por nome
int condicaobinaria = 0;

// funcao para limpar buffer

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
}

// struct para representar um item na mochila
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
};

// vetor para armazenar os itens na mochila

struct Item Mochila[MAX_ITENS];
int totalItens = 0;

// funcao para inserir um item na mochila
void inserirItem(){
    if (totalItens >= MAX_ITENS)
    {
        printf("Mochila cheia! Nao e possivel adicionar mais itens\n");
        return;
    }

    limparBuffer();

    printf("\nDigite o nome do item:\n");
    fgets(Mochila[totalItens].nome, sizeof(Mochila[totalItens].nome), stdin);
    Mochila[totalItens].nome[strcspn(Mochila[totalItens].nome, "\n")] = '\0'; 

    printf("\nDigite o tipo do item:\n");
    fgets(Mochila[totalItens].tipo, sizeof(Mochila[totalItens].tipo), stdin);
    Mochila[totalItens].tipo[strcspn(Mochila[totalItens].tipo, "\n")] = '\0';

    printf("\nDigite a quantidade de itens:\n");
    scanf("%d", &Mochila[totalItens].quantidade);
    
    printf("\n Digite a prioridade do item (1 a 10): \n");
    scanf("%d", &Mochila[totalItens].prioridade);

    limparBuffer();

    totalItens++;
    condicaobinaria = 0;    

    printf("O item foi adicionado!\n");
}

// Função para remover um item da mochila

void removerItem(){
    limparBuffer();
    char nomeRemov[30];
    int posicaoRemov = -1;

    printf("Digite o nome do item que deve ser removido: \n");
    fgets(nomeRemov, sizeof(nomeRemov), stdin);
    nomeRemov[strcspn(nomeRemov, "\n")] = '\0';

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
    condicaobinaria = 0;

    printf("O item %s foi removido!\n", nomeRemov);
}

// funcao para listar os itens na mochila

void listarItens() {
    printf("\n======== ITENS NA MOCHILA ======== \n");

    if (totalItens == 0) {
        printf("A mochila esta vazia!\n");
        printf("==================================\n");
        return;
    }
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n", Mochila[i].nome, Mochila[i].tipo, Mochila[i].quantidade, Mochila[i].prioridade);
    }

    printf("==================================\n");
}

// funcao para buscar um item na mochila e exibir seus detalhes
void buscarItem(){

    if (!condicaobinaria) {
        printf("A lista precisa estar ordenada alfabeticamente primeiro!\n");
        printf("Use a opcao de ordenar antes de fazer busca binaria.\n");
        return;
    }
    if (totalItens == 0) {
        printf("A Mochila esta vazia! \n");
        return;
    }

    char nomeBusca[30];

    limparBuffer();

    printf("Digite o nome do item que deseja buscar: \n");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] ='\0'; 

    int inicio = 0;
    int fim = totalItens - 1;
    int meio;

    while (inicio <= fim) {

        meio = (inicio + fim) / 2;

        int resultado = strcmp(Mochila[meio].nome, nomeBusca);

        if (resultado == 0) {
            printf("\n Item encontrado! \n");
            printf("\n 2Nome: %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n", Mochila[meio].nome, Mochila[meio].tipo, Mochila[meio].quantidade, Mochila[meio].prioridade);
            return;
        } else if (resultado < 0) {
            fim = meio - 1; 
        } else {
            inicio = meio + 1;
        }
    }

    printf("\n Item nao encontrado! \n");
}

void ordenacao() {
    int escolha;

    printf("Escolha um criterio de ordenacao para sua mochila:\n");

    printf("\n1. Ordernar por ordem alfabetica (A - Z).\n");
    printf("2. Ordernar por prioridade (Maior valor para o menor).\n");
    printf("3. Ordernar por tipo.\n");
    scanf("%d", &escolha);

    
    switch (escolha)
    {
        // ordenacao por nome usando bubble sort
    case 1:

    for (int i = 1; i < totalItens - 1; i++) {
    
        for (int j = 1; j < totalItens - 1; j++) {
          
            if (strcmp(Mochila[j].nome, Mochila[j + 1].nome) > 0) {
                
                struct Item temp = Mochila[j];
                Mochila[j] = Mochila[j + 1];
                Mochila[j + 1] = temp;
            }
        }
    }

    // apos ordenar por nome, a busca binaria pode ser realizada, entao a variavel de controle condicaobinaria e ajustada para 1

    condicaobinaria = 1;

    printf("A mochila foi ordenada em ordem alfabeica! \n");

        break;
        // ordenacao por prioridade usando insertion sort
    case 2:

        for (int i = 1; i < totalItens; i++) {

            struct Item chave = Mochila[i];
            int j = i - 1;

            while (j >= 0 && Mochila[j].prioridade < chave.prioridade) {
                Mochila[j + 1] = Mochila[j];
                j--;
            }
            
            Mochila[j + 1] = chave;
        }

        printf("A mochila foi ordenada por prioridade! \n");

        break;
        // ordenacao por tipo usando selection sort
    case 3:
        
    for (int i = 0; i < totalItens - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < totalItens; j++) {

            if (strcmp(Mochila[j].tipo, Mochila[menor].tipo) < 0) {
                menor = j;
            }
        }

        if (menor != i) {

            struct Item temp;

            temp = Mochila[i];
            Mochila[i] = Mochila[menor];
            Mochila[menor] = temp;
        }
    }

    printf("Itens ordenados por tipo!\n");

        break;
    default:

        printf("Opcao invalida! A mochila nao foi ordenada.\n");
        break;
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

       printf("Selecione uma das opcoes a seguir:\n");
       printf("1. Inserir item.\n");
       printf("2. Remover item.\n");
       printf("3. Listar itens. \n");
       printf("4. Buscar item por nome. \n");
       printf("5. Ordenar itens. \n");
       printf("6. Sair.\n");
       scanf("%d", &opcao);

         switch (opcao)
         {
         case 1:
             limparTela();
             inserirItem();
             break;
         case 2:
             limparTela();
             removerItem();
             break;
         case 3:
             limparTela();
             listarItens();
             break;
         case 4:
             limparTela();
             buscarItem();
             break;
         case 5:
             limparTela();
             ordenacao();
             break;
         case 6:
             limparTela();
             printf("Saindo do programa.\n");
             break;
         default:
             printf("Opcao invalida! Por favor, selecione uma opcao valida.\n");
             break;
         }

        } while (opcao != 6);

// fim do loop principal

    return 0;
}

