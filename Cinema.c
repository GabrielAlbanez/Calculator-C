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

    char sala[100];
    char horario[100];

} sessaoClientEscolha;

typedef struct
{

    char cinema[100];
    char filmes[100];
    char dataFilme[100];
    sessaoClientEscolha sessoes[MAX_SESSOES];
    float ingressos;
    int assentos;

} EcolhaClient;

typedef struct
{
    char name[100];
    int idade;
    EcolhaClient escolha;

} Cliente;

cinema *createDataCinemas()
{

    cinema *cinemas = malloc(MAX_CINEMAS * sizeof(cinema));
    if (cinemas == NULL)
    {
        fprintf(stderr, "Erro ao alocar o cinemas memória.\n");
        return NULL;
    }

    strcpy(cinemas[0].nome, "Kinoplex");
    strcpy(cinemas[1].nome, "Cinemark");

    for (int i = 0; i < MAX_CINEMAS; i++)
    {
        cinemas[i].id = i;
        printf("Criando os filmes do cinema: %s\n", cinemas[i].nome);
        puts("--------------------------------------");
        for (int j = 0; j < MAX_FILMES; j++)
        {
            cinemas[i].filmesDisponiveis[j].id = j;
            printf("digite as informações do %d filme\n", cinemas[i].filmesDisponiveis[j].id + 1);
            printf("Digite o nome do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].nome);
            printf("Digite o gênero do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].genero);
            printf("Digite a data (dd/mm/aaaa) do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].data);
            printf("Digite o tempo do filme: ");
            scanf("%s", cinemas[i].filmesDisponiveis[j].time);
            puts("--------------------------------");
            for (int s = 0; s < MAX_SESSOES; s++)
            {
                cinemas[i].filmesDisponiveis[j].sessions[s].id = s;
                printf("digite as informações da %d sessão do filme: %s\n", cinemas[i].filmesDisponiveis[j].sessions[s].id + 1, cinemas[i].filmesDisponiveis[j].nome);
                printf("Digite o nome da sala: ");
                scanf("%s", cinemas[i].filmesDisponiveis[j].sessions[s].sala);
                printf("Digite a hora da sessão (hh:mm): ");
                scanf("%s", cinemas[i].filmesDisponiveis[j].sessions[s].hora);
                printf("Digite a quantidade de assentos: ");
                scanf("%d", &cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeAssentos);
                printf("Digite a quantidade de ingressos: ");
                scanf("%d", &cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeIngressos);
                puts("-------------------------------------------");

                for (int ig = 0; ig < MAX_INGRESSOS; ig++)
                {
                    cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].id = ig;
                    printf("Digite o preço total do ingresso: ");
                    scanf("%f", &cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco);
                    printf("Digite o preço da meia entrada do ingresso: ");
                    scanf("%f", &cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco_faxetaria);
                    printf("--------------------------------------\n");
                }
            }
            system("cls");
        }
        system("cls");
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
            printf("Filme %d - ID: %d | Nome: %s | Gênero: %s | Dia: %s | Tempo: %s\n", j + 1, cinemas[i].filmesDisponiveis[j].id, cinemas[i].filmesDisponiveis[j].nome, cinemas[i].filmesDisponiveis[j].genero, cinemas[i].filmesDisponiveis[j].data, cinemas[i].filmesDisponiveis[j].time);
            for (int s = 0; s < MAX_SESSOES; s++)
            {
                printf("Sessão %d - ID: %d | Sala: %s  | Hora: %s | Assentos: %d | Ingressos: %d\n", s + 1, cinemas[i].filmesDisponiveis[j].sessions[s].id, cinemas[i].filmesDisponiveis[j].sessions[s].sala, cinemas[i].filmesDisponiveis[j].sessions[s].hora, cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeAssentos, cinemas[i].filmesDisponiveis[j].sessions[s].quantidadeIngressos);
                for (int ig = 0; ig < MAX_INGRESSOS; ig++)
                {
                    printf("Ingresso | Preço: %.2f | Preço da meia: %.2f\n", cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco, cinemas[i].filmesDisponiveis[j].sessions[s].ingressoSession[ig].preco_faxetaria);
                }
            }

            printf("----------------------------------------------------------\n\n");
        }
    }
}

Cliente *createCLientes(cinema *cinema)
{

    int escolhaCinema;
    int escolhaFilme;
    int escolhaSessao;

    Cliente *clientes = malloc(MAX_CLIENTES * sizeof(Cliente));
    if (clientes == NULL)
    {
        fprintf(stderr, "Erro ao alocar o cinemas memória.\n");
        return NULL;
    }

    for (int i = 0; i < MAX_CLIENTES; i++)
    {

        printf("Digite seu nome: ");
        scanf("%s", clientes[i].name);
        printf("Digite sua idade: ");
        scanf("%d", &clientes[i].idade);
        system("cls");
        printf("Bem-vindo %s!\n", clientes[i].name);
        printf("Escolha um dos cinemas para assistir um filme:\n");
        for (int j = 0; j < MAX_CINEMAS; j++)
        {
            printf("%d | %s\n", cinema[j].id, cinema[j].nome);
        }
        printf("para escolher basta digitar o numero respectivo ao lado do cinema: ");
        scanf("%d", &escolhaCinema);
        strcpy(clientes[i].escolha.cinema, cinema[escolhaCinema].nome);
        printf("ecolha abaixo o filme que vc quer assistir\n");
        for (int a = 0; a < MAX_FILMES; a++)
        {
            printf("%d | %s\n", cinema[escolhaCinema].filmesDisponiveis[a].id, cinema[escolhaCinema].filmesDisponiveis[a].nome);
        }
        printf("para escolher basta digitar o numero respectivo ao lado do filme: ");
        scanf("%d", &escolhaFilme);
        strcpy(clientes[i].escolha.filmes, cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].nome);
        strcpy(clientes[i].escolha.dataFilme, cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].data);
        printf("ecolha abaixo o qual sessão do filme vc quer: ");

        for (int s = 0; s < MAX_SESSOES; s++)
        {
            printf("%d - Sala : %s | Horario : %s | Quantidade de assentos disponiveis : %d | quantidade de ingresos : %d\n",
                   cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[s].id,
                   cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[s].sala,
                   cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[s].hora,
                   cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[s].quantidadeAssentos,
                   cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[s].quantidadeIngressos);
        }
        printf("para escolher basta digitar o numero respectivo ao lado da sessao: ");
        scanf("%d", &escolhaSessao);
        strcpy(clientes[i].escolha.sessoes->sala, cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[escolhaSessao].sala);
        strcpy(clientes[i].escolha.sessoes->horario, cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[escolhaSessao].hora);
        printf("ecolha o numero de assento de acordo com o que tem no maximo: ");
        scanf("%d", &clientes[i].escolha.assentos);

        if (clientes[i].idade <= 17)
        {
            clientes[i].escolha.ingressos = cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[escolhaSessao].ingressoSession[0].preco_faxetaria;
        }
        else
        {
            clientes[i].escolha.ingressos = cinema[escolhaCinema].filmesDisponiveis[escolhaFilme].sessions[escolhaSessao].ingressoSession[0].preco;
        }
        system("cls");
    }

    return clientes;
}

void listeningClientes(Cliente *clientes)
{
    printf("\n\nDados dos clientes:\n");
    printf("==========================================================\n");

    for (int i = 0; i < MAX_CLIENTES; i++)
    {
        printf("Cliente %d\n", i + 1);
        printf("Nome: %s\n", clientes[i].name);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Escolha:\n");
        printf("Cinema: %s\n", clientes[i].escolha.cinema);
        printf("Filme: %s\n", clientes[i].escolha.filmes);
        printf("Data do Filme: %s\n", clientes[i].escolha.dataFilme);
        printf("Sessão:\n");
        printf("Sala: %s\n", clientes[i].escolha.sessoes[0].sala);
        printf("Horário: %s\n", clientes[i].escolha.sessoes[0].horario);
        printf("Número do Assento: %d\n", clientes[i].escolha.assentos);
        printf("Preço do Ingresso: %.2f\n", clientes[i].escolha.ingressos);
        printf("----------------------------------------------------------\n");
    }
}

int main(void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    cinema *cinemas = createDataCinemas();
    printCinemaData(cinemas);
    Cliente *cliente = createCLientes(cinemas);
    listeningClientes(cliente);
    free(cinemas);
    return 0;
}
