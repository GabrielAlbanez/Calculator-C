#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXPRODUCTS 10
#define MAXCLIENTES 2
#define MAXCARRINHO 1

typedef struct
{
    int id;
    char nome[100];
    float preco;
    int quantidade; 
} product;

typedef struct
{
    char name[100];
    int idade;
    int lenghProducts;
    product produtos[MAXPRODUCTS];
} Cliente;

typedef struct
{
    Cliente cliente[MAXCLIENTES];
} Carrinho;

product *createDataProducts()
{
    product *produtos = malloc(MAXPRODUCTS * sizeof(product));
    if (produtos == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para os produtos.\n");
        return NULL;
    }

    for (int i = 0; i < MAXPRODUCTS; i++)
    {
        produtos[i].id = i;
        produtos[i].quantidade = 0; 
    }

    strcpy(produtos[0].nome, "Coca");
    produtos[0].preco = 10.50;
    strcpy(produtos[1].nome, "Pão");
    produtos[1].preco = 2.50;
    strcpy(produtos[2].nome, "Fanta");
    produtos[2].preco = 6.30;
    strcpy(produtos[3].nome, "7Belo");
    produtos[3].preco = 0.50;
    strcpy(produtos[4].nome, "Douritos");
    produtos[4].preco = 14.30;
    strcpy(produtos[5].nome, "BatataDoce");
    produtos[5].preco = 8.50;
    strcpy(produtos[6].nome, "Beterraba");
    produtos[6].preco = 6.50;
    strcpy(produtos[7].nome, "Alface");
    produtos[7].preco = 7.50;
    strcpy(produtos[8].nome, "Repolho");
    produtos[8].preco = 16.50;
    strcpy(produtos[9].nome, "Arroz");
    produtos[9].preco = 20.50;

    return produtos;
}

Carrinho *createDataCarrinho(product *produtos)
{
    Carrinho *carrinho = malloc(MAXCARRINHO * sizeof(Carrinho));
    if (carrinho == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o carrinho.\n");
        return NULL;
    }

    for (int l = 0; l < MAXCLIENTES; l++)
    {
        int pl = 0;
        bool continuarEscolhendo = true;
        printf("Digite seu nome: \n");
        scanf("%s", carrinho->cliente[l].name);
        printf("Digite sua idade: \n");
        scanf("%d", &carrinho->cliente[l].idade);
        printf("Bem vindo %s ao nosso mercado\n", carrinho->cliente[l].name);
        printf("Produtos disponíveis na loja\n");
        printf("---------------------------------\n");
        for (int p = 0; p < MAXPRODUCTS; p++)
        {
            printf("id - %d | nome - %s | preco - %.2f\n", produtos[p].id, produtos[p].nome, produtos[p].preco);
        }
        while (continuarEscolhendo)
        {
            int escolhaProduto;
            printf("Para escolher o produto, digite o id ao lado dele: ");
            scanf("%d", &escolhaProduto);
            printf("Quantidade: ");
            scanf("%d", &produtos[escolhaProduto].quantidade); 
            carrinho->cliente[l].produtos[pl] = produtos[escolhaProduto];
            printf("Deseja escolher mais um produto? Se sim, digite 1; se não, digite 2: ");
            int escolhaUser;
            scanf("%d", &escolhaUser);
            if (escolhaUser == 2)
            {
                continuarEscolhendo = false;
            }
            pl++;
        }
        carrinho->cliente[l].lenghProducts = pl;
        system("cls");
    }

    return carrinho;
}

void listeningDataCarrinho(Carrinho *carrinho)
{
    for (int i = 0; i < MAXCLIENTES; i++)
    {
        printf("Carrinho de %s\n", carrinho->cliente[i].name);
        printf("-----------------------------------------\n");
        for (int l = 0; l < carrinho->cliente[i].lenghProducts; l++)
        {
            printf("Nome: %s | Preço: %.2f | Quantidade: %d | Toal : %.2f\n", carrinho->cliente[i].produtos[l].nome, carrinho->cliente[i].produtos[l].preco, carrinho->cliente[i].produtos[l].quantidade, carrinho->cliente[i].produtos[l].preco * carrinho->cliente[i].produtos[l].quantidade);
        }
        printf("-----------------------------------------\n");
    }
}

int main(void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    product *Products = createDataProducts();
    Carrinho *carrinho = createDataCarrinho(Products);
    listeningDataCarrinho(carrinho);
    free(Products);
    free(carrinho);
    return 0;
}
