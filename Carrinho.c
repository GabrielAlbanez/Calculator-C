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
    char nome;
    float preco;
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
        fprintf(stderr, "Erro ao alocar os produtos memória.\n");
        return NULL;
    }

    for (int i = 0; i < MAXPRODUCTS; i++)
    {
        produtos[i].id = i;
    }

    strcpy(produtos[0].nome, "Coca");
    produtos[0].preco = 10.50;
    strcpy(produtos[1].nome, "Pão");
    produtos[1].preco = 2.50;
    strcpy(produtos[2].nome, "fanta");
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
};

Carrinho *createDataCarrinho(product *produtos)
{

    Carrinho *carrinho = malloc(MAXCARRINHO * sizeof(Carrinho));
    if (carrinho == NULL)
    {
        fprintf(stderr, "Erro ao alocar o carrinho na memória.\n");
        return NULL;
    }

    for (int i = 0; i < MAXCARRINHO; i++)
    {
        for (int l = 0; l < MAXCLIENTES; l++)
        {
            int escolhaProduto;
            bool continarEscolhendo;
            int pl;
            printf("digite seu nome: \n");
            scanf("%s", carrinho->cliente[l].name);
            printf("digite sua idade: \n");
            scanf("%s", carrinho->cliente[l].idade);
            system("cls");
            printf("Bem vindo %s ao nosso mercado\n", carrinho->cliente[l].name);
            printf("produtos disponiveis na loja\n");
            printf("---------------------------------\n");
            for (int p = 0; p < MAXPRODUCTS; p++)
            {
                printf("id - %d | nome - %s | preco - %f\n", produtos[p].id, produtos[p].nome, produtos[p].preco);
            }
            while (continarEscolhendo == true)
            {
                int escolhaUser;
                printf("para escolher o produto basta digitar o id ao lado dele\n");
                scanf("%d", &escolhaProduto);
                carrinho->cliente[l].produtos[pl].preco = produtos[escolhaProduto].preco;
                strcpy(carrinho->cliente[l].produtos[pl].nome, produtos[escolhaProduto].nome);
                printf("deseha escolher mais um produto, se sim digite : 1 se não digite 2\n");
                scanf("%d", &escolhaUser);
                if (escolhaUser == 2)
                {
                    continarEscolhendo = false;
                }
                else
                {
                    continarEscolhendo = true;
                }
                pl++;
            }

            carrinho->cliente[l].lenghProducts = pl;
        }
    }

    return carrinho;
};

void listeningDataCarrinho(Carrinho *carrinho)
{

    for (int i = 0; i < MAXCLIENTES; i++)
    {
        printf("Carrinho de %s\n", carrinho->cliente[i].name);
        printf("-----------------------------------------\n");
        for (int l = 0; l < carrinho->cliente[i].lenghProducts; i++)
        {
            printf("nome : %s | preco : %f", carrinho->cliente[i].produtos[l].nome, carrinho->cliente[i].produtos[l].preco);
        }
    }
};

int main(void)

{
    product *Products = createDataProducts();
    Carrinho *carrinho = createDataCarrinho(Products);
    listeningDataCarrinho(carrinho);

    return 0;
}
