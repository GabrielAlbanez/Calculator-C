#include <stdio.h>
#include <string.h>

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

        printf("Deseja realizar mais operacoes? Digite '1' para continuar ou '2' para ver suas conntas: ");
        scanf("%d", &limit);

        i++;
    }

    printf("\nResultados das operacoes:\n");
    printf("-------------------------------------------------\n");

    for (int l = 0; l < i; l++)
    {
        printf("conta %d\n", l);
        printf("numero 1 : %2f | operador : %s | numero 2 : %2f  | total : %2f  |\n", Contas[l][0], operador[l], Contas[l][1], Contas[l][2]);
        printf("-------------------------------------------------\n");
    }
   

    return 0;
}
