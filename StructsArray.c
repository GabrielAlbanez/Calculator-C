#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 50
#include <stdlib.h>

typedef struct DataUser
{
    char nome[50];
    int idade;
    float peso;
} dataUser;

void listIntes(dataUser user[], int lenght)
{
    int i;

    for (i = 0; i < lenght; i++)
    {
        printf("%s\n", user[i].nome);
        printf("Idade: %d\n", user[i].idade);
        printf("Peso: %f\n", user[i].peso);
        printf("---------------------------------------------\n");
    };
}
int main()
{

    dataUser usuarios[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Digite o nome do usuario %d: ", i + 1);
        scanf("%s", usuarios[i].nome);
        fflush(stdin);
        printf("Digite a idade do usuario %d: ", i + 1);
        scanf("%d", &usuarios[i].idade);
        // usa esse fflush para limpar os buffers logo apos de digitar no telacado assim tendo dados mais precisos logo apos do scan ou de função que caputura dados de entrada
        fflush(stdin);
        printf("Digite o peso do usuario %d: ", i + 1);
        scanf("%f", &usuarios[i].peso);
        fflush(stdin);
        system("cls");
    };

    // usamos o puts para ja colocara string e o \n junto
    puts("alunos\n");
    int tamanhoLista = sizeof(usuarios) / sizeof(usuarios[3]);
    listIntes(usuarios, tamanhoLista);

    return 0;
}
