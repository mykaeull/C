#include <stdio.h>

int main(void) {
    char nome[60];
    int h_trabalhadas, valor_hora, n_filhos;
    float acrescimo, salario;

    printf("entre nome do funcionario: ");
    fgets(nome, 60, stdin);
    printf("horas trabalhadas: ");
    scanf("%d", &h_trabalhadas);
    printf("valor por hora: ");
    scanf("%d", &valor_hora);
    printf("numero de filhos: ");
    scanf("%d", &n_filhos);
    
    if (n_filhos > 3) {
        acrescimo = n_filhos*(0.03*(h_trabalhadas * valor_hora));
        salario = (h_trabalhadas * valor_hora) + acrescimo;
    } else {
        salario = (h_trabalhadas * valor_hora);
    }

    printf("---------------------\n");
    printf("nome: %s", nome);
    printf("salario: %.2f R$\n", salario);
    printf("acrescimo: %.2f porcento", acrescimo);

    return 0;
}