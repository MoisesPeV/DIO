#include <stdio.h>

// Função para converter um número decimal para binário e imprimir
void exibirBinario(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }

    int binario[32];
    int i = 0;

    while (numero > 0) {
        binario[i] = numero % 2;
        numero /= 2;
        i++;
    }

    // Exibe o número binário em ordem inversa
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

// Função principal
int main() {
    int opcao;
    float num1, num2, resultadoDecimal;
    int num1Int, num2Int, resultadoInt;

    printf("Calculadora Avancada\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Resto da Divisao\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    // Verifica se a opção é válida
    if (opcao < 1 || opcao > 5) {
        printf("Opcao invalida! Tente novamente.\n");
        return 1;
    }

    // Solicita os números ao usuário
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    // Converte os números para inteiros, se necessário
    num1Int = (int)num1;
    num2Int = (int)num2;

    // Realiza a operação escolhida
    switch (opcao) {
        case 1: // Adição
            resultadoDecimal = num1 + num2;
            resultadoInt = num1Int + num2Int;
            printf("\nResultado da Adicao:\n");
            break;
        case 2: // Subtração
            resultadoDecimal = num1 - num2;
            resultadoInt = num1Int - num2Int;
            printf("\nResultado da Subtracao:\n");
            break;
        case 3: // Multiplicação
            resultadoDecimal = num1 * num2;
            resultadoInt = num1Int * num2Int;
            printf("\nResultado da Multiplicacao:\n");
            break;
        case 4: // Divisão
            if (num2 == 0) {
                printf("Erro! Divisao por zero nao permitida.\n");
                return 1;
            }
            resultadoDecimal = num1 / num2;
            printf("\nResultado da Divisao:\n");
            printf("Decimal: %.2f\n", resultadoDecimal);
            return 0;
        case 5: // Resto da Divisão
            if (num2Int == 0) {
                printf("Erro! Divisao por zero nao permitida.\n");
                return 1;
            }
            resultadoInt = num1Int % num2Int;
            printf("\nResultado do Resto da Divisao:\n");
            break;
        default:
            printf("Opcao invalida! Algo deu errado.\n");
            return 1;
    }

    // Exibe os resultados em decimal, binário e hexadecimal
    printf("Decimal: %.2f\n", resultadoDecimal);
    printf("Binario: ");
    exibirBinario(resultadoInt);
    printf("\nHexadecimal: %X\n", resultadoInt);

    return 0;
}
