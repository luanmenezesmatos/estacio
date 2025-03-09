#include <stdio.h>

int main()
{
  printf("Movimentos anteriores das peças:\n");
  printf("Cima\n");
  printf("Direita\n");
  printf("Baixo\n");

  printf("\nMovimento do Cavalo:\n");

  int i;
  for (i = 0; i < 2; i++)
  {
    printf("Baixo\n");
  }

  int j = 0;
  while (j < 1)
  {
    printf("Esquerda\n");
    j++;
  }

  return 0;
}