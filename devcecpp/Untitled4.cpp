#include <stdio.h>

void imprimirDiagnostico(int idade, int concentracaoGlicose, float imc) {
    //TODO: Crie as condições necessárias para a impressão do diagnóstico.
    if (concentracaoGlicose < 120 && idade < 40) {
        printf("Você não corre risco de diabetes\n");
    } else if (concentracaoGlicose >= 120 && concentracaoGlicose <= 125 && imc > 27) {
        printf("Você tem uma probabilidade de adquirir diabetes. Procure um médico\n");
    } else if (concentracaoGlicose >= 126) {
        printf("É altamente recomendável que você procure um médico para avaliação\n");
    } else if (idade >= 40 && concentracaoGlicose < 120) {
        printf("Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos\n");
    }
}

int main() {
    int idade, concentracaoGlicose;
    float imc;

    scanf("%d", &idade);
    scanf("%d", &concentracaoGlicose);
    scanf("%f", &imc);

    imprimirDiagnostico(idade, concentracaoGlicose, imc);

    return 0;
}
