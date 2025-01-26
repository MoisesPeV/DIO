#include <stdio.h>

void imprimirDiagnostico(int idade, int concentracaoGlicose, float imc) {
    //TODO: Crie as condi��es necess�rias para a impress�o do diagn�stico.
    if (concentracaoGlicose < 120 && idade < 40) {
        printf("Voc� n�o corre risco de diabetes\n");
    } else if (concentracaoGlicose >= 120 && concentracaoGlicose <= 125 && imc > 27) {
        printf("Voc� tem uma probabilidade de adquirir diabetes. Procure um m�dico\n");
    } else if (concentracaoGlicose >= 126) {
        printf("� altamente recomend�vel que voc� procure um m�dico para avalia��o\n");
    } else if (idade >= 40 && concentracaoGlicose < 120) {
        printf("N�o tem diabetes. IMPORTANTE: cuide da sua sa�de por estar acima dos 40 anos\n");
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
