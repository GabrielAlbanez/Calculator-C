#include <stdio.h>
#include <string.h>

// assim que faz para listar os intens de uma matriz
// passa ela com o valor de quanntas colunas tem e o tamanho da array
void listeningItems(float contas[][3], int sizeLengthList)
int i,j
{
    for ( i = 0; i < sizeLengthList; i++)

    {
        printf("indice %d\n",i);
        for ( j = 0; j < 3; j++)
        {
            printf("%.2f ", contas[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    float numero1[50];
    char operador[50][50];
    float numero2[50];
    float Contas[50][3];
    int limit = 0;

    int i = 0;

    while (limit != 2)
    {
        printf("Digite o numero 1: ");
        scanf("%f", &numero1[i]);
        printf("Digite o operador: ");
        scanf("%s", operador[i]);
        printf("Digite o numero 2: ");
        scanf("%f", &numero2[i]);

        Contas[i][0] = numero1[i];
        Contas[i][1] = numero2[i];

        switch (operador[i][0])
        {
        case '+':
            Contas[i][2] = numero1[i] + numero2[i];
            break;
        case '-':
            Contas[i][2] = numero1[i] - numero2[i];
            break;
        case '*':
            Contas[i][2] = numero1[i] * numero2[i];
            break;
        case '%':
            Contas[i][2] = remainder(numero1[i], numero2[i]);
            break;
        case '/':
            if (numero2[i] == 0 || numero1[i] == 0)
            {
                printf("erro: não é possivel realizar uma divisão por 0\n");
                continue;
            }
            Contas[i][2] = numero1[i] / numero2[i];
            break;
        default:
            printf("Operador inválido\n");
            continue;
        }

        printf("Deseja realizar mais operacoes? Digite '1' para continuar ou '2' para ver suas contas: ");
        scanf("%d", &limit);

        i++;
    }

    printf("Minnha calculadora\n");
    printf("\nResultados das operacoes:\n");
    printf("-------------------------------------------------\n");

    for (int l = 0; l < i; l++)
    {
        printf("conta %d\n", l);
        printf("numero 1 : %.2f | operador : %s | numero 2 : %.2f  | total : %.2f  |\n", Contas[l][0], operador[l], Contas[l][1], Contas[l][2]);
        printf("-------------------------------------------------\n");
    }

    // aq a gente passa o valor
    // listeningItems(Contas, i);
    return 0;
}
