#include <stdio.h>

int main() {
    int opcao;
    float num1, num2, resultado;
    int resto;

    printf("Calculadora Simples\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Resto da Divisao\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    // Verifica se a op��o � v�lida
    if (opcao < 1 || opcao > 5) {
        printf("Opcao invalida! Tente novamente.\n");
        return 1;
    }

    // Solicita os n�meros ao usu�rio
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    // Realiza a opera��o escolhida
    switch (opcao) {
        case 1: // Adi��o
            resultado = num1 + num2;
            printf("Resultado da adicao: %.2f\n", resultado);
            break;
        case 2: // Subtra��o
            resultado = num1 - num2;
            printf("Resultado da subtracao: %.2f\n", resultado);
            break;
        case 3: // Multiplica��o
            resultado = num1 * num2;
            printf("Resultado da multiplicacao: %.2f\n", resultado);
            break;
        case 4: // Divis�o
            if (num2 == 0) {
                printf("Erro! Divisao por zero nao permitida.\n");
            } else {
                resultado = num1 / num2;
                printf("Resultado da divisao: %.2f\n", resultado);
            }
            break;
        case 5: // Resto da Divis�o
            if ((int)num2 == 0) {
                printf("Erro! Divisao por zero nao permitida.\n");
            } else {
                resto = (int)num1 % (int)num2;
                printf("Resto da divisao: %d\n", resto);
            }
            break;
        default:
            printf("Opcao invalida! Algo deu errado.\n");
            break;
    }

    return 0;
}

