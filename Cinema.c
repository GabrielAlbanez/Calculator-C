
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 50
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char name;
    int idade;
} Cliente;

typedef struct
{
    int id;
    char sala;
    char dia;
    char hora;
    int quantidadeAssentos[50];
} session;

typedef struct
{
    int id;
    char nome;
    char data;
    char time;
    char gênero;
    int idade;
    int quantidadeIngressos;
    session session[50];
} filme;

typedef struct
{

    int id;
    float preco;
    bool preco_faxetaria;
    filme infFime;

} ingresso_session;

typedef struct
{
    int id;
    char nome;
    filme filmesDisponiveis[100]
} cinema;


char createDataClientes(){};

void createDataSession(){};

void createDataFilmes(){};

void createDataIngressos(){};

void createDataCinemas(){};




int main(void)
{

    int i;
    int limit = 1;
    Cliente cliete[100];
    session sessão[100];
    filme filme[100];
    ingresso_session ingresso_session[100];
    cinema cinema[100];

   

    return 0;
}
