#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_CLIENTES 2
#define MAX_SESSOES 2
#define MAX_FILMES 2
#define MAX_INGRESSOS 1
#define MAX_CINEMAS 2

typedef struct
{
    int id;
    float preco;
    float preco_faxetaria;
} ingresso_session;

typedef struct
{
    int id;
    char sala[100];
    char hora[100];
    int quantidadeAssentos;
    int quantidadeIngressos;
    ingresso_session ingressoSession[MAX_INGRESSOS];
} session;

typedef struct
{
    int id;
    char nome[100];
    char data[100];
    char time[100];
    char genero[100];
    session sessions[MAX_SESSOES];
} filme;

typedef struct
{
    int id;
    char nome[100];
    filme filmesDisponiveis[MAX_FILMES];
} cinema;

typedef struct
{
    char name[100];
    int idade;
} Cliente;

cinema *createDataCinemas()
{
    cinema *cinemas = malloc(MAX_CINEMAS * sizeof(cinema));
    if (cinemas == NULL)
    {
        fprintf(stderr, "Erro ao alocar o cinemas memória.\n");
        return 0;
    }

    puts("Criando cinemas\n");

    strcpy(cinemas[0].nome, "Kinoplex");
    strcpy(cinemas[1].nome, "Cinemark");

    for (int i = 0; i < MAX_CINEMAS; i++)
    {
        cinemas[i].id = i + 1;
        for (int j = 0; j < MAX_FILMES; j++)
        {
            cinemas[i].filmesDisponiveis[j].id = j + 1;
            printf("Digite o nome do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].nome);
            printf("Digite o gênero do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].genero);
            printf("Digite a data (dd/mm/aaaa) do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].data);
            printf("Digite o tempo do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].time);
            for (int s = 0; s < MAX_SESSOES; s++)
            {
                cinemas[i].filmesDisponiveis[j].sessions[s].id = s + 1;
                printf("Digite o nome da sala: ");
                scanf("%s", cinemas[i].filmesDisponiveis[j].sessions[s].sala);
                printf("Digite a hora da sessão (hh:mm): ");
                scanf("%s", cinemas[i].filmesDisponiveis[j].sessions[s].hora);
                printf("Digite a quantidade de assentos: ");
                scanf("%d", &cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeAssentos);
                printf("Digite a quantidade de ingressos: ");
                scanf("%d", &cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeIngressos);

                for (int ig = 0; ig < MAX_INGRESSOS; ig++)
                {
                    cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].id = ig + 1;
                    printf("Digite o preço total do ingresso: ");
                    scanf("%f", &cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco);
                    printf("Digite o preço da meia entrada do ingresso: ");
                    scanf("%f", &cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco_faxetaria);
                }
            }
        }
    }

    return cinemas;
}

void printCinemaData(cinema *cinemas)
{
    printf("\n\nDados dos cinemas:\n");
    printf("==========================================================\n");

    for (int i = 0; i < MAX_CINEMAS; i++)
    {
        printf("Cinema %d - ID: %d | Nome: %s\n", i + 1, cinemas[i].id, cinemas[i].nome);
        printf("----------------------------------------------------------\n");
        for (int j = 0; j < MAX_FILMES; j++)
        {
            printf("Filme %d - ID: %d | Nome: %s | Gênero: %s | Dia: %s\n", j + 1, cinemas[i].filmesDisponiveis[j].id, cinemas[i].filmesDisponiveis[j].nome, cinemas[i].filmesDisponiveis[j].genero, cinemas[i].filmesDisponiveis[j].data);
            for (int s = 0; s < MAX_SESSOES; s++)
            {
                printf("Sessão %d - ID: %d | Sala: %s  | Hora: %s | Assentos: %d | Ingressos: %d\n", s + 1, cinemas[i].filmesDisponiveis[j].sessions[s].id, cinemas[i].filmesDisponiveis[j].sessions[s].sala, cinemas[i].filmesDisponiveis[j].sessions[s].hora, cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeAssentos, cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeIngressos);
                for (int ig = 0; ig < MAX_INGRESSOS; ig++)
                {
                    printf("Ingresso %d - ID: %d | Preço: %.2f | Preço da meia: %.2f\n", ig + 1, cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].id, cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco, cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco_faxetaria);
                }
            }
            printf("Filmes e Cinemas Criado com sucesso\n");
            sleep(10);
            system("cls");
        }
    }
}

Cliente *createListenincCLientes(cinema *cinema)
{

    Cliente *clientes = malloc(MAX_CLIENTES * sizeof(Cliente));
    if (clientes == NULL)
    {
        fprintf(stderr, "Erro ao alocar o cinemas memória.\n");
        return 0;
    }

    for (int i = 0; i < MAX_CLIENTES; i++)
    {
        printf("Digite seu nome: ");
        scanf("%s", clientes[i].name);
        printf("Digite sua idade: ");
        scanf("%d", &clientes[i].idade);
        system("cls");
        printf("Bem-vindo %s!\n", clientes[i].name);

        for (int j = 0; j < MAX_CINEMAS; j++)
        {
            printf("Escolha um dos cinemas para assistir um filme:\n");
            printf("%s\n", cinema[j].nome);
        }
    }

    return clientes; // Retorna o ponteiro para a estrutura de clientes
}

int main(void)
{
    cinema *cinemas = createDataCinemas();
    Cliente *clientes = createListenincCLientes(cinemas);
    if (clientes == NULL)
    {
        // Tratar erro de alocação de memória para clientes
        // Por exemplo, imprimir uma mensagem de erro e sair do programa
        fprintf(stderr, "Erro ao criar clientes.\n");
        return 1;
    }
    printCinemaData(cinemas);
    free(cinemas);
    return 0;
}
