#include <stdio.h>
#include <math.h>

int main(void) {
    int dia_atual, mes_atual, ano_atual;
    int dia_nasc, mes_nasc, ano_nasc;
    int horas_dia, horas_mes, horas_ano, horas_total;

    printf("entre com o dia, mes e ano atual: \n");
    scanf("%d", &dia_atual);
    scanf("%d", &mes_atual);
    scanf("%d", &ano_atual);

    printf("entre com o dia, mes e ano de nascimento: \n");
    scanf("%d", &dia_nasc);
    scanf("%d", &mes_nasc);
    scanf("%d", &ano_nasc);

    horas_dia = abs(dia_atual - dia_nasc) * 24;
    horas_mes = abs(mes_atual - mes_nasc) * 730;
    horas_ano = abs(ano_atual - ano_nasc) * 8760;
    horas_total = horas_dia + horas_mes + horas_ano;

    if (horas_total < 140160) {
        printf("nao eleitor");
    } else if ((horas_total < 157680) || (horas_total > 569400)) {
        printf("eleitor facultativo");
    } else {
        printf("eleitor obrigatorio");
    }


    return 0;
}