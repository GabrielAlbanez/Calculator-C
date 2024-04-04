#include <stdio.h>
#include <string.h>

int main(void) {
  char NomeCliente[50];
  char Produto[50][50];
  int quantidade;
  float valorUnitario[50];
  float Carrinho[50][3];
  float QuantidadePorProduto[50];
 
  printf("digite seu nome - ");
  scanf("%s",NomeCliente);
  printf("Digite a quantidade de produtos que você deseja comprar: ");
  scanf("%d", &quantidade);

  for (int i = 0; i < quantidade; i++) {
    printf("Digite o nome do produto %d: ", i + 1);
    scanf("%s", Produto[i]);
    printf("Digite a quantidade do produto %d: ", i + 1);
    scanf("%f", &QuantidadePorProduto[i]);
    printf("Digite o valor unitario do produto %d: ", i + 1);
    scanf("%f", &valorUnitario[i]);

    Carrinho[i][0] = QuantidadePorProduto[i];
    Carrinho[i][1] = valorUnitario[i];
    Carrinho[i][2] = (QuantidadePorProduto[i] * 10) + valorUnitario[i];
  }
 
  printf("\n -------------------------------carrinho de %s---------------------------:\n",NomeCliente);
  for (int i = 0; i < quantidade; i++) {
    printf(" id - %d | Produto %d: %s | Quantidade: %f |  Valor unitário: %f | Valor "
           "total: %f\n",
           i + 1,i + 1, Produto[i], Carrinho[i][0], Carrinho[i][1], Carrinho[i][2]);
  }

  return 0;
}
