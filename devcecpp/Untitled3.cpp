#include <stdio.h>
#include <math.h>

int main() {
  int largura, comprimento, area, tempo;
  printf("Largura: ");
  scanf("%d", &largura);
  printf("Comprimento: ");
  scanf("%d", &comprimento);
  
  //TODO: Calcular a área do local e o tempo que o robo levará para limpá-lo.
  area = largura * comprimento;
  tempo = area/5;
  if(area%5)
    tempo += 1; 
  //TODO: Imprimir a saída de acordo com o enunciado deste desafio.
  printf("\nO robo de limpeza levara %i minutos para limpar a sala\n", tempo);
  return 0;
}
