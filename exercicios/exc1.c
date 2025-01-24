#include <stdio.h>

int main() {
    int i;
    float valor, soma = 0, media;

    printf("Digite 10 valores para calcular a media:\n");

    // Laço de repetição para receber 10 valores
    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valor);
        soma += valor; // Soma os valores
    }

    // Calcula a média
    media = soma / 10;

    // Exibe o resultado
    printf("A media dos valores digitados e: %.2f\n", media);

    return 0;
}